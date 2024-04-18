const int ledPin = 13;   // Pin connected to the LED
const int ldrPin = A0;   // Analog pin connected to the LDR

boolean ledState = false; // Store the LED state
unsigned long pulseStartTime = 0;
const unsigned long pulseDuration = 100; // 3 seconds in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Turn off the LED
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the command from the Serial Monitor
    
    if (command == '1') {
      pulseStartTime = millis(); // Record the start time of the pulse
      ledState = true;
    }
  }

  // Check if the pulse duration has elapsed
  if (ledState && (millis() - pulseStartTime >= pulseDuration)) {
    ledState = false; // Turn off the LED after the pulse duration
  }

  // Turn the LED on or off based on the state
  digitalWrite(ledPin, ledState ? HIGH : LOW);

  // Read the LDR value and print it to the serial monitor
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  delay(500); // Add a short delay to avoid rapidly repeating values
}
