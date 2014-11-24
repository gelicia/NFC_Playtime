  #include <Wire.h>
  #include <PN532_I2C.h>
  #include <PN532.h>

  PN532_I2C pn532i2c(Wire);
  PN532 nfc(pn532i2c);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");
  Bean.setLed(255, 0, 0);
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  //nfc.setPassiveActivationRetries(0xFF);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
    
  Serial.println("Waiting for an ISO14443A card");
}

void loop(void) {
  boolean success;
  boolean valid = false;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t myuid[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  uint8_t uidLength;
  
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if (success) {
    Serial.println("Found a card!");
    Serial.print("UID Value: ");
    valid = true; 
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(" 0x");Serial.print(uid[i], HEX); 
      
      if (uid[i] != myuid[i]){
        valid = false;
      }
    }
    
    if (valid){
      Bean.setLed(0,255,0);
    }
    else {
      Bean.setLed(0,0,255);
    }
    // Wait 1 second before continuing
    delay(1000);
  }
  else
  {
    Serial.println("not successful");
    Bean.setLed(255, 0, 0);
    valid = false;
  }
}
