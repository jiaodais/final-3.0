#include "LPC11xx.h"
#include "delay.h"
void delay(int a)
{
	int t=0;
	int i=0;
	int j=0;
	for (i=0;i<a;i++)
	for (j=0;j<12100;j++);
	return ;
}
