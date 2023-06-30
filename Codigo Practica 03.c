#include <16F877A.h>                                            //declaramos el pic a utilizar
#device adc=10                                                  //declaramos el valor del adc, es este caso es de 10
#fuses XT,NOWDT,PUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOCPD,NOWRT    //declaramos los fuses a utilizar
#use delay(clock=4000000)                                       //declaramos la velocidad del reloj en esta ocasion de 4mhz
#include <LCD.C>                                                //añadimos la libreria para el LCD

void main() {
   int16 C;                                                     //declaramos la variable para la conversion en esta ocasion use la letra "C"
   float V;                                                     //declaramos la variable para la tension o voltaje, en esta ocasion la letra "V"
   
   setup_adc_ports(AN0);                                        //declaramos el puerto AN0, como entrada
   setup_adc(ADC_CLOCK_INTERNAL);                               //activamos el reloj interno del pic
   set_adc_channel(0);                                          //declaramos el canal que usaremos, en esta ocasion es el canal 0
   delay_us(20);                                                //retardo de 20 microsegundos 
   lcd_init();                                                  //esta función se utiliza para inicializar la pantalla LCD.
   
while(1){

C=read_adc();                                                  //leemos la variable "C" que tomara el valor de la lectura del adc                      
V=5*C/1023.0;                                                  //calculamos la tension o voltaje, en esta ocasion usaremos solo "5v" que multimplica a la variable conversion"C", esto es dividido entre el valor en decimal de 10 bits = 1023
lcd_gotoxy(1,1);                                               //se indica la posicion del tecto en este casi la parte superior del display 
printf(lcd_putc,"CONVERSION=%4Ld", C);                         //aqui se muestra la palabra conversion asi como el valor de la variable "C"
lcd_gotoxy(1,2);                                               //se indica la posicion del texto en esta caso la parte baja del display
printf(lcd_putc,"TENSION= %1.2f V", V);                        //mostramos la palabra Tension, asi como el valor de la variable "V"
delay_ms(100);                                                 //por ultimo un delay de 100 milisegundos

}
}
   
