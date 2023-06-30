#include <16F877A.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 4000000)
#define use_portb_lcd TRUE
#define use_portb_kbd TRUE
#include <lcd.c>
#include <kbd.c>


void main() {
    char k;
    int  x;
    kbd_init();
    lcd_init();
    port_b_pullups(TRUE);
    lcd_putc("\fListo...\n");
    
    while (true) {
        k=kbd_getc();
        x=k-48;
        if(k!=0) {
           if(k=='*')
             lcd_putc('\f');
           else
             lcd_putc(k);
             delay_ms(500);
             
             printf(lcd_putc,"\f Car=%c",k); 
             delay_ms(500);
             
             printf(lcd_putc,"\f Ascii=%u",k);
             delay_ms(500);
             
             printf(lcd_putc,"\f Num=%u",x);
             delay_ms(500);
             lcd_putc("\fListo...\n");
             
              
        }
    }
    
}
