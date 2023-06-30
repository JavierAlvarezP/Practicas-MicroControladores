#include <16F877A.h> 
#fuses XT, NOWDT, PUT, NOPROTECT, NOLVP, BROWNOUT, NOCPD, NOWRT, NODEBUG
#use delay (clock= 4000000) 
#use standard_io (a) 
#define use_portb_lcd true
#define use_portb_kbd true
#include <lcd.c> 
#include <kbd.c> 
#include <stdlib.h> 
#rom 0x2100 = {'7','2','3'} // Posición 0,1 y 2 de la Eeprom con los datos. //7,2, y 3 respectivamente 

void main (){
     char k; 
     int i; 
     char data[3], clave[3]; // Matrices para guardar clave y datos 
     lcd_init (); 
     kbd_init ();
     port_b_pullups (TRUE); 
     while (TRUE) {
     i=0; // posición de la matriz 
     printf(lcd_putc,"\fpulsar tecla 1\n"); 
     while (i<=2){ 
        k=kbd_getc();
      if (k!=0)
         {data[i]=k;
         i++;
         printf(lcd_putc,"\fpulsar tecla %u\n",i+1);
         }    
    }
   for (i=0;i<=2;i++){
     clave[i]=read_eeprom(i);}
   if ((data[0]==clave[0])&&(data[1]==clave[1])&&(data[2]==clave[2]))
      { printf(lcd_putc,"\fPuerta Abierta");
    output_high(PIN_A0);
    delay_ms(500);
    output_low(PIN_A0);}
   else printf(lcd_putc,"\fPuerta Cerrada");
    delay_ms(1000);
    
     }
     
}
