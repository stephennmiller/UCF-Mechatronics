/*  Created by Stephen Miller on 2/23/21.
 *  Copyright © 2020 Stephen Miller. All rights reserved.
 *  Updated: 2/25/25 for UCF-Mechatronics GitHub repo.
 *  Description: Extra Lab 3 code. Turns an LED on when a photoresistor detects low light
 *  (<150 analog value), otherwise keeps it off. Outputs reading to Serial Monitor.
 */

// Pin definitions
#define LED_PIN 7     // LED output pin
#define PHOTO_PIN A0  // Photoresistor input pin

// Constants
#define LIGHT_THRESHOLD 150  // Threshold for turning LED on (0-1023 range)
#define DELAY_MS 250         // Delay between readings in milliseconds

// Variables
int lightValue;  // Raw photoresistor reading

void setup() {
  Serial.begin(9600);         // Start serial communication at 9600 baud
  pinMode(LED_PIN, OUTPUT);   // Set LED pin as output
  pinMode(PHOTO_PIN, INPUT);  // Set photoresistor pin as input
}

void loop() {
  // Read photoresistor value (0-1023)
  lightValue = analogRead(PHOTO_PIN);

  // Turn LED on if light level is below threshold, off otherwise
  if (lightValue < LIGHT_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // LED on in low light
  } else {
    digitalWrite(LED_PIN, LOW);   // LED off in bright light
  }

  // Print light value to Serial Monitor
  Serial.print("Light Level: ");
  Serial.println(lightValue);

  delay(DELAY_MS);  // Wait before next reading
}
