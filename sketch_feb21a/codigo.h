#define _uint8_t    0x01
#define _int8_t     0x02
#define _uint16_t   0x03
#define _int16_t    0x04
#define _uint32_t   0x05
#define _int32_t    0x06
#define _uint64_t   0x07
#define _int64_t    0x08

class class_serial{
  
void setup();

   public:
    char byte_recibido;
    String trama_recibida;
    uint8_t x;

  public:
    void SerialEvent (void);
    uint64_t get_max (uint8_t);  
    uint64_t get_min (uint8_t);
    void get_data (uint8_t);
    void imprimisida(uint64_t n);

};

void class_serial::SerialEvent (void) {

    byte_recibido = (char)Serial.read();
    trama_recibida += byte_recibido;

         
  
     if (byte_recibido == '\n'){

       if (trama_recibida == "uint8_t\n")
         get_data (_uint8_t);

        if( trama_recibida == "int8_t\n")
            get_data (_int8_t);

        if (trama_recibida == "uint16_t/n") 
         get_data (_uint16_t);

         if( trama_recibida == "int16_t\n")
            get_data ( _int16_t);

        if (trama_recibida == "uint32_t/n") 
         get_data (_uint32_t);

         if( trama_recibida == "int32_t\n")
            get_data (_int32_t);

        if (trama_recibida == "uint64_t/n") 
         get_data (_uint64_t);

          if( trama_recibida == "int64_t\n")
            get_data ( _int64_t);
     
       trama_recibida =""; 

}}

void class_serial::get_data ( uint8_t data){

   switch (data){

    case _uint8_t:
      Serial.print("El rango maximo es: "); 
      Serial.println(get_max(8)-1);
      Serial.print("El rango mimimo es: ");
      Serial.println("0");
    break;

    case _int8_t:
       Serial.print("El rango maximo es: "); 
      Serial.println(get_max(7)-1);
      Serial.print("El rango mimimo es: -");
      Serial.println("8");
      break;

    case _uint16_t:
       Serial.print("El rango maximo es: "); 
      Serial.println(get_max(16)-1);
      Serial.print("El rango mimimo es: ");
      Serial.println("0");
    break;  

  case _int16_t:
       Serial.print("El rango maximo es: "); 
      Serial.println(get_max(15)-1);
      Serial.print("El rango mimimo es: -");
      Serial.println("16");
    break;

  case _uint32_t:
       Serial.print("El rango maximo es: "); 
      Serial.println(get_max(32)-1);
      Serial.print("El rango mimimo es: ");
      Serial.println("0");
    break;

  case _int32_t:
       Serial.print("El rango maximo es: "); 
      Serial.println(get_max(31)-1);
      Serial.print("El rango mimimo es: -");
      Serial.println("32");
    break;

  case _uint64_t:
      Serial.print("El rango maximo es: "); 
      Serial.println(get_max(64));
      Serial.println();
    break;
  
   }

   }

uint64_t class_serial::get_max(uint8_t exponente)
{

   return (uint64_t)pow (2,exponente);
}

uint64_t class_serial::get_min(uint8_t exponente)
{
   
   return (uint64_t)pow (2, (exponente -1));
   
} 
