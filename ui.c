#include "LPC11xx.h"
#include "stdio.h"
#include "string.h"
#include "KEY.h"
#include "delay.h"
#include "oled.h"
#include "ui.h"
#include "ADC.h"
#include "UART.h"
extern int  	key_value  ;
extern  float low_temp ;
extern  float high_temp ;
extern  uint32_t  k,t;
extern	int   lastlow_temp ;
extern	int   lasthigh_temp ; 
extern float low_temp;
extern float high_temp;
uint8_t Arrow = 2,	chonum, scrnum = 0;

uint8_t AR[]="--+";//��ʾ��ͷ
uint8_t AC[]="   ";//������ͷ

typedef struct 
{
	uint8_t num;
	uint8_t number[2];
	uint8_t title[20];
	uint8_t choose1[20];
	uint8_t choose2[20];
	uint8_t choose3[20];
	uint8_t choose4[20];
	uint8_t choose5[20];
	uint8_t choose6[20];
	uint8_t choose7[20];
}screen[1];
static screen scr[10]=
{
//{???,"???","����",      					 "�˵�1",               "�˵�2",           			  "�˵�3",           	    "�˵�4",             		"�˵�5", 	},
	{0,"0","zhuomian       ",   "     start     ",   "    Setting    ",   "    nothing   ",   "     MAKER ",   "     nothing        ",   },   
  {1,"1","start          ",   "    N_temp     ",   "       -       ",   "       _       ",   "       _       ",   "      nothing  ",   },
  {2,"2","setting        ",   "    lowtemp    ",   "   higetemp   ",   "       _       ",   "       -       ",   "      nothing   ",   },
  {3,"3","   nothing      ",   "       _       ",   "       _       ",   "       _       ",   "       -       ",   "    nothing    ",   },
  {4,"4"," MAKER       ",   "  15160200124  ",   "   LINXIA      ",   "  15160200116   ",   "    QIANCAHNGYOU  ",   "   0.0    ",   },
	

};
void printscreen(uint8_t i)
{
	OLED_P6x8Str(0,0,scr[i]->title );
	OLED_P6x8Str(16,2,scr[i]->choose1);
  OLED_P6x8Str(16,3,scr[i]->choose2);
	OLED_P6x8Str(16,4,scr[i]->choose3);
	OLED_P6x8Str(16,5,scr[i]->choose4);
	OLED_P6x8Str(16,6,scr[i]->choose5);
	OLED_P6x8Str(16,7,scr[i]->choose6);
	
}
uint8_t  UI(void)
{
	key_value = 0;
	chonum = 0;
	
	
	OLED_P6x8Str(0,Arrow,AR );
	
	printscreen (scrnum);
	
	switch(key_value )
	{
		case 6:                                   
    OLED_P6x8Str(0,Arrow,AC);
    Arrow--;
    if(Arrow < 2) Arrow=7;
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;
    break;
    
  case 7:                                   
    OLED_P6x8Str(0,Arrow,AC);
    Arrow++;
    if(Arrow > 7) Arrow=2;
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;
    break;
    
  case 8:                                   
    {
      OLED_CLS();
      OLED_P6x8Str(0,Arrow,AC);             
      if(scrnum!=0)                          
      {
        chonum=scrnum*10+Arrow-1;           
      }
      else
      {
        scrnum=Arrow-1;                     
        chonum=Arrow-1;
      }
      key_value = 0;
      break;
    }
  case 9:                                   
    {
      OLED_P6x8Str(0,Arrow,AC);
      scrnum=0;
      key_value = 0;
      OLED_CLS();
      break;
    }
  case 10:
		
    break;
	}



  switch(chonum)
    {

			case 11:UART_SendStr("N_temp:");
							OLED_Print(5, 0, "now temp:");
			        OLED_Print(5, 3, "now Frh" );
			        while(key_value != 9)
							{
								
								
								
								
							 ADC_read();
								
									OLED_PrintNum(30,2,t);
							
								
							
							  OLED_P6x8Str(43,2,".");
								OLED_P6x8Str(42,5,".");
								OLED_PrintNum(30,5,(t*(9/5)+32));
								OLED_P6x8Str(60,2,"C'");
								OLED_P6x8Str(60,5,"F'");
								
										
										
										if(key_value == 9)
											{
												OLED_CLS();
											}
									
								
							
								
								
							}
			
							
							break;
      case 12:break;
      case 13:break;
      case 14:break;
							
							
						}
					







					

					}