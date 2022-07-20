#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define LED_ADDRESS2 0x3c
#define LED_ADDRESS1 0x3d

SSD1306AsciiWire oled1;
SSD1306AsciiWire oled2;

int fader1 = A3;
int fader2 = A2;
int val = 0;
int yeet = 0;
int oldYeet;
int oldVal;
int time1,time2;
bool x = 0;

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  analogReference(DEFAULT);
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT); 

  oled1.begin(&Adafruit128x64, LED_ADDRESS1);
  oled2.begin(&Adafruit128x64, LED_ADDRESS2);

  oled1.setFont(Adafruit5x7);
  oled1.clear();
  oled1.set2X();
  oled2.setFont(Adafruit5x7);
  oled2.clear();
  oled2.set2X();
  }

void loop() {
  delay(10);
  val = analogRead(fader1);  // read the input pin
  oled1.setCursor(0,0);
  oled1.println("1");
  val = val/10;
  if(val>100){
    val = 100;
  }
  if(abs(val-oldVal)>1){
    time1=20;
  }
  if (time1!=0){
    time1--;    
  }
  if(abs(val-oldVal)<2 && time1 == 0){
    val = oldVal;
  }
  oldVal=val;
  if(val<10){oled1.print("0");}
  if(val<100){oled1.print("0");}
  oled1.println(val);
  oled1.println(time1);
  delay(10);
  
  yeet = analogRead(fader2);  // read the input pin
  oled2.setCursor(0,0);
  oled2.println("2");
  yeet = yeet/10;
  if (yeet>100){
    yeet=100;
  }
  if(abs(yeet-oldYeet)>1){
    time2=20;
  }
  if (time2!=0){
    time2--;    
  }
  if(abs(yeet-oldYeet)<2 && time2 == 0){
    yeet = oldYeet;
  }
  oldYeet=yeet;
  if(yeet<10){oled2.print("0");}
  if(yeet<100){oled2.print("0");}
  oled2.println(yeet);
  oled2.println(time2);
  Serial.println(val);
  Serial.print(",");
  Serial.println(yeet);
    Serial.print(",");
}