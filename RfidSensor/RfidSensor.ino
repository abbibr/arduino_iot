#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// In000000000000000it SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  int cardAmity[] = {0xBB, 0xD0, 0xB2, 0x7D};
  if(mfrc522.uid.uidByte[0] == cardAmity[0] && mfrc522.uid.uidByte[1] == cardAmity[1] && mfrc522.uid.uidByte[2] == cardAmity[2] && mfrc522.uid.uidByte[3] == cardAmity[3]) {
    Serial.println("Welcome Mr.Ibrohim Abbosov");
  }
  else {
    Serial.println("You don`t have access to enter our university!");
  }

  mfrc522.PICC_HaltA();
}
