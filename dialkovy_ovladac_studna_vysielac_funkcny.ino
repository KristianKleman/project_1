/*
Author: Danny van den Brande, Arduinosensors.nl. BlueCore Tech.
*/
 ///////transmitter
 
#include <VirtualWire.h>
int pin6 = 6;
int pin4 = 4;
int Button1 = 10; 
boolean val ;
 
void setup() {
    pinMode(pin6, OUTPUT);
    pinMode(pin4, OUTPUT);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin4, LOW);
    
    Serial.begin(9600);
    Serial.print("Hello there.  ,");
    
    pinMode(13,OUTPUT);
    pinMode (Button1, INPUT);
    vw_set_tx_pin(6); 
    vw_setup(4000);// speed of data transfer in bps, can max out at 10000
}
 
void loop()
{
  char *senddata="1";
  val = digitalRead (Button1); 
    if (val == 0){
    Serial.print(val);
    digitalWrite(13,1); 
    vw_send((uint8_t *)senddata, strlen(senddata));
    vw_wait_tx(); 
    digitalWrite(13,0); 
    delay(1000);
    
    }
}
