#include <AccelStepper.h>

#include "pinout.h"

int receivedPrinterID;
int receivedEventID;

AccelStepper stock(1, X_STEP_PIN, X_DIR_PIN);

AccelStepper lift(1, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper ladle(1, Z_STEP_PIN, Z_DIR_PIN);

void setup() 
{
  Serial.begin(115200);
   
  pinMode(FAN_PIN , OUTPUT);
  pinMode(HEATER_0_PIN , OUTPUT);
  pinMode(HEATER_1_PIN , OUTPUT);
  pinMode(LED_PIN  , OUTPUT);
  
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);
  
  pinMode(E_STEP_PIN  , OUTPUT);
  pinMode(E_DIR_PIN    , OUTPUT);
  pinMode(E_ENABLE_PIN    , OUTPUT);
  
  pinMode(Q_STEP_PIN  , OUTPUT);
  pinMode(Q_DIR_PIN    , OUTPUT);
  pinMode(Q_ENABLE_PIN    , OUTPUT);
  
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);
  digitalWrite(E_ENABLE_PIN    , LOW);
  digitalWrite(Q_ENABLE_PIN    , LOW);

  stock.setMaxSpeed(50000);
  stock.setAcceleration(10000);
  
  lift.setMaxSpeed(50000);
  lift.setAcceleration(20000);
}


void loop() {
  if (Serial.available() > 0) {
    receivedPrinterID = Serial.parseInt(); 
    receivedEventID = Serial.parseInt();
    
    if (receivedPrinterID == 1 && receivedEventID == 1) {
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      stock.runToNewPosition(10000);
    } else if (receivedPrinterID == 2 && receivedEventID == 2) {
      Serial.println("Akce pro printerID 1 a eventID 1 bola vykonaná.");
      lift.runToNewPosition(5000);
    }
    Serial.flush();
  }
}
