#include <16F877A.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stop=1)

#define right_servos pin_b0
#define middle_servos pin_b1
#define left_servos pin_b2

int16 i=0;
int x;

   // PWM Duty Cycles for Servo Control: 
   // (1000 us per [20 ms (50Hz)] = -90 degree)
   // (1500 us per [20 ms (50Hz)]  = 0 degree)
   // (2000 us per [20 ms (50Hz)]  = 90 degree)

void main ()
{
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x0F);
   set_tris_b(0x00);
   output_b(0x00);
   
   //PWM Duty Cycles for Servo Control: 
   // (1000 us = -90 degree)
   // (1500 us = 0 degree)
   // (2000 us = 90 degree)
   
 








  while(TRUE)
   {
   x=getc();

   /*******GO_FORWARD*******/
   if (x=='f')
   {
   
      for(i=0;i<=25;i++) //FOR is used for produce enough pwm signals for servo
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);         // 1300 1300 1300 -->  All Servos = -36 degree
      output_low(right_servos);
      output_low(middle_servos); 
      output_low(left_servos);       
      delay_us(18700);       
      }
      
      for(i=0;i<=25;i++) // 1300 1700 1300
                                     // Right & Left Servos = -36 degree
                                     // Middle Servos = +36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);      
      output_low(right_servos);    
      output_low(left_servos); 
      delay_us(400);       
      output_low(middle_servos); 
      delay_us(18300);       
      }   
      
      for(i=0;i<=25;i++) // 1800 1700 1800  
                                     // Right & Left Servos = +54 degree
                                     // Middle Servos = +36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1700);       
      output_low(middle_servos);
      delay_us(100);       
      output_low(right_servos);        
      output_low(left_servos); 
      delay_us(18200);       
      }
      





      for(i=0;i<=25;i++) // 1800 1300 1800
                                     // Right & Left Servos = +54 degree
                                    // Middle Servos = -36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(middle_servos);
      delay_us(500);       
      output_low(right_servos);   
      output_low(left_servos); 
      delay_us(18200);       
      }
   }
   
   /*******GO_BACK*******/
   if (x=='b')
   {
      for(i=0;i<=25;i++) // 1300 1700 1300
                                     // Right & Left Servos = -36 degree
                                     // Middle Servos = +36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(right_servos);    
      output_low(left_servos); 
      delay_us(400);       
      output_low(middle_servos); 
      delay_us(18300);       
      }   
      
      for(i=0;i<=25;i++)  // 1300 1300 1300 -->  All Servos = -36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(right_servos); 
      output_low(middle_servos);       
      output_low(left_servos); 
      delay_us(18700);       
      }
      
   







   for(i=0;i<=25;i++)  // 1800 1300 1800
                                      // Right & Left Servos = +54 degree
                                      // Middle Servos = -36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(middle_servos);
      delay_us(500);
      output_low(right_servos);      
      output_low(left_servos); 
      delay_us(18200);       
      }
      
      for(i=0;i<=25;i++) // 1800 1700 1800
                                     // Right & Left Servos = +54 degree
                                     // Middle Servos = +36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1700);       
      output_low(middle_servos);
      delay_us(100);       
      output_low(right_servos);        
      output_low(left_servos); 
      delay_us(18200);       
      }
   }
   
   /*******TURN_RIGHT*******/
   if (x=='r')
   {
   
      for(i=0;i<=25;i++)  // 1300 1300 1800
                                      // Right & Middle Servos = -36 degree
                                      // Left Servos = +54 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(right_servos);
      output_low(middle_servos); 
      delay_us(500);       
      output_low(left_servos); 
      delay_us(18200);       
      }
      




      for(i=0;i<=25;i++) // 1300 1700 1800
                                     // Right Servos = -36 degree
                                     // Middle Servos = +36 degree
                                     // Left Servos = +54 degree
      
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(right_servos);
      delay_us(400);
      output_low(middle_servos); 
      delay_us(100);       
      output_low(left_servos); 
      delay_us(18200);       
      }  
      
      for(i=0;i<=25;i++) // 1800 1700 1300
                                     // Right Servos = +54 degree
                                     // Middle Servos = +36 degree
                                     // Left Servos = -36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(left_servos);
      delay_us(400);       
      output_low(middle_servos); 
      delay_us(100);
      output_low(right_servos); 
      delay_us(18200);       
      }
      
      for(i=0;i<=25;i++) // 1800 1300 1300
                                     // Right Servos = +54 degree
                                     // Middle Servos = -36 degree
                                     // Left Servos = -36 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(middle_servos);       
      output_low(left_servos);
      delay_us(500);
      output_low(right_servos); 
      delay_us(18200);       
      }
   }
   


   /*******TURN_LEFT*******/
   if (x=='l')
   {
   
      for(i=0;i<=25;i++)  // 1800 1300 1300
                                      // Left & Middle Servos = -36 degree
                                      // Right Servos = +54 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(left_servos);
      output_low(middle_servos); 
      delay_us(500);       
      output_low(right_servos); 
      delay_us(18200);       
      }
      
      for(i=0;i<=25;i++) // 1800 1700 1300
                                     // Right Servos = +54 degree
                                     // Middle Servos = +36 degree
                                     // Left Servos = -37 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(left_servos);
      delay_us(400);
      output_low(middle_servos); 
      delay_us(100);       
      output_low(right_servos); 
      delay_us(18200);       
      }   
      
      for(i=0;i<=25;i++) // 1300 1700 1800
                                     // Right Servos = -36 degree
                                     // Middle Servos = +36 degree
                                     // Left Servos = +54 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(right_servos);
      delay_us(400);       
      output_low(middle_servos); 
      delay_us(100);
      output_low(left_servos); 
      delay_us(18200);       
      }

      
      for(i=0;i<=25;i++) // 1300 1300 1800
                                     // Right Servos = -36 degree
                                     // Middle Servos = -36 degree
                                     // Left Servos = +54 degree
      {
      output_high(right_servos);
      output_high(middle_servos);
      output_high(left_servos);
      delay_us(1300);       
      output_low(middle_servos);       
      output_low(right_servos);
      delay_us(500);
      output_low(left_servos); 
      delay_us(18200);       
      }
   }   
   }
}

