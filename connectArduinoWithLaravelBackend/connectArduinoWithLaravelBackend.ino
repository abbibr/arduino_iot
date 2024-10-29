// Connect Arduino project to backend (Laravel) using Arduino wifi mkr 1010 esp32

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your_SSID"; // Replace with your Wi-Fi SSID
const char* password = "your_PASSWORD"; // Replace with your Wi-Fi password
const char* serverName = "http://your_laravel_backend/api/sensor-value"; // Replace with your Laravel API URL

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    int potValue = analogRead(34); // Read the potentiometer value (0-4095)
    float voltage = potValue * (3.3 / 4095); // Convert to voltage (0-3.3V)

    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverName);
        http.addHeader("Content-Type", "application/json");

        String httpRequestData = "{\"value\":" + String(voltage) + "}";
        int httpResponseCode = http.POST(httpRequestData);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
        } else {
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    }
    delay(5000); // Send data every 5 seconds
}
