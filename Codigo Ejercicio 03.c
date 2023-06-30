#include <16F877A.h>
#fuses XT,NOWDT
#use delay ( clock = 4000000 )
#include <lcd.c>
#use standard_io(C)
#use standard_io(A)

  enum funciones {med,cal,ini};

void medir(void)
{
    output_toggle(pin_C0);
}
   
   void calibrar(void){
   output_toggle(pin_C1);
   }
   
    void inicializar(void){
    output_toggle(pin_C2);
    }
    
    void run_func(int numfunc){
    
       switch(numfunc) {
          case med:
              medir();
              break;
         case cal:
              calibrar();
              break;
         case ini:
              inicializar();
              break;
       }
    }
    
    void main() {
       char item;
       char n_menus = 3;
       
       lcd_init();

   while(1){
      if (input(PIN_A0) == 1) {
          item++;
          delay_ms(300);
          lcd_putc('\f');
          
      }     
          
       if (item > (n_menus-1)){
            item = 0; }
            
            
      switch (item) {
      
         case 0:
            lcd_gotoxy(1,1);
            printf(lcd_putc,"MEDIR");
            lcd_gotoxy(1,1);
            break;
            
        case 1:
            printf(lcd_putc,"CALIBRAR");
            lcd_gotoxy(1,1);
            break;
            
            
         case 2:
            printf(lcd_putc,"INICIALIZAR");
            lcd_gotoxy(1,1);
            break;
      }
      
      if (input(PIN_A1) == 1) 
         {delay_ms(200);
         run_func(item); }
   

   
   }

}
   




