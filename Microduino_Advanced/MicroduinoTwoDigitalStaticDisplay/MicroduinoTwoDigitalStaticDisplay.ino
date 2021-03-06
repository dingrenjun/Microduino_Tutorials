byte digit0 = 10;	//ten digital for Microduino pin10
byte digit1 = 11;	//single digital for Microduino pin11
byte dotPin = 2;	//pointer for pin2

byte sevenSegmentPins[] = {2,3,4,5,6,7,8};	//A,B,C,D,E,F,G  correspanding Microduino pin
byte sevenSegment[10][7] =
{
  //a b c d e f g
  { 0,0,0,0,0,0,1 },  // = 0
  { 1,0,0,1,1,1,1 },  // = 1
  { 0,0,1,0,0,1,0 },  // = 2
  { 0,0,0,0,1,1,0 },  // = 3
  { 1,0,0,1,1,0,0 },  // = 4
  { 0,1,0,0,1,0,0 },  // = 5
  { 0,1,0,0,0,0,0 },  // = 6
  { 0,0,0,1,1,1,1 },  // = 7
  { 0,0,0,0,0,0,0 },  // = 8
  { 0,0,0,1,1,0,0 }   // = 9
};

void setup()
{

	//inital all light
   pinMode(dotPin, OUTPUT); //pin 2
   pinMode(digit0, OUTPUT); //pin 10
   pinMode(digit1, OUTPUT); //pin 11

  for(int i=0; i<7; i++)
  {
    pinMode(sevenSegmentPins[i], OUTPUT);
  }
  digitalWrite(dotPin, HIGH);
  digitalWrite(digit0, HIGH);
  digitalWrite(digit1, HIGH);
}

//show number
void segmentWrite(byte digit)
{
  byte pin = 2;
  for (byte i=0; i<7; ++i)
  {
    digitalWrite(pin, sevenSegment[digit][i]);
      ++pin;
  }
}

void loop()
{
  //dispaly 68
  digitalWrite(digit0, LOW);   //disable ten digital
  segmentWrite(8);             //show single digital 8
  delay(10);                  //10ms delay
  digitalWrite(digit0, HIGH);  //enable ten digital
  digitalWrite(digit1, LOW);   //disable single digital
  segmentWrite(6);             //show ten digital 6
  delay(10);                  //10ms delay
  digitalWrite(digit1, HIGH);  //enable single digital

}
