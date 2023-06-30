#INCLUDE <16F877A.h>
#device adc=10
#use delay(clock=4000000)
#fuses XT,NOWDT
#BYTE TRISC = 0x87

void main() {
int16 valor;
int16 control;
float a,b,c;
float temp_limit;
float rT,eT,iT,dT,yT,uT,iT0,eT0,iT_1,eT_1;
float max,min;
min=0.0;
max=1000.0;
iT_1=0.0;
eT_1=0.0;
a=0.1243;
b=0.0062;
c=0.6215;
temp_limit=500.0;
TRISC=0;
setup_timer_2(t2_div_by_4,249,1);
setup_ccp1(ccp_pwm);
setup_adc_ports(all_analog);
setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0);
while(1) {
   valor=read_adc();
   yT=valor*5000.0/1024.0;
   rT=temp_limit;
   eT=rT-yT;
   iT=b*eT+iT0;
   dT=c*(eT-eT0);
   uT=iT+a*eT+dT;
   if (uT>max) {
       uT=max;}
   else {
      if (uT<min){
          uT=min; }
         
       }
   control=uT;
   set_pwm1_duty(control);
   iT0=iT;
   eT0=eT;
   delay_ms(100);
  }
}
