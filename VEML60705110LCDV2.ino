#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_VEML6070.h"

// Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, DC, CS, RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);


Adafruit_VEML6070 uv = Adafruit_VEML6070();

#define VEML6070_ADDR_L     (0x38) ///< Low address



//SCL A5
//SDA A4

void setup () {
  
   Serial.begin(9600);
   Serial.println("VEML6070 Test");
   uv.begin(VEML6070_1_T); 

  /*
   * Other measuring options
   VEML6070_HALF_T ~62.5ms
   VEML6070_1_T ~125ms
   VEML6070_2_T ~250ms
   VEML6070_4_T ~500ms
   */
  
  display.begin();
  delay(1000);
  display.clearDisplay(); // clears the screen and buffer
  display.display();
  display.setTextColor(BLACK);
  display.setContrast(70);
  }

void loop() {
  display.clearDisplay();
  display.setContrast(60);
  display.setTextSize(1);
  display.setCursor(20,0);
  display.print("UV Index");
  display.setTextSize(3);
  display.setCursor(35,20);
  display.print(uv.readUV()/230); //250

  if(uv.readUV()>=0 && uv.readUV()<689 )
  {
    display.setTextSize(1);
  display.setCursor(30,10);
  display.print("LOW");
  } else 

   if(uv.readUV()>=690 && uv.readUV()<1379)
  {
  display.setTextSize(1);
  display.setCursor(20,10);
  display.print("Moderate");
  } else 

   if(uv.readUV()>=1380 && uv.readUV()<1839)
  {
  display.setTextSize(1);
  display.setCursor(30,10);
  display.print("High");
  } else


  if(uv.readUV()>=1839 && uv.readUV()<2529)
  {
  display.setTextSize(1);
  display.setCursor(20,10);
  display.print("Very High");
  }

  if(uv.readUV()>=2530 && uv.readUV()<2760)
  {
  display.setTextSize(1);
  display.setCursor(10,10);
  display.print("Extreme high");
  }

  display.display();
  delay(500);
  
  
  
  
  }

  /*1-230
  2-460
  3-690
  4-920
  5-1150
  6-1380
  7-1610
  8-1840
  9-2070
  10-2300
  11-2530*/
