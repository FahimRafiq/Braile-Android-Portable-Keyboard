#include <Keyboard.h>


#define mode usb
#define debug 1
#define bouncetime 50
enum modes {serial, usb};
bool newPress;
char imode = 'a';
//               s6,s5,s4,s3,s2,s1,ENT,DEL
//byte pinMap[] = {10 , 9, 8, 4, 12, 6, 7, 11 };
//byte pinMap[] = {10,9,8,7,6,5,14,15};
byte pinMap[] = {2 ,3, 4, 16, 10, 6, 14, 15};
byte keyMap[] = {

  B000000,
  //    6XS432
  'a', B100000,//a
  'b', B110000,
  'c', B100100,
  'd', B100110,
  'e', B100010,
  'f', B110100,
  'g', B110110,
  'h', B110010,
  'i', B010100,
  'j', B010110,
  'k', B101000,
  'l', B111000,
  'm', B101100,
  'n', B101110,
  'o', B101010,
  'p', B111100,
  'q', B111110,
  'r', B111010,
  's', B011100,
  't', B011110,
  'u', B101001,
  'v', B111001,
  'w', B010111,
  'x', B101101,
  'y', B101111,
  'z', B101011, //z
  '#', B001111,
  '`', B111111,
};

byte keyMapN[] = {

  B000000,
  //    A86432
  '1', B100000,//a
  '2', B110000,
  '3', B100100,
  '4', B100110,
  '5', B100010,
  '6', B110100,
  '7', B110110,
  '8', B110010,
  '9', B010100,
  '0', B010110,
  '`', B111111,
};

void setup() {
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  if (debug)
    Serial.begin(115200);
  if (mode == usb)
    Keyboard.begin();
  for (int i = 0; i <= 7; i++) {
    pinMode(pinMap[i], INPUT);
//    digitalWrite(pinMap[i], HIGH);
  }
}

void loop() {
  char character = readKeys();

  if (newPress && character != 0) {
    if (character == '`')
    {
      if (imode == 'a') {
      imode = 'n';
    } else {
      imode = 'a';
    }
    } else {
      if (mode == usb)
      Keyboard.print(character);
    else if (mode == serial)
      Serial.print(character);
    }
    newPress = 0;
  }
  
  if (newPress) newPress = 0;
}
