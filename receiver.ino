#include<SPI.h>
#include<RF24.h>
#include<Servo.h>

Servo servox;
Servo servoy;

RF24 radio (7, 8);      

struct package
{
  int valbx = 90;             //thats will make the camera allways start in right position 90 degrees 
  int valby = 90;
  
}data;

byte addresses[][6] = {"0"}; 



void setup() {
  
  radio.begin(); 
  radio.setChannel(115); 
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_250KBPS ) ; 
  radio.readingPipe(1,addresses[0]);
  radio.startListening();
  
  servox.attach(9);
  servoy.attach(10);
}

void loop()
{
  if(radio.available()
  {
    while(radio.available())
    {
      radio.(&data,sizeof(data));
      servox.write(data.valbx);
      servoy.write(data.valby);
    }
  }
}
