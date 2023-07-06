#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <SoftwareSerial.h>

#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define TxD 2//connect RXD of Bluetooth to D2 pin
#define RxD 3 //connect TXD of Bluetooth to D3 pin
SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

int F1 = A0; //Thumb 
int F2 = A1; //Index
int F3 = A2;// middle
int F4 = A3;// Ring
int F5 = A6;// little

int count = 50;// for average values

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  mySerial.begin(9600); // For Bluetooth 
  display.begin(i2c_Address, true); // Address 0x3C default
  display.display();
  delay(500);
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Smart Glove: Sign Language Detection");
  display.display();
  delay(2000);
  display.clearDisplay();
  mySerial.println("Smart Glove: Sign Language Detection"); 
  pinMode(F1, INPUT);
  pinMode(F2, INPUT);
  pinMode(F3, INPUT);
  pinMode(F4, INPUT);
  pinMode(F5, INPUT);
}

void loop() {

unsigned int raw1=0;
unsigned int raw2=0;
unsigned int raw3=0;
unsigned int raw4=0;
unsigned int raw5=0;

for (int i=0; i< count; i++)
{
  // read the value from the Flex sensor:
  raw1 += analogRead(F1);
  raw2 += analogRead(F2);
  raw3 += analogRead(F3);
  raw4 += analogRead(F4);
  raw5 += analogRead(F5);
  delay(50);
}
//Calculate avg value of each flex sensor
raw1 = raw1 / count;
raw2 = raw2 / count;
raw3 = raw3 / count;
raw4 = raw4 / count;
raw5 = raw5 / count;
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20, 10);

  //"0" 240  264 264 230 219
  if((raw1>=530 && raw1<=560) && (raw2>=620 && raw2<=680) && (raw3>=640 && raw3<=675) && (raw4>=690 && raw4<=760) &&(raw5>=600 && raw5<=680)){
  Serial.print("A");
  display.println("A");
  display.display();
  mySerial.println("A");}
  //"1" 247  270 265 232 225
  if((raw1>=570 && raw1<=630) && (raw2>=525 && raw2<=590) && (raw3>=545 && raw3<=625) && (raw4>=570 && raw4<=610) &&(raw5>=450 && raw5<=560)){
  Serial.print("B");
  display.println("B");
  display.display();
  mySerial.println("B");}
  //"2" 249  270 270 230 220
  if((raw1>=554 && raw1<=570) && (raw2>=578 && raw2<=630) && (raw3>=585 && raw3<=648) && (raw4>=646 && raw4<=692) &&(raw5>=420 && raw5<=584)){
  Serial.print("C");
  display.println("C");
  display.display();
  mySerial.println("C");}
  //"3" 251  271 271 231 219
  if((raw1>=570 && raw1<=620) && (raw2>=550 && raw2<=640) && (raw3>=623 && raw3<=700) && (raw4>=710 && raw4<=765) &&(raw5>=590 && raw5<=630)){
  Serial.print("D");
  display.println("D");
  display.display();
  mySerial.println("D");}
  //"4" 245  270 271 235 225
  if((raw1>=560 && raw1<=689) && (raw2>= 565 && raw2<=690) && (raw3>=635 && raw3<=684) && (raw4>=690 && raw4<=750) &&(raw5>=515 && raw5<=670)){
  Serial.print("E");
  display.println("E");
  display.display();
  mySerial.println("E");}
  //"5" 250  270 272 238 228
  if((raw1>=568 && raw1<=610) && (raw2>=617 && raw2<=690) && (raw3>=545 && raw3<=570) && (raw4>=565 && raw4<=600) &&(raw5>=470 && raw5<=560)){
  Serial.print("F");
  display.println("F");
  display.display();
  mySerial.println("F");}
  //"6" 249  271 271 235 209
  if((raw1>=535 && raw1<=565) && (raw2>=546 && raw2<=578) && (raw3>=635 && raw3<=697) && (raw4>=690 && raw4<=753) &&(raw5>=600 && raw5<=646)){
  Serial.print("G");
  display.println("G");
  display.display();
  mySerial.println("G");}
  //"7" 247  270 271 227 221
  if((raw1>=565 && raw1<=580) && (raw2>=553 && raw2<=575) && (raw3>=539 && raw3<=578) && (raw4>=715 && raw4<=750) &&(raw5>=585 && raw5<=623)){
  Serial.print("H");
  display.println("H");
  display.display();
  mySerial.println("H");}
  //"8" 245  271 261 234 222
  if((raw1>=576 && raw1<=638) && (raw2>=585 && raw2<=665) && (raw3>=605 && raw3<=685) && (raw4>=685 && raw4<=730) &&(raw5>=530 && raw5<=569)){
  Serial.print("I");
  display.println("I");
  display.display();
  mySerial.println("I");}
  //"9" 243  257 267 233 222
  if((raw1>=547 && raw1<=559) && (raw2>=648 && raw2<=659) && (raw3>=631 && raw3<=642) && (raw4>=703 && raw4<=718) &&(raw5>=541 && raw5<=557)){
  Serial.print("J");
  display.println("J");
  display.display();
  mySerial.println("J");}
  //"@" 255  275 274 239 228
  if((raw1>=544 && raw1<=574) && (raw2>=542 &&raw2<=575) && (raw3>=540 && raw3<=589) && (raw4>=650 && raw4<=715) &&(raw5>=575 && raw5<=610)){
  Serial.print("K");
  display.println("K");
  display.display();
  mySerial.println("K"); }
  if((raw1>=541 && raw1<=568) && (raw2>=553 &&raw2<=592) && (raw3>=600 && raw3<=694) && (raw4>=646 && raw4<=750) &&(raw5>=520 && raw5<=622)){
  Serial.print("L");
  display.println("L");
  display.display();
  mySerial.println("L"); }
  if((raw1>=579 && raw1<=620) && (raw2>=610 &&raw2<=652) && (raw3>=605 && raw3<=649) && (raw4>=697 && raw4<=738) &&(raw5>=590 && raw5<=675)){
  Serial.print("M");
  display.println("M");
  display.display();
  mySerial.println("M"); }
  if((raw1>=555 && raw1<=584) && (raw2>=600 &&raw2<=625) && (raw3>=607 && raw3<=632) && (raw4>=660 && raw4<=700) &&(raw5>=580 && raw5<=625)){
  Serial.print("N");
  display.println("N");
  display.display();
  mySerial.println("N"); }
  if((raw1>=570 && raw1<=620) && (raw2>=590 &&raw2<=648) && (raw3>=592 && raw3<=639) && (raw4>=625 && raw4<=720) &&(raw5>=500 && raw5<=600)){
  Serial.print("O");
  display.println("O");
  display.display();
  mySerial.println("O"); }
  if((raw1>=547 && raw1<=553) && (raw2>=562 &&raw2<=582) && (raw3>=562 && raw3<=570) && (raw4>=651 && raw4<=683) &&(raw5>=598 && raw5<=616)){
  Serial.print("P");
  display.println("P");
  display.display();
  mySerial.println("P"); }
  if((raw1>=540 && raw1<=570) && (raw2>=558 &&raw2<=600) && (raw3>=633 && raw3<=674) && (raw4>=690 && raw4<=745) &&(raw5>=575 && raw5<=638)){
  Serial.print("Q");
  display.println("Q");
  display.display();
  mySerial.println("Q"); }
  if((raw1>=579 && raw1<=625) && (raw2>=548 &&raw2<=580) && (raw3>=615 && raw3<=633) && (raw4>=725 && raw4<=791) &&(raw5>=658 && raw5<=750)){
  Serial.print("R");
  display.println("R");
  display.display();
  mySerial.println("R"); }
  if((raw1>=550 && raw1<=615) && (raw2>=623 &&raw2<=689) && (raw3>=615 && raw3<=688) && (raw4>=670 && raw4<=775) &&(raw5>=610 && raw5<=670)){
  Serial.print("S");
  display.println("S");
  display.display();
  mySerial.println("S"); }
  if((raw1>=528 && raw1<=612) && (raw2>=580 &&raw2<=651) && (raw3>=600 && raw3<=678) && (raw4>=646 && raw4<=720) &&(raw5>=576 && raw5<=639)){
  Serial.print("T");
  display.println("T");
  display.display();
  mySerial.println("T"); }
  if((raw1>=567 && raw1<=618) && (raw2>=528 &&raw2<=596) && (raw3>=527 && raw3<=585) && (raw4>=695 && raw4<=779) &&(raw5>=546 && raw5<=600)){
  Serial.print("U");
  display.println("U");
  display.display();
  mySerial.println("U"); }
  if((raw1>=545 && raw1<=602) && (raw2>=535 &&raw2<=595) && (raw3>=527 && raw3<=589) && (raw4>=697 && raw4<=783) &&(raw5>=632 && raw5<=725)){
  Serial.print("V");
  display.println("V");
  display.display();
  mySerial.println("V"); }
  if((raw1>=546 && raw1<=593) && (raw2>=538 &&raw2<=584) && (raw3>=534 && raw3<=587) && (raw4>=559 && raw4<=610) &&(raw5>=625 && raw5<=692)){
  Serial.print("W");
  display.println("W");
  display.display();
  mySerial.println("W"); }
  if((raw1>=547 && raw1<=605) && (raw2>=609 &&raw2<=684) && (raw3>=617 && raw3<=683) && (raw4>=670 && raw4<=731) &&(raw5>=575 && raw5<=615)){
  Serial.print("X");
  display.println("X");
  display.display();
  mySerial.println("X"); }
  if((raw1>=530 && raw1<=660) && (raw2>=618 &&raw2<=686) && (raw3>=609 && raw3<=680) && (raw4>=643 && raw4<=730) &&(raw5>=455 && raw5<=615)){
  Serial.print("Y");
  display.println("Y");
  display.display();
  mySerial.println("Y"); }
  if((raw1>=538 && raw1<=594) && (raw2>=544 &&raw2<=603) && (raw3>=642 && raw3<=710) && (raw4>=710 && raw4<=774) &&(raw5>=600 && raw5<=648)){
  Serial.print("Z");
  display.println("Z");
  display.display();
  mySerial.println("Z"); } 
  else{
  mySerial.println("No gesture recognized"); }   

  display.display();

  Serial.print(raw1);Serial.print("\t");
  Serial.print(raw2);Serial.print("\t");
  Serial.print(raw3);Serial.print("\t");
  Serial.print(raw4);Serial.print("\t");
  Serial.println(raw5);
  delay(100);
}
