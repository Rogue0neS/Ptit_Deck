#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <HID-Project.h>

#define PIN 15        
#define NUM_LEDS 5  

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C

#define lumo 0

#define red1 1
#define green1 2
#define blue1 3

#define red2 4
#define green2 5
#define blue2 6

#define red3 7
#define green3 8
#define blue3 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int As1 =  4;
int Bs1 =  5;

int As2 =  6;
int Bs2 =  7;

int As3 =  8;
int Bs3 =  9;

int b1 = 10;
int b2 = 16;
int b3 = 14;

int An1 = 500; 
int An2 = 500; 
int An3 = 500;

int mode = 0;
int mled = 1;

int r1 = 125;
int g1 = 125;
int bl1 = 125;

int r2 = 255;
int g2 = 255;
int bl2 = 255;

int r3 = 255;
int g3 = 255;
int bl3 = 255;

int lum = 0;
int lumu = 0;

int Ana[3];

int analogSliderValues[3];


void setup() {
pinMode(As1,INPUT_PULLUP);
pinMode(Bs1,INPUT_PULLUP);

pinMode(As2,INPUT_PULLUP);
pinMode(Bs2,INPUT_PULLUP);

pinMode(As3,INPUT_PULLUP);
pinMode(Bs3,INPUT_PULLUP);

pinMode(b1,INPUT_PULLUP);
pinMode(b2,INPUT_PULLUP);
pinMode(b3,INPUT_PULLUP);

strip.begin();    
strip.show(); 

lum = EEPROM.read(lumo);

r1 = EEPROM.read(red1);
g1 = EEPROM.read(green1);
bl1 = EEPROM.read(blue1);

r2 = EEPROM.read(red2);
g2 = EEPROM.read(green2);
bl2 = EEPROM.read(blue2);

r3 = EEPROM.read(red3);
g3 = EEPROM.read(green3);
bl3 = EEPROM.read(blue3);

strip.setBrightness(lum);

strip.setPixelColor(0, strip.Color(r1, g1, bl1));
strip.setPixelColor(1, strip.Color(r2, g2, bl2));
strip.setPixelColor(2, strip.Color(r3, g3, bl3));

if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
  Serial.println(F("Erreur : écran OLED non détecté"));
  for (;;); 
}

display.clearDisplay();
display.setTextSize(2); 
display.setTextColor(SSD1306_WHITE);

display.setCursor(10, 32);  
display.print("Ptit Deej");
display.display();  
delay(2000);
display.clearDisplay();

Keyboard.begin();
 Consumer.begin();

Serial.begin(9600);

}

void loop() {
 
  int etatbut = digitalRead(b1);
  int etatbut2 = digitalRead(b2);
  int etatbut3 = digitalRead(b3);
  if(etatbut == LOW){
    display.clearDisplay();
    delay(200);
    mode = mode + 1;
  if(mode > 2 ){
    mode = 0;
    }
  }
 
  if(mode == 0){

    display.setTextSize(1);  
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(4, 3); 
    display.print("Page 1");
    display.drawRect(0, 1, 40, 12, SSD1306_WHITE);  
    display.drawLine(0, 12, 128, 12, SSD1306_WHITE);

    int w1 = map(Ana[0],0,1020,0,50);
    display.drawRect(40, 25, 50, 5, SSD1306_WHITE);  
    display.fillRect(41,26,w1,4,WHITE); 

    int w2 = map(Ana[1],0,1020,0,50);
    display.drawRect(40, 35, 50, 5, SSD1306_WHITE); 
    display.fillRect(41,36,w2,4,WHITE); 

    int w3 = map(Ana[2],0,1020,0,50);
    display.drawRect(40, 45, 50, 5, SSD1306_WHITE);  
    display.fillRect(41,46,w3,4,WHITE); 

    int etatA1 = digitalRead(As1);
    int etatB1 = digitalRead(Bs1);
 
    int etatA2 = digitalRead(As2);
    int etatB2 = digitalRead(Bs2);

    int etatA3 = digitalRead(As3);
    int etatB3 = digitalRead(Bs3);
 
  if(etatA1 > etatB1){
    display.clearDisplay();
    delay(300);
    Ana[0] = An1;
    if (An1 < 1020) An1 = An1+40;
  }else if(etatA1 < etatB1){
    display.clearDisplay();
    delay(300);
    if (An1 > 0) An1 = An1-40;
  }

 
  if(etatA2 > etatB2){
    display.clearDisplay();
    delay(300);
    if (An2 < 1020) An2 = An2+40;
  }else if(etatA2 < etatB2){
    display.clearDisplay();
    delay(300);
    if (An2 > 0) An2 = An2-40;
  }

 
  if(etatA3 > etatB3){
    display.clearDisplay();
    delay(300);
    if (An3 < 1020) An3 = An3+40;
  }else if(etatA3 < etatB3){
    display.clearDisplay();
    delay(300);
    if (An3 > 0) An3 = An3-40;
  }

Ana[0] = An1;
Ana[1] = An2;
Ana[2] = An3;

 if (etatbut2 == LOW) {
     Consumer.write(MEDIA_VOLUME_MUTE);
    delay(100);
    Keyboard.releaseAll();
    delay(500);
  }

 if (etatbut3 == LOW) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.releaseAll();
    delay(500); 
  }

}

if(mode==1){

  display.setTextSize(1);  
  display.setTextColor(SSD1306_WHITE);  
  display.setCursor(40, 3);
  display.print("Page 2");
  display.drawRect(40, 1, 40, 12, SSD1306_WHITE); 
  display.drawLine(0, 12, 128, 12, SSD1306_WHITE);

  display.setCursor(20, 30);  
  display.print("Mode Raccourcis");

  int etatA1 = digitalRead(As1);
  int etatB1 = digitalRead(Bs1);

  int etatA2 = digitalRead(As2);
  int etatB2 = digitalRead(Bs2);

  int etatA3 = digitalRead(As3);
  int etatB3 = digitalRead(Bs3);

  if(etatA3 > etatB3){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_C);
    Keyboard.releaseAll();
    delay(300);
    if (An3 < 1020) An3 = An3+40;
  }else if(etatA3 < etatB3){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_V);
    Keyboard.releaseAll();
    delay(300);
    if (An3 > 0) An3 = An3-40;
  }
}
  

if(mode==2){

    if(etatbut2 == LOW){
      display.clearDisplay();
      delay(200);
      mled = mled + 1;
      display.display();
    if(mled > 4 ){
    mled= 1;  
  }
}

  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(90, 3); 
  display.print("Page 3");
  display.drawRect(88, 1, 40, 12, SSD1306_WHITE); 
  display.drawLine(0, 12, 128, 12, SSD1306_WHITE);

  int etatA1 = digitalRead(As1);
  int etatB1 = digitalRead(Bs1);

  int etatA2 = digitalRead(As2);
  int etatB2 = digitalRead(Bs2);

  int etatA3 = digitalRead(As3);
  int etatB3 = digitalRead(Bs3);

  if(mled==1){

    display.setTextSize(1);  
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(30, 25); 
    display.print("Luminosite :");
  
    display.setCursor(55, 40);  
    display.print(lum);

  if(etatA1 > etatB1){
    display.clearDisplay();
    delay(200);
    if (lum < 100) lum = lum+5;
      Luminosite(lum);
  }else if(etatA1 < etatB1){
    display.clearDisplay();
    delay(200);
    if (lum > 0) lum = lum-5;
      Luminosite(lum);
  }else if(lum<0) lum = 0;
  EEPROM.update(lumo, lum);
  }

  if(mled==2){

    display.setTextSize(1);  
    display.setTextColor(SSD1306_WHITE); 

    display.setCursor(40, 35);
    display.print(" LED 1");

    display.setCursor(10, 20); 
    display.print(r1);

    display.setCursor(50, 20);  
    display.print(g1);

    display.setCursor(90, 20); 
    display.print(bl1);

  if(etatA1 > etatB1){
    display.clearDisplay();
    delay(200);
    if (r1 < 255) r1 = r1+5;
  }else if(etatA1 < etatB1){
    display.clearDisplay();
    delay(200);
    if (r1 > 0) r1 = r1-5;
  }

  if(etatA2 > etatB2){
    display.clearDisplay();
    delay(200);
    if (g1 < 255) g1 = g1+5;
  }else if(etatA2 < etatB2){
    display.clearDisplay();
    delay(200);
    if (g1 > 0) g1 = g1-5;
  }

  if(etatA3 > etatB3){
    display.clearDisplay();
    delay(200);
    if (bl1 < 255) bl1 = bl1+5;
  }else if(etatA3 < etatB3){
    display.clearDisplay();
    delay(200);
    if (bl1 > 0) bl1 = bl1-5;
  } 
  
  EEPROM.update(red1, r1);
  EEPROM.update(green1, g1);
  EEPROM.update(blue1, bl1);

  }

  if(mled==3){

    display.setTextSize(1); 
    display.setTextColor(SSD1306_WHITE); 
    
    display.setCursor(40, 35); 
    display.print(" LED 2");

    display.setCursor(10, 20);  
    display.print(r2);

    display.setCursor(50, 20);  
    display.print(g2);

    display.setCursor(90, 20); 
    display.print(bl2);

  if(etatA1 > etatB1){
    display.clearDisplay();
    delay(100);
    if (r2 < 255) r2 = r2+5;
  }else if(etatA1 < etatB1){
    display.clearDisplay();
    delay(100);
    if (r2 > 0) r2 = r2-5;
  }

  if(etatA2 > etatB2){
    display.clearDisplay();
    delay(100);
    if (g2 < 255) g2 = g2+5;
  }else if(etatA2 < etatB2){
    display.clearDisplay();
    delay(100);
    if (g2 > 0) g2 = g2-5;
  }

  if(etatA3 > etatB3){
    display.clearDisplay();
    delay(100);
    if (bl2 < 255) bl2 = bl2+5;
  }else if(etatA3 < etatB3){
    display.clearDisplay();
    delay(100);
    if (bl2 > 0) bl2 = bl2-5;
  }
  
  EEPROM.update(red2, r2);
  EEPROM.update(green2, g2);
  EEPROM.update(blue2, bl2);
  }
  if(mled==4){

    display.setTextSize(1);  
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(40, 35); 
    display.print(" LED 3");

    display.setCursor(10, 20); 
    display.print(r3);

    display.setCursor(50, 20); 
    display.print(g3);

    display.setCursor(90, 20); 
    display.print(bl3);

  if(etatA1 > etatB1){
    display.clearDisplay();
    delay(100);
    if (r3 < 255) r3 = r3+5;
  }else if(etatA1 < etatB1){
    display.clearDisplay();
    delay(100);
    if (r3 > 0) r3 = r3-5;
  }

  if(etatA2 > etatB2){
    display.clearDisplay();
    delay(100);
    if (g3 < 255) g3 = g3+5;
  }else if(etatA2 < etatB2){
    display.clearDisplay();
    delay(100);
    if (g3 > 0) g3 = g3-5;
  }

  if(etatA3 > etatB3){
    display.clearDisplay();
    delay(100);
    if (bl3 < 255) bl3 = bl3+5;
  }else if(etatA3 < etatB3){
    display.clearDisplay();
    delay(100);
    if (bl3 > 0) bl3 = bl3-5;
  }
  
  EEPROM.update(red3, r3);
  EEPROM.update(green3, g3);
  EEPROM.update(blue3, bl3);
  } 
  Serial.println(r1);
  Serial.println(g1);
  Serial.println(bl1);
  }

  updateSliderValues();
  sendSliderValues();

  strip.setPixelColor(0, strip.Color(r1, g1, bl1));
  strip.setPixelColor(1, strip.Color(r2, g2, bl2));
  strip.setPixelColor(2, strip.Color(r3, g3, bl3));
  display.display();
  strip.show();

}

void updateSliderValues() {
  for (int i = 0; i < 3; i++) {
    analogSliderValues[i] = Ana[i];
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < 3; i++) {
    builtString += String((int)analogSliderValues[i]);
    if (i < 3 - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString); 
}

void Luminosite(int lumi) {
  lumi = map(lumi,0,100,0,255);
  strip.setBrightness(lumi);  
}

