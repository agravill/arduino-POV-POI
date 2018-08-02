#include <SPI.h>
#include <SD.h>
#include <FastLED.h>
#define LED_PIN_1    6
#define LED_PIN_2    7
#define NUM_LEDS    36
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  64

CRGB leds[NUM_LEDS];
unsigned char image[180];
File myFile;

void setup() {
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds, NUM_LEDS);
    LEDS.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    Serial.begin(9600);
  Serial.print("\nWaiting for SD card ready...");
  if (!SD.begin(4)) {
    Serial.println("Fail!");
    return;
  }
  Serial.println("Success!");
}

void loop()
{
   for(int i =0;i<30;i++){
      char filename[] = "face.txt";
      display(filename,255,165,79,0,0,0);
   }
   for(int i =0;i<30;i++){
      char filename[] = "heart.txt";
      display(filename,255,105,180,50,50,255);
   }
   for(int i =0;i<30;i++){
      char filename[] = "star.txt";
      display(filename,255,215,0,255,255,255);
   }
  //change_color();
   for(int i =0;i<30;i++){
      char filename[] = "face1.txt";
      display(filename,255,165,79,0,0,0);
   }
   for(int i =0;i<30;i++){
      char filename[] = "heart1.txt";
      display(filename,255,105,180,50,50,255);
   }
   for(int i =0;i<30;i++){
      char filename[] = "star1.txt";
      display(filename,255,215,0,255,255,255);
   }


    for(int i =0;i<30;i++){
      char filename[] = "face1.txt";
      display(filename,255,165,79,0,0,0);
   }
   for(int i =0;i<30;i++){
      char filename[] = "heart1.txt";
      display(filename,255,105,180,50,50,255);
   }
   for(int i =0;i<30;i++){
      char filename[] = "star1.txt";
      display(filename,255,215,0,255,255,255);
   }
}


unsigned char read_line(File myFile){
   String s =  "";
   char c;
   while((c = myFile.read()) !='\n' && c !=' '){
      s += c;
   }  
   return (unsigned char)(s.toInt()); 
}
void display(char* filename,int BR,int BG ,int BB,int WR,int WG,int WB){
   myFile = SD.open(filename);
   if (myFile){
      for(int i=0;i<128;i++){
        image[i] = read_line(myFile);
      }
   }else {
      Serial.println("\n open file error ");    // 無法開啟時顯示錯誤
   }
   myFile.close();
FastLED.clear();
  for(int j=0;j<36;j++){ 
  byte e = image[0+j];
  byte d = image[36+j];
  byte c = image[72+j];
  byte b = image[108+j];
  byte a = image[144+j];
  FastLED.clear();
  for(int i=3;i>=0;i--){
    if((a & B00000001) == 1){
      leds[i].setRGB(BR,BG,BB);
      //255 165 79
    }else{
      leds[i].setRGB(WR,WG,WB);
    }
   a >>= 1;
  }
  for(int i=11;i>=4;i--){
    if((b & B00000001) == 1){
      leds[i].setRGB(BR,BG,BB);
    }else{
      leds[i].setRGB(WR,WG,WB);
    }
   b >>= 1;
  }
  for(int i=19;i>=12;i--){
    if((c & B00000001) == 1){
      leds[i].setRGB(BR,BG,BB);
    }else{
      leds[i].setRGB(WR,WG,WB);
    }
   c >>= 1;
  }
  for(int i=27;i>=20;i--){
    if((d & B00000001) == 1){
      leds[i].setRGB(BR,BG,BB);
    }else{
      leds[i].setRGB(WR,WG,WB);
    }
   d >>= 1;
  }
  for(int i=35;i>=28;i--){
    if((e & B00000001) == 1){
      leds[i].setRGB(BR,BG,BB);
    }else{
      leds[i].setRGB(WR,WG,WB);
    }
   e >>= 1;
  }
  FastLED.show();
  delay(0.01);
  }  
}

void change_color(){
    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(248,188, 255);
    }
    FastLED.show();
    delay(2400);
    
    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(1.4,100, 255);
    }
    FastLED.show();
    delay(2400);
  
    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(17.7,78.1, 255);
    }
    FastLED.show();
    delay(2400);  
 
    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(42.6,40, 255);
    }
    FastLED.show();
    delay(2400);

    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(108.8,64.3, 255);
    }
    FastLED.show();
    delay(2400);

    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setHSV(140,109, 255);
    }
    FastLED.show();
    delay(2400);

    FastLED.clear();
    fill_rainbow(leds,NUM_LEDS, 0, 35);
    FastLED.show();
    delay(2400);
  
}





