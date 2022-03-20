#include "codigo.h" 
class_serial c_serial;

void setup(void){

Serial.begin(115200);
}


void loop (void) {

   if( Serial.available ())
      c_serial.SerialEvent();

}
