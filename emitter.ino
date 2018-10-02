#include <SPI.h>
#include<RF24.h>

RF24 radio (7, 8); 
struct package{
  
  int valbx = 90;
  int valby = 90;
  
}data;

byte addresses[][6] = {"0"}; 

int valx;
int valy;

void setup()
{

  radio.begin(); 
  radio.setChannel(115); 
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_250KBPS ) ; 
  radio.openWritingPipe(addresses[0]);
  
}

void loop()
{
  
  valx = analogRead(0);
  valy = analogRead(1);
 
  valx = map(valx,0,1023,0,179);
  valy = map(valy,0,1023,0,179);

    radio.write(&data,sizeof(data));

}
