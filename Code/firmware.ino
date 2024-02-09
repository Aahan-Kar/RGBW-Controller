#define WhiteKnob 0
#define BlueKnob 1
#define GreenKnob 2
#define RedKnob 3
#define swhwSwitch 2
#define differsby 4   //As the analog value fluctuates quite a lot this is how much the new value has to differ from the olv value to be considered as new value
#define WhitePWMPin 10
#define BluePWMPin 9
#define GreenPWMPin 6
#define RedPWMPin 5

int WhiteBrightness=0;
int BlueBrightness=0;
int GreenBrightness=0;
int RedBrightness=0;
bool TypeOfControl=false;    //false means HW control true means sofrware control
bool ControlOverride = false; //Allow the software to override the control if necessary. Toggling the HW/SW switch should clear this flag.


void setup()
{                
  pinMode(swhwSwitch, INPUT);
  analogWriteResolution(11);
  analogWriteFrequency(RedPWMPin, 23437.5);
  analogWriteFrequency(GreenPWMPin, 23437.5);
  analogWriteFrequency(BluePWMPin, 23437.5);
  analogWriteFrequency(WhitePWMPin, 23437.5);

  RedBrightness=(analogRead(RedKnob)*2047)/1023;
  analogWrite(RedPWMPin,2047-RedBrightness);         //My Potentiometers are wires to decrease in voltage on clockwise turn. As it seems counter intuitive I just ionvert in the software
  GreenBrightness=(analogRead(GreenKnob)*2047)/1023;
  analogWrite(GreenPWMPin,2047-GreenBrightness);
  BlueBrightness=(analogRead(BlueKnob)*2047)/1023;
  analogWrite(BluePWMPin,2047-BlueBrightness);
  WhiteBrightness=(analogRead(WhiteKnob)*2047)/1023;
  analogWrite(WhitePWMPin,2047-WhiteBrightness);
  Serial.begin(9600);
}

void loop()                     
{
  if(digitalRead(swhwSwitch)==1)    //the switch is open. Pin 2 is wired for active low
    TypeOfControl=false;
  else
    TypeOfControl=true;

  //if(!TypeOfControl)        //i.e. it's under hardware control
  //{
     int val = 0;
     val=(analogRead(RedKnob)*2047)/1023;
     if(abs(RedBrightness-val)>differsby)
     {
       RedBrightness =val;
       Serial.print("RedBrightness=");
       Serial.println(RedBrightness);
       analogWrite(RedPWMPin,2047-RedBrightness);         //My Potentiometers are wires to decrease in voltage on clockwise turn. As it seems counter intuitive I just ionvert in the software
     }

     val=(analogRead(GreenKnob)*2047)/1023;
     if(abs(GreenBrightness-val)>differsby)
     {
        GreenBrightness=val;
        Serial.print("GreenBrightness=");
        Serial.println(GreenBrightness);
        analogWrite(GreenPWMPin,2047-GreenBrightness);
     }

     val=(analogRead(BlueKnob)*2047)/1023;
     if(abs(BlueBrightness-val)>differsby)
     {
        BlueBrightness=val;
        Serial.print("BlueBrightness=");
        Serial.println(BlueBrightness);
        analogWrite(BluePWMPin,2047-BlueBrightness);
     }

     val=(analogRead(WhiteKnob)*2047)/1023;
     if(abs(WhiteBrightness-val)>differsby)
     {
        WhiteBrightness=val;
        Serial.print("WhiteBrightness=");
        Serial.println(WhiteBrightness); 
        analogWrite(WhitePWMPin,2047-WhiteBrightness);
     }         
    
  //}
  //Serial.println(val);
  //delay(250);
}
