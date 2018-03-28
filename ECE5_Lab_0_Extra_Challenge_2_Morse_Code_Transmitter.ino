/*
  UPDATED: Blinking Morse Code Transmitter

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

const int LED1 = 13;
const int timeUnit = 100;

int messageLength = 0;

String message = "";

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // send data only when data is received:
  if (Serial.available() > 0) {
      // read the incoming string:
      message = Serial.readString();
      message.toLowerCase();
      messageLength = message.length()-2;
      
      // used for debugging purposes
      Serial.print("Message transmitted as: ");
      Serial.println(message);
      Serial.print("The length of the message is: ");
      Serial.println(messageLength);
      Serial.print("\n");
      // Serial.print("The last letter of the message is: ");
      // Serial.println(message[messageLength-1]);

      // read message character by character to convert to morse code
      int i = 0;
      while(i < messageLength){
        switch(message[i]){
          case 'a': // a = *-
          {
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // -  
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'b': // b = -***
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);  
          // * x3
          for(int j = 0; j < 3; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'c': // c = -*-*
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // *  
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'd': // d = -**
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // * x2
          for(int j = 0; j < 2; j++){  
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'e': // e = *
          {
          // *   
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'f': // f = **-*
          {
          // * x2
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'g': // g = --*
          {
          // - x2
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'h': // h = ****
          {
          // * x4
          for(int j = 0; j < 4; j++){ 
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'i': // i = **
          {
          // * x2
          for(int j = 0; j < 2; j++){
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          }
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'j': // j = *---
          {
          // *  
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // - x3
          for(int j = 0; j < 3; j++){
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          }
          // time delay between letters
          delay(3*timeUnit);     
          }
          break;
          case 'k': // k = -*-
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'l': // l = *-**
          {
          // *  
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // * x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit); 
          }
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'm': // m = --
          {
          // - x2 
          for(int j = 0; j < 2; j++){
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);  
          }
          // time delay between letters
          delay(3*timeUnit); 
          }
          break;
          case 'n': // n = -*
          {
          // -  
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);  
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);  
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'o': // o = ---
          {
          // - x3
          for(int j = 0; j < 3; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);   
            delay(timeUnit);   
          }
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'p': // p = *--*
          {
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);  
          // - x2
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          }
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'q': // q = --*-
          {
          // - x2
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);
          } 
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);  
          }
          break;
          case 'r': // r = *-*
          {
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 's': // s = ***
          {
          // * x3
          for(int j = 0; j < 3; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          }
          // time delay between letters 
          delay(3*timeUnit); 
          }
          break;
          case 't': // t = -
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'u': // u = **-
          {
          // * x2
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit); 
          }
          break;
          case 'v': // v = ***-
          {
          // * x3
          for(int j = 0; j < 3; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'w': // w = *--
          {
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // - x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'x': // x = -**-
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // * x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);          
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case 'y': // y = -*--
          {
          // -
          digitalWrite(LED1, HIGH);   
          delay(3*timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit);
          // *
          digitalWrite(LED1, HIGH);   
          delay(timeUnit);
          digitalWrite(LED1, LOW);    
          delay(timeUnit); 
          // - x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // time delay between letters
          delay(3*timeUnit);   
          }
          break;
          case 'z': // z = --**
          {
          // - x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(3*timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          } 
          // * x2 
          for(int j = 0; j < 2; j++){
            digitalWrite(LED1, HIGH);   
            delay(timeUnit);
            digitalWrite(LED1, LOW);    
            delay(timeUnit);   
          }  
          // time delay between letters
          delay(3*timeUnit);    
          }
          break;
          case ' ':
          {
          // time delay between words
          delay(7*timeUnit); 
          }
          break;
        }
        i++;
      }
      // used to verify correct converted message
    //Serial.println(i);
  }                   
}
