#include <Servo.h>

// --- Servo Setup ---
Servo servos[6];
int servoPins[6] = {8, 9, 10, 11, 12, 13};
int servoAngle[6] = {90, 150, 45, 90, 90, 90};  // Start all servos at 90°

int currentServo = 0;

// --- Encoder and Buttons ---
int encoderCLK = 2;
int encoderDT = 3;
int encoderSW = 4;  // Reset button on encoder

int btnNext = 5;     // Next servo
int btnPrev = 6;     // Previous servo
int btnAdjust = 7;   // Angle change mode toggle

int lastStateCLK;
int currentStateCLK;
bool adjustMode = false;   // Toggle angle change mode
bool encoderPressed = false;

// --- Rotation Control Variables ---
int angleStep = 5;   // degrees added per encoder step
int speed = 5;       // dynamic step value (resettable)
bool clkLastState = LOW;

// --- Debounce Helpers ---
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200; // milliseconds

void setup() {
  Serial.begin(9600);

  // Attach servos
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(servoAngle[i]);
  }

  // Pin modes
  pinMode(encoderCLK, INPUT);
  pinMode(encoderDT, INPUT);
  pinMode(encoderSW, INPUT_PULLUP);
  pinMode(btnNext, INPUT_PULLUP);
  pinMode(btnPrev, INPUT_PULLUP);
  pinMode(btnAdjust, INPUT_PULLUP);

  lastStateCLK = digitalRead(encoderCLK);

  Serial.println("===== 6DOF Robotic Arm Control Initialized =====");
  Serial.println("Use rotary encoder to move servos.");
  Serial.println("Button 5=Next Servo, Button 6=Previous, Button 7=Toggle Adjust Mode");
  Serial.println("Encoder Push = Reset speed.");
  Serial.println("===============================================");
}

void loop() {
  // --- Read Encoder Rotation ---
  currentStateCLK = digitalRead(encoderCLK);
  if (currentStateCLK != lastStateCLK && currentStateCLK == HIGH) {
    if (digitalRead(encoderDT) != currentStateCLK) {
      servoAngle[currentServo] += speed;  // Clockwise rotation
    } else {
      servoAngle[currentServo] -= speed;  // Counterclockwise rotation
    }

    servoAngle[currentServo] = constrain(servoAngle[currentServo], 0, 180);
    if (adjustMode) servos[currentServo].write(servoAngle[currentServo]);

    Serial.print("Servo ");
    Serial.print(currentServo + 1);
    Serial.print(" Angle: ");
    Serial.println(servoAngle[currentServo]);
  }
  lastStateCLK = currentStateCLK;

  // --- Button: Next Servo ---
  if (buttonPressed(btnNext)) {
    currentServo = (currentServo + 1) % 6;
    Serial.print("Switched to Servo: ");
    Serial.println(currentServo + 1);
  }

  // --- Button: Previous Servo ---
  if (buttonPressed(btnPrev)) {
    currentServo = (currentServo - 1 + 6) % 6;
    Serial.print("Switched to Servo: ");
    Serial.println(currentServo + 1);
  }

  // --- Button: Toggle Adjust Mode ---
  if (buttonPressed(btnAdjust)) {
    adjustMode = !adjustMode;
    Serial.print("Adjust Mode: ");
    Serial.println(adjustMode ? "ON (Servo follows encoder)" : "OFF");
  }

  // --- Encoder Button: Reset speed only ---
  if (digitalRead(encoderSW) == LOW && !encoderPressed) {
    encoderPressed = true;
    speed = 5;
    Serial.println("Encoder speed reset to default (5° per step)");
  }
  if (digitalRead(encoderSW) == HIGH) {
    encoderPressed = false;
  }

  delay(10);
}

// --- Function: Button Debounce ---
bool buttonPressed(int pin) {
  if (digitalRead(pin) == LOW && (millis() - lastDebounceTime > debounceDelay)) {
    lastDebounceTime = millis();
    return true;
  }
  return false;
}

