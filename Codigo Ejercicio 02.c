#include <16F877A.h>
#USE DELAY ( clock = 4000000 )
#FUSES XT,NOWDT,NOPROTECT,NOPUT
#USE fast_IO (B)
#USE fast_IO (A)
byte CONST DISPLAY[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

 main()
{
   byte ud=0,dec=0;
   SET_TRIS_B(0X00);
   SET_TRIS_A(0X00);
   OUTPUT_B(0);
    
   for( ; ; ){
      for (dec=0;dec<10;dec++){
         for (ud=0;ud<10;ud++){
            OUTPUT_A(0X02);
            OUTPUT_B(DISPLAY[ud]);
            delay_ms(50);
            if (dec==0) output_a(0x03);
            
            else output_a(0x01);
            
            OUTPUT_B(DISPLAY[dec]);
            delay_ms(50);
         }
      }

   
   }

}




