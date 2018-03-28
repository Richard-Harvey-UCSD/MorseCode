/*
  UPDATED: Blinking Morse Code Receiver

  Functionality now includes the ability to send any alphabetic messages through the serial monitor.
  
  Timing reference used:
  1. The length of a dot is 1 time unit.
  2. A dash is 3 time units.
  3. The space between symbols (dots and dashes) of the same letter is 1 time unit.
  4. The space between letters is 3 time units.
  5. The space between words is 7 time units.
  
  Source: http://www.codebug.org.uk/learn/step/541/morse-code-timing-rules/

  By: Richard Harvey
*/

const int sensor = A0;
const int timeUnit = 100;
const int threshold = 80;

int lightLevel = 0;
int thresholdVals = 0;
int nonThresholdVals = 0;
int messageLength = 0;

String morseCode = "";
String message = "";

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  lightLevel = analogRead(sensor);
  //Serial.print("Light intensity is: ");
  //Serial.println(lightLevel);
  delay(.25*timeUnit);
  if(lightLevel >= threshold){
    thresholdVals++;
    nonThresholdVals = 0;
  }
  else if(thresholdVals > 0 & lightLevel < threshold){
    if(thresholdVals <= 6){
      morseCode += '*';
      //Serial.println(morseCode);
      thresholdVals = 0; 
    }
    else{
      morseCode += '-';
      //Serial.println(morseCode);
      thresholdVals = 0;
    }
  }
  else{
    nonThresholdVals++;
    thresholdVals = 0;
  }
  //delay(.25*timeUnit);
  // now to decode signal into alphabetic message

  if(nonThresholdVals > 20 && morseCode.length() >= 1 && morseCode.length() < 4){
      morseCode += 'x';
      //Serial.println(morseCode);
  }

  if(morseCode.length() == 4){
    // a = *-
    if(morseCode == "*-xx"){
      //Serial.print("a");
      message += 'a';
      messageLength++;
      morseCode = "";
    }
    // b = -***
    else if(morseCode == "-***"){
      //Serial.print("b");
      message += 'b';
      messageLength++;
      morseCode = "";
    }
    // c = -*-*
    else if(morseCode == "-*-*"){
      //Serial.print("c");
      message += 'c';
      messageLength++;
      morseCode = "";
    }
    // d = -**
    else if(morseCode == "-**x"){
      //Serial.print("d");
      message += 'd';
      messageLength++;
      morseCode = "";
    }
    // e = *
    else if(morseCode == "*xxx"){
      //Serial.print("e");
      message += 'e';
      messageLength++;
      morseCode = "";
    }
    // f = **-*
    else if(morseCode == "**-*"){
      //Serial.print("f");
      message += 'f';
      messageLength++;
      morseCode = "";
    }
    // g = --*
    else if(morseCode == "--*x"){
      //Serial.print("g");
      message += 'g';
      messageLength++;
      morseCode = "";
    }
    // h = ****
    else if(morseCode == "****"){
      //Serial.print("h");
      message += 'h';
      messageLength++;
      morseCode = "";
    }
    // i = **
    else if(morseCode == "**xx"){
      //Serial.print("i");
      message += 'i';
      messageLength++;
      morseCode = "";
    }
    // j = *---
    else if(morseCode == "*---"){
      //Serial.print("j");
      message += 'j';
      messageLength++;
      morseCode = "";
    }
    // k = -*-
    else if(morseCode == "-*-x"){
      //Serial.print("k");
      message += 'k';
      messageLength++;
      morseCode = "";
    }
    // l = *-**
    else if(morseCode == "*-**"){
      //Serial.print("l");
      message += 'l';
      messageLength++;
      morseCode = "";
    }
    // m = --
    else if(morseCode == "--xx"){
      //Serial.print("m");
      message += 'm';
      messageLength++;
      morseCode = "";
    }
    // n = -*
    else if(morseCode == "-*xx"){
      //Serial.print("n");
      message += 'n';
      messageLength++;
      morseCode = "";
    }
    // o = ---
    else if(morseCode == "---x"){
      //Serial.print("o");
      message += 'o';
      messageLength++;
      morseCode = "";
    }
    // p = *--*
    else if(morseCode == "*--*"){
      //Serial.print("p");
      message += 'p';
      messageLength++;
      morseCode = "";
    }
    // q = --*-
    else if(morseCode == "--*-"){
      //Serial.print("q");
      message += 'q';
      messageLength++;
      morseCode = "";
    }
    // r = *-*
    else if(morseCode == "*-*x"){
      //Serial.print("r");
      message += 'r';
      messageLength++;
      morseCode = "";
    }
    // s = ***
    else if(morseCode == "***x"){
      //Serial.print("s");
      message += 's';
      messageLength++;
      morseCode = "";
    }
    // t = -
    else if(morseCode == "-xxx"){
      //Serial.print("t");
      message += 't';
      messageLength++;
      morseCode = "";
    }
    // u = **-
    else if(morseCode == "**-x"){
      //Serial.print("u");
      message += 'u';
      messageLength++;
      morseCode = "";
    }
    // v = ***-
    else if(morseCode == "***-"){
      //Serial.print("v");
      message += 'v';
      messageLength++;
      morseCode = "";
    }
    // w = *--
    else if(morseCode == "*--x"){
      //Serial.print("w");
      message += 'w';
      messageLength++;
      morseCode = "";
    }
    // x = -**-
    else if(morseCode == "-**-"){
      //Serial.print("x");
      message += 'x';
      messageLength++;
      morseCode = "";
    }
    // y = -*--
    else if(morseCode == "-*--"){
      //Serial.print("y");
      message += 'y';
      messageLength++;
      morseCode = "";
    }
    // z = --**
    else if(morseCode == "--**"){
      //Serial.print("z");
      message += 'z';
      messageLength++;
      morseCode = "";
    }
    else{
      Serial.print("Something went wrong!");
      message = "";
      morseCode = "";
    }
  }
  if(nonThresholdVals > 30 && message.length() == messageLength){
    Serial.println(messageLength);
    printMessage();
    message = "";
    //messageLength = 0;
    morseCode = "";
  }
}

void printMessage(){
  for(int i = 0; i < message.length(); i++){
    Serial.print(message[i]);
  }
  Serial.print(" ");
}


