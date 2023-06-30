#include <16F877A.h>
#fuses XT,NOWDT
int1 cambio=0;

#int_ccp2
void ccp2_int() {
   if(++cambio==1) {
     setup_ccp2(CCP_COMPARE_CLR_ON_MATCH);
   } else {
     setup_ccp2(CCP_COMPARE_SET_ON_MATCH);
   }
   set_timer1(0);
   CCP_2 = 199;
  }
  void main() {
  disable_interrupts(global);
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
  setup_ccp2(CCP_COMPARE_SET_ON_MATCH);
  CCP_2 = 199;
  
  enable_interrupts(int_ccp2);
  enable_interrupts(global);
  do {
  } while (TRUE);
 }
