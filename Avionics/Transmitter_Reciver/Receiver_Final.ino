#include <VirtualWire.h>

void setup() {
  // Initialize VirtualWire library
  vw_setup(2000); // Bits per second
  vw_set_rx_pin(11); // Receiver pin
  vw_rx_start(); // Start the receiver
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) { // If a message is received
    Serial.print(": ");
    for (int i = 0; i < buflen; i++) {
      Serial.print(char(buf[i])); // Print each character of the message
    }
    Serial.println(); // Print a newline character
  }
}
