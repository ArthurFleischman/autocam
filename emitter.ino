#include <SPI.h>
#include<RF24.h>

RF24 radio (7, 8); 
struct package                                    //struct of data to be sent
{                                                     
  
  int valbx = 90;
  int valby = 90;
  
}data;

byte addresses[][6] = {"0"};                      //addresses

int valx;                                         //initializes values of horizontal and vertical servos
int valy;

void setup()
{
                                                  //radio setup
  radio.begin();                                  
  radio.setChannel(115); 
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_250KBPS ) ; 
  radio.openWritingPipe(addresses[0]);
                                                  //end of radio setup
}

void loop()
{
  
  valx = analogRead(0);                          //potentiometer attached to A0 pin
  valy = analogRead(1);                          //potentiometer attached to A1 pin
 
  valx = map(valx,0,1023,0,179);                 //mapping to the right values
  valy = map(valy,0,1023,0,179);

  radio.write(&data,sizeof(data));               //sending data

}
