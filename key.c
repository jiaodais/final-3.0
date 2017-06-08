#include "KEY.H"
#include "LPC11XX.H"
#include "delay.h"
 int key_value;
int key_mode;
void key_init()
{
	LPC_GPIO3->DIR = 0xe0; // ��P3.0-5����Ϊ��������
	LPC_GPIO3->IE = 0x1f; // ����P3.0-5�����ϵ��ж�
  LPC_GPIO3->IS = 0xe0; // ����P3.0-5����Ϊ���ش���
  LPC_GPIO3->IEV =0xe0; // ����P3.0-5����Ϊ�½��ش���
//	LPC_GPIO3->IS = 0x1f; // ����P3.0-5����Ϊ��ƽ����
//	LPC_GPIO3->IEV =0xe0; // ����P3.0-5����Ϊ�͵�ƽ����
  NVIC_EnableIRQ(EINT3_IRQn); // ��GPIO3�ж�
}

void PIOINT3_IRQHandler()
{
		key_mode=0;														//0����δ�ɿ��ͼ�����1�����ɿ������
		if((LPC_GPIO3->MIS & (1<<0))==(1<<0)) // P3.0����
			{		
				delay(50);
				key_value=6;
				while((LPC_GPIO3->DATA&(1<<0))!=(1<<0)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<0);  // ���ж�
			}
    if((LPC_GPIO3->MIS & (1<<1))==(1<<1)) // P3.1����
			{	
				delay(50);
				key_value=7;
				while((LPC_GPIO3->DATA&(1<<1))!=(1<<1)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<1);  // ���ж�
			}
		if((LPC_GPIO3->MIS & (1<<2))==(1<<2)) // P3.2����
			{	
				delay(50);
				key_value=8;
				while((LPC_GPIO3->DATA&(1<<2))!=(1<<2)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<2);  // ���ж�
			}
		if((LPC_GPIO3->MIS & (1<<3))==(1<<3)) // P3.3����
			{		
				delay(50);				
				key_value=9;
				while((LPC_GPIO3->DATA&(1<<3))!=(1<<3)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<3);  // ���ж�
			}
		if((LPC_GPIO3->MIS & (1<<4))==(1<<4)) // P3.4����
			{	
				delay(50);				
				key_value=10;
				while((LPC_GPIO3->DATA&(1<<4))!=(1<<4)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<4);  // ���ж�
			}
}

