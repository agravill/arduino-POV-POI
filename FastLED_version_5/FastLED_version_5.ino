#include <FastLED.h>
#define LED_PIN_1    6
#define LED_PIN_2    7
#define NUM_LEDS    36
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  64

//one-color

#include "face.h"
#include "heart.h"
#include "star.h"
#include "tree.h"

//--two color
#include "eee.h"
#include "sees.h"
#include "camp.h"
#include "lightning.h"
#include "crossing.h"

CRGB leds[NUM_LEDS];

void setup() {
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds, NUM_LEDS);
    LEDS.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    Serial.begin(9600);
}

void loop()
{
  /*
  for(int i =0;i<100;i++){
    display_onecolor(star,255,215,0,255,255,255);
  }
  for(int i =0;i<100;i++){
    display_onecolor(heart,255,105,180,50,50,255);
  }
  for(int i =0;i<100;i++){
    display_onecolor(face,255,165,79,0,0,0);
  }*/

  /*
  for(int i =0;i<100;i++){
    display_twocolor(eee1,eee2,eee_color);
    display_twocolor(sees1,sees2,sees_color);
    display_twocolor(camp1,camp2,camp_color);
  }
  for(int i =0;i<100;i++){
    display_twocolor(crossing1,crossing2,crossing_color);
  }
  
  for(int i =0;i<100;i++){
    display_onecolor(tree,tree_color);
  }
  */
  //fast_change_color();
  //all_random(20,50);
  hsv_change_color(50);
  fast_change_color(50);
  lattice_BG(50);
}
void hsv_change_color(int count){
  for(int k=0;k<count;k++){
     FastLED.clear();
     for(int j=0;j<256;j++){
       FastLED.clear();
       for(int i =0;i<NUM_LEDS;i++){
          leds[i].setHSV( j, 255, 255 );
       }
       FastLED.show();
       delay(0.5);
     }
  }
}
void lattice_BG(int count){
  for(int i=0 ;i<count;i++){
    FastLED.clear();
    fill_solid(leds,4,CRGB::Blue);
    fill_solid(leds+8,4,CRGB::Blue);
    fill_solid(leds+16,6,CRGB::Blue);
    fill_solid(leds+24,6,CRGB::Blue);
    fill_solid(leds+32,6,CRGB::Blue);
    FastLED.show();
    delay(20);
    FastLED.clear();
    fill_solid(leds+4,4,CRGB::Green);
    fill_solid(leds+12,4,CRGB::Green);
    fill_solid(leds+20,4,CRGB::Green);
    fill_solid(leds+28,4,CRGB::Green);
    FastLED.show();
    delay(20);
  }
}
void all_random(int millisec,int count){
  FastLED.clear();
  for(int j=0;j<count;j++){
    FastLED.clear();
    for(int i =0;i<NUM_LEDS;i++){
      leds[i].setRGB(random8(),random8(),random8());
    }
    FastLED.show();
    delay(millisec);
  }
}
void fast_change_color(int count){
  for(int i=0 ;i<count;i++){
    FastLED.clear();
    //fill_gradient_RGB(leds,(i)%42,CRGB::Red,(i+7)%42,CRGB::Blue);
    //fill_gradient_RGB(leds,(i+14)%42,CRGB::Blue,(i+21)%42,CRGB::Yellow);
    fill_solid(leds,NUM_LEDS,CRGB::Red);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::Orange);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::Yellow);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::Green);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::Blue);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::SlateBlue);
    FastLED.show();
    delay(20);
    fill_solid(leds,NUM_LEDS,CRGB::Purple);
    FastLED.show();
    delay(20);
  }
}

void display_onecolor(uint8_t* image,uint8_t color[][3]){
  FastLED.clear();
  for(int j=0;j<36;j++){ 
  uint8_t e = pgm_read_byte(image+j);
  uint8_t d = pgm_read_byte(image+36+j);
  uint8_t c = pgm_read_byte(image+72+j);
  uint8_t b = pgm_read_byte(image+108+j);
  uint8_t a = pgm_read_byte(image+144+j);
  FastLED.clear();
  for(int i=3;i>=0;i--){
    if((a & B00000001) == 1){
      leds[i].setRGB(color[0][0],color[0][1],color[0][2]);
      //255 165 79
    }else{
      leds[i].setRGB(color[1][0],color[1][1],color[1][2]);
    }
   a >>= 1;
  }
  for(int i=11;i>=4;i--){
    if((b & B00000001) == 1){
      leds[i].setRGB(color[0][0],color[0][1],color[0][2]);
    }else{
      leds[i].setRGB(color[1][0],color[1][1],color[1][2]);
    }
   b >>= 1;
  }
  for(int i=19;i>=12;i--){
    if((c & B00000001) == 1){
      leds[i].setRGB(color[0][0],color[0][1],color[0][2]);
    }else{
      leds[i].setRGB(color[1][0],color[1][1],color[1][2]);
    }
   c >>= 1;
  }
  for(int i=27;i>=20;i--){
    if((d & B00000001) == 1){
       leds[i].setRGB(color[0][0],color[0][1],color[0][2]);
    }else{
      leds[i].setRGB(color[1][0],color[1][1],color[1][2]);
    }
   d >>= 1;
  }
  for(int i=35;i>=28;i--){
    if((e & B00000001) == 1){
      leds[i].setRGB(color[0][0],color[0][1],color[0][2]);
    }else{
       leds[i].setRGB(color[1][0],color[1][1],color[1][2]);
    }
   e >>= 1;
  }
  FastLED.show();
  delay(0.01);
  }  
}
//-------
void display_twocolor(uint8_t* image1,uint8_t* image2,uint8_t color[][3]){
  uint8_t* ptr;
  FastLED.clear();
  for(int j=0;j<36;j++){
    FastLED.clear();
    for(int i=0;i<36;i++){
      leds[i].setRGB(color[2][0],color[2][1],color[2][2]);
    } 
    ptr = image1;
    for(int k=0;k<2;k++){  
      uint8_t e = pgm_read_byte(ptr+j);
      uint8_t d = pgm_read_byte(ptr+36+j);
      uint8_t c = pgm_read_byte(ptr+72+j);
      uint8_t b = pgm_read_byte(ptr+108+j);
      uint8_t a = pgm_read_byte(ptr+144+j);
      
      for(int i=3;i>=0;i--){
        if((a & B00000001) == 1){
          leds[i].setRGB(color[k][0],color[k][1],color[k][2]);
        }
       a >>= 1;
      }
      for(int i=11;i>=4;i--){
        if((b & B00000001) == 1){
          leds[i].setRGB(color[k][0],color[k][1],color[k][2]);
        }
       b >>= 1;
      }
      for(int i=19;i>=12;i--){
        if((c & B00000001) == 1){
          leds[i].setRGB(color[k][0],color[k][1],color[k][2]);
        }
       c >>= 1;
      }
      for(int i=27;i>=20;i--){
        if((d & B00000001) == 1){
          leds[i].setRGB(color[k][0],color[k][1],color[k][2]);
        }
       d >>= 1;
      }
      for(int i=35;i>=28;i--){
        if((e & B00000001) == 1){
          leds[i].setRGB(color[k][0],color[k][1],color[k][2]);
        }
       e >>= 1;
      }
      ptr = image2;
    }
    FastLED.show();
    delay(0.01);
  }  
}




