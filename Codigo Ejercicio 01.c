#include <16F877A.h>
#fuses XT,NOWDT
#use delay ( clock = 4000000 )
#BYTE TRISB = 0X86
#BYTE PORTB = 0X06
#BYTE OPTION_REG = 0X81

void main()
{
    bit_clear(OPTION_REG,7);
    bit_set(TRISB,0);
    bit_clear(TRISB,1);
    bit_clear(PORTB,1);
    
   while(1){
      if (bit_test(portb,0) == 1)
             bit_clear(portb,1);
      else
             bit_set(portb,1);
   


   
   }

}
