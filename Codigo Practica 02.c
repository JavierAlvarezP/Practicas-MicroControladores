#include <16F877A.h>                                                   //declaramos el pic a utilizar en este caso es el pic16f877a
#fuses XT,NOWDT,PUT,NOWRT,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT             //los fuses de trabajo
#use delay(clock=4000000)                                              //declaramos la velocidad del reloj a 4mhz
#include <LCD.c>                                                       //añadimos la libreria del LCD
#byte PORTB=0x06                                                       //habilitamos todo el puerto B
#byte TRISB=0x86

int led1,led2,led3,led4;                                        //declaramos variables
int s=0,s2=0,m0=0,m=0,m2=0,h=0,h2=0;                                // declaramos las variables para las horas, minutos y segundos

#int_timer1             

void timer_1(){        

   led1++;                 
   if (led1==2){                                                    //contamos cada 2 segundos apagar el puerto b0, realizando un ciclo de encendido y apagado en 2 segundos
   s=s+1;                                                            //una vez terminado el ciclo, comienza de nuevo
   m0=m0+1;
   output_toggle(pin_b0);{                                         //declaramos el pin b0 del led rojo como salida
   led1=0;}
   set_timer1(3035);}                                               //se retorna al valor inicial del timer
   led2++;
   
   if (led2==120){                                               //contamos cada 120 segundos para apagar el puerto b1, realizando un ciclo de encendido y apagado en 120 segundos, una vez terminado el ciclo, comienza de nuevo
   output_toggle(pin_b1);{                                       //declaramos el pin b1 del led amrillo como salida
   led2=0;}
   set_timer1(3035);}                                             //se retorna al valor inicial del timer 
   led3++;
   
   if (led3==180){                                              //contamos 180 segundos para apagar el puerto b2, realizando un ciclo de encendido y apagado en 180 segundos, una vez terminado el ciclo, comienza de nuevo
   output_toggle(pin_b2);{                                      //declaramos el pin b2 del puerto verde como salida
   led3=0;}
   set_timer1(3035);}                                            //se retorna al valor inicial del timer
   led4++;
   
   if (led4==240){                                              //contamos 240 segundos para apagar el puerto b3, realizando un ciclo de encendido y apagado en 240 segundos, una vez terminado el ciclo, comienza de nuevo
   output_toggle(pin_b3);{                                     //declaramos el pin b3 del led azul como salida
   led4=0;}
   set_timer1(3035);}                                              //se retorna al valor inicial del timer
   
   
   }

void main(){
 TRISB=0x00;                                                            //declaramos todo el puerto B como salidas
 PORTB=0x00;
 setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);                                 ///configuración del Timer1 por medio de parámetros, en este caso sera en modo temporizador
 set_timer1(3036);                                                        //se retorna al valor inicial del timer
 enable_interrupts(int_timer1);                                            //Habilita interrupciones del timer1
 enable_interrupts(global);                                               //Habilita interrupciones
 led1=0;                                                                   //definimos los leds en apagado
 led2=0;
 led3=0;
 led4=0;
 
 while(true){
    lcd_init();                                                         //Iniciamos el display
    lcd_gotoxy(1,1);                                                    //le decimos que coloque el texto en la parte superior izquierda
    printf(lcd_putc,"TIEMPO %i%i:%i%i:%i%i",h2,h,m2,m,s2,s);            //mostrara la palabra "Tiempo asi como las variables previamente declaradas
       if(m0>59){
       m=m+1;
       m0=0;
       }
          if(s>9){                                                   //si "s" llega a 9, se le suma uno a S2 y "s" vuelve a 0
          s2=s2+1;
          s=0;
          }
             if(s2>5){                                              //si "s2" llega a 5, "s2" vuelve a 0
             s2=0;
             }
                if(m>9){                                             //si m es mayor de 9, a m2 se le suma 1 y m vuelve a 0
                m2=m2+1;
                m=0;
                }
}
}

