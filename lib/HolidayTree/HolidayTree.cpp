/*
  HolidayTree.cpp - Library for Hour of Code NeoPixel Project.
  Created by Giselle Koo, November 2015.
*/
#include "Arduino.h"
#include <StandardCplusplus.h>
#include <Adafruit_NeoPixel.h>
#include <vector>
#include "HolidayTree.h"

/* 
  CONSTRUCTOR. Each strand must have the same number of lights 
*/
HolidayTree::HolidayTree(int nStrands, int nLights){
  /* Save these numbers for future reference */
  numStrands = nStrands;
  numLights = nLights;
  
  /* Create <numStrand> strands with <numLights> lights on each. */
  if(numStrands > 13) {
    Serial.print("[Warning] Arduino Uno only has 12 non-Serial Digital Pins (DP #2 - DP #13). You may use Analog Pins 0-6 as Digital Pins 14-19"); 
  }
  strand.reserve(numStrands);
  for(int i = 0; i < numStrands; i++){
    Adafruit_NeoPixel s = Adafruit_NeoPixel(nLights, i + 2, NEO_GRB + NEO_KHZ800);
    strand.push_back(s);
  }
}

/*
  This function should be called in the setup() arduino function.
  Brightness is a number between 0 and 255.
*/
void HolidayTree::init(int brightness){
  for(int i = 0; i < numStrands; i++){
    Adafruit_NeoPixel s = strand[i];
    s.begin();
    s.setBrightness(brightness);
  }
  show();
}

void HolidayTree::show(){
  for(int i = 0; i < numStrands; i++){
    Adafruit_NeoPixel s = strand[i];
    s.show();
  }
}

void HolidayTree::setLightColor(int strandNum, int light, int red, int green, int blue){
  strand[strandNum].setPixelColor(light, red, green, blue);
}

int HolidayTree::getNumStrands(){
  return numStrands;
}

int HolidayTree::getNumLights(){
  return numLights;
}

/* turns all lights red.*/
void HolidayTree::test(){
  for(int i = 0; i < numStrands; i++){
    for(int j = 0; j < numLights; j++){
      setLightColor(i, j, 255, 0, 0);
    }
  }
  show();
}
/* turns all lights off*/
void HolidayTree::reset(){
  for(int i = 0; i < numStrands; i++){
    for(int j = 0; j < numLights; j++){
      setLightColor(i, j, 0, 0, 0);
    }
  }
  show();
}