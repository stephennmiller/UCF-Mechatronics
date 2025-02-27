/*  Created by Stephen Miller on 2/22/21.
 *  Copyright © 2020 Stephen Miller. All rights reserved.
 *  Updated: 2/25/25 for UCF-Mechatronics GitHub repo.
 *  Description: Controls a servo angle with joystick X-axis, LED brightness with Y-axis,
 *  and buzzer with switch press. Outputs key data to Serial Monitor in volts.
 */

#include <Servo.h>

Servo myServo;

// Pin definitions
#define LED_PIN 11      // LED on PWM pin for brightness control
#define BUZZER_PIN 6    // Buzzer pin
#define JOY_X A0        // Joystick X-axis input
#define JOY_Y A1        // Joystick Y-axis input
#define JOY_SW 2        // Joystick switch input
#define SERVO_PIN 9     // Servo motor pin

// Constants
#define SERVO_SCALE (180.0 / 1023.0)  // Convert X-axis (0-1023) to servo angle (0-180)
#define LED_SCALE (255.0 / 1023.0)    // Convert Y-axis (0-1023) to PWM (0-255)
#define BUZZER_FREQ 100               // Buzzer tone frequency (Hz)
#define BIT_TO_VOLT (5.0 / 1023.0)   // Convert analog read (0-1023) to volts (0-5V)
#define DELAY_MS 200                  // Loop delay in milliseconds

// Variables
int xPosition;    // Raw X-axis joystick value
int yPosition;    // Raw Y-axis joystick value
int switchState;  // Joystick switch state (0 = pressed, 1 = not pressed)
int servoAngle;   // Calculated servo angle
int ledBrightness; // Calculated LED brightness

void setup() {
  Serial.begin(9600);           // Start serial communication
  pinMode(JOY_X, INPUT);        // X-axis as input
  pinMode(JOY_Y, INPUT);        // Y-axis as input
  pinMode(JOY_SW, INPUT_PULLUP); // Switch with internal pull-up
  pinMode(LED_PIN, OUTPUT);     // LED as output
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer as output
  myServo.attach(SERVO_PIN);     // Attach servo to its pin
}

void loop() {
  // Read joystick inputs
  xPosition = analogRead(JOY_X);      // X-axis position (0-1023)
  yPosition = analogRead(JOY_Y);      // Y-axis position (0-1023)
  switchState = digitalRead(JOY_SW);  // Switch state (0 or 1)

  // Calculate outputs
  servoAngle = xPosition * SERVO_SCALE;     // Scale X for servo angle
  ledBrightness = yPosition * LED_SCALE;    // Scale Y for LED brightness

  // Apply outputs
  myServo.write(servoAngle);         // Set servo position
  analogWrite(LED_PIN, ledBrightness); // Set LED brightness
  switchState == 0 ? tone(BUZZER_PIN, BUZZER_FREQ) : noTone(BUZZER_PIN); // Buzzer on/off

  // Convert to volts for serial output
  float xVolt = xPosition * BIT_TO_VOLT;
  float servoVolt = servoAngle * BIT_TO_VOLT;

  // Print data to Serial Monitor
  Serial.print("X Volt: "); Serial.print(xVolt);
  Serial.print(" | Servo Volt: "); Serial.println(servoVolt);

  delay(DELAY_MS);  // Pause before next loop
}
