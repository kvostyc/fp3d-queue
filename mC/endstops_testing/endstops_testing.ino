#include "pinout.h"

void setup()
{
  Serial.begin(9600);

  pinMode(PLATE_BOX_ONE, INPUT_PULLUP);
  pinMode(PLATE_BOX_TWO, INPUT_PULLUP);
  pinMode(PLATE_BOX_THREE, INPUT_PULLUP);
  pinMode(PLATE_BOX_FOUR, INPUT_PULLUP);
  pinMode(PLATE_BOX_FIVE, INPUT_PULLUP);
  pinMode(PLATE_BOX_SIX, INPUT_PULLUP);
  pinMode(PLATE_BOX_SEVEN, INPUT_PULLUP);
  pinMode(PLATE_BOX_EIGHT, INPUT_PULLUP);
}

void loop() {
  // Čítanie stavov pinov a výpis cez sériový monitor
  int one = digitalRead(PLATE_BOX_ONE);
  int two = digitalRead(PLATE_BOX_TWO);
  int three = digitalRead(PLATE_BOX_THREE);
  int four = digitalRead(PLATE_BOX_FOUR);
  int five = digitalRead(PLATE_BOX_FIVE);
  int six = digitalRead(PLATE_BOX_SIX);
  int seven = digitalRead(PLATE_BOX_SEVEN);
  int eight = digitalRead(PLATE_BOX_EIGHT);
  
  Serial.print("one: ");
  Serial.println(one);
  Serial.print("two: ");
  Serial.println(two);
  Serial.print("three: ");
  Serial.println(three);
  Serial.print("four: ");
  Serial.println(four);
  Serial.print("five: ");
  Serial.println(five);
  Serial.print("six: ");
  Serial.println(six);
  Serial.print("seven: ");
  Serial.println(seven);
  Serial.print("eight: ");
  Serial.println(eight);
  
  delay(1000); // oneskorenie 1 sekundu
}



/**
 * X MAX = RAMENO UPLNE VZADU
 * X MIN = UPLNE HORE
 * Y MIN = PRVA POZICIA
 * Y MAX´= DRUHA POZICIA
 * Z MIN = TRETIA POZICIA
 * Z MAX = STVRTA POZICIA
 */
