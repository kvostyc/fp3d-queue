#include <AccelStepper.h>

#include "pinout.h"

int POSITION_ONE_E = 1;
int POSITION_TWO_E = 2;
int POSITION_THREE_E = 3;
int POSITION_FOUR_E = 4;

int ARM_MIN_HOME = 5;
int ARM_MAX_HOME = 6;

int LIFT_MIN_HOME = 7;
int LIFT_MAX_HOME = 8;

int STOCK_FORWARD=1;
int STOCK_BACKWARD=8;

int PLATE_BOX_ONE_E=9;
int PLATE_BOX_TWO_E=10;   
int PLATE_BOX_THREE_E=11;    
int PLATE_BOX_FOUR_E=12;     
int PLATE_BOX_FIVE_E=13;     
int PLATE_BOX_SIX_E=14;      
int PLATE_BOX_SEVEN_E=15;    
int PLATE_BOX_EIGHT_E=16;

int LIFT_UP=17;

long lastStockStep;
long initial_stock_homing = -1;
long initial_stock_homing_up = 1;

long lastLiftStep;
long initial_homing = -1;
long initial_homing_up = 1;

long initial_platform = -1;

int receivedPrinterID;
int receivedEventID;

AccelStepper arm(1, X_STEP_PIN, X_DIR_PIN);

AccelStepper lift(1, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper platform(1, Z_STEP_PIN, Z_DIR_PIN);

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

  pinMode(X_MIN_PIN, INPUT_PULLUP);
  pinMode(X_MAX_PIN, INPUT_PULLUP);

  pinMode(Y_MIN_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);

  pinMode(POSITION_ONE, INPUT_PULLUP);
  pinMode(POSITION_TWO, INPUT_PULLUP);
  pinMode(POSITION_THREE, INPUT_PULLUP);
  pinMode(POSITION_FOUR, INPUT_PULLUP);

  pinMode(PLATE_BOX_ONE, INPUT_PULLUP);
  pinMode(PLATE_BOX_TWO, INPUT_PULLUP);
  pinMode(PLATE_BOX_THREE, INPUT_PULLUP);
  pinMode(PLATE_BOX_FOUR, INPUT_PULLUP);
  pinMode(PLATE_BOX_FIVE, INPUT_PULLUP);
  pinMode(PLATE_BOX_SIX, INPUT_PULLUP);
  pinMode(PLATE_BOX_SEVEN, INPUT_PULLUP);
  pinMode(PLATE_BOX_EIGHT, INPUT_PULLUP);
  
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);
  digitalWrite(E_ENABLE_PIN    , LOW);
  digitalWrite(Q_ENABLE_PIN    , LOW);

  arm.setMaxSpeed(20000);
  arm.setAcceleration(2000);
  arm.setCurrentPosition(0);
  
  lift.setMaxSpeed(5000);
  lift.setAcceleration(200);
  lift.setCurrentPosition(0);

  platform.setMaxSpeed(20000);
  platform.setAcceleration(5000);
  platform.setCurrentPosition(0);
}


void loop() {
  //platform.runToNewPosition(-380000);
  
  if (Serial.available() > 0) {
    receivedPrinterID = Serial.parseInt(); 
    receivedEventID = Serial.parseInt();

    if (receivedPrinterID == 1 && receivedEventID == ARM_MIN_HOME) 
    {
      arm.setCurrentPosition(0);
      Serial.println("Akcia pro printerID 1 a eventID 5 bola vykonaná.");
      while (digitalRead(Y_MIN_PIN)) 
      {
          arm.moveTo(initial_stock_homing);
          arm.runSpeed();  
          initial_stock_homing--;
      }
    } 
    else if (receivedPrinterID == 1 && receivedEventID == ARM_MAX_HOME) 
    {
      Serial.println("Akcia pro printerID 1 a eventID 6 bola vykonaná.");
      while (digitalRead(Y_MAX_PIN)) 
      {
          arm.moveTo(initial_stock_homing_up);
          arm.runSpeed();  
          initial_stock_homing_up++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == LIFT_MIN_HOME) 
    {
      Serial.println("Akcia pro printerID 1 a eventID 6 bola vykonaná.");
      while (digitalRead(X_MIN_PIN)) 
      {
          lift.moveTo(initial_homing_up);
          lift.runSpeed();  
          initial_homing_up++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == LIFT_MAX_HOME) 
    {
      arm.setCurrentPosition(0);
      Serial.println("Akcia pro printerID 1 a eventID 6 bola vykonaná.");
      while (digitalRead(X_MAX_PIN)) 
      {
          lift.moveTo(initial_homing);
          lift.runSpeed();  
          initial_homing--;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == POSITION_ONE_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlatform();
      while (digitalRead(POSITION_ONE)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == POSITION_TWO_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlatform();
      while (digitalRead(POSITION_TWO)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == POSITION_THREE_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlatform();
      while (digitalRead(POSITION_THREE)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == POSITION_FOUR_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(POSITION_FOUR)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_ONE_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_TWO_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_TWO)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_THREE_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_THREE)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_FOUR_E) 
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_FOUR)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_FIVE_E)
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_FIVE)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_SIX_E)
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_SIX)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_SEVEN_E)
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_SEVEN)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == PLATE_BOX_EIGHT_E)
    {  
      Serial.println("Akcia pro printerID 1 a eventID 1 bola vykonaná.");
      homePlate();
      while (digitalRead(PLATE_BOX_EIGHT)) 
      {
        platform.moveTo(initial_platform);
        platform.runSpeed();  
        initial_platform++;
      }
    }
    else if (receivedPrinterID == 1 && receivedEventID == LIFT_UP)
    {  
      Serial.println("Akcia pro printerID 1 a eventID 17 bola vykonaná.");
      lift.setMaxSpeed(500);
      lift.setAcceleration(500);
      
      long initial_lift = 0;
    
      lift.stop();
    
      while (lift.isRunning()) {
        delay(1);
      }
    
      while (initial_lift >= -80000) 
      {
        lift.moveTo(initial_lift);
        lift.runSpeed();  
        initial_lift--;
      }
    }
    Serial.flush();
  }
}


void homePlatform()
{
  platform.setMaxSpeed(50000);
  platform.setAcceleration(5000);
  initial_platform = platform.currentPosition();

  platform.stop();

  while (platform.isRunning()) {
    delay(1);
  }

  while (digitalRead(POSITION_FOUR)) 
  {
    platform.moveTo(initial_platform);
    platform.runSpeed();  
    initial_platform--;
  }
}

void homePlate()
{
  platform.setMaxSpeed(50000);
  platform.setAcceleration(5000);
  initial_platform = platform.currentPosition();

  platform.stop();

  while (platform.isRunning()) {
    delay(1);
  }

  while (digitalRead(PLATE_BOX_ONE)) 
  {
    platform.moveTo(initial_platform);
    platform.runSpeed();  
    initial_platform--;
  }
}
