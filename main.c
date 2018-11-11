/*
 * main.c
 */
#include <stdint.h>
#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "Segment.h"
#include "Segment_Cfg.h"
#include "BTN.h"
#include "BTN_Cfg.h"

#define F_CPU 4000000
#include <util/delay.h>

int main(void) {
	int Seg[4]={0,0,0,0}
	uint8_t OnOff;
	uint8_t Increment;
	uint8_t Decrement;
	uint8_t Field;
	uint8_t Selector=0;
	uint8_t count=0;
	GPIO_Init();
	Seg_Init();
	BTN_Init();
	while(1)
	{
		Seg_disp(0,Seg[0],DP_OFF);
		Seg_Disp(1,Seg[1],DP_OFF);
		Seg_Disp(2,Seg[2],DP_OFF);
		Seg_Disp(3,Seg[3],DP_OFF);
		BTN_GetBtnState(0,&OnOff);
		if(OnOff == BTN_ON)
		{
			_delay_ms(100);
			Seg_Off(Selector);
			_delay_ms(100);
			BTN_GetBtnState(1,&Increment);
			BTN_GetBtnState(1,&Field);
			BTN_GetBtnState(1,&Decrement);
			if(Field == BTN_JPRSD)
			{
				Selector++
				if(Selector>3)
				{
					Selector=0;
				}
				else
				{
					/* Do nothing */
				}
			}
			else
			{
				/* Do nothing */
			}
			if (Increment == BTN_JPRSD)
			{
				Seg[Selector]++;
				if ((Selector==0)&&(Seg[0]==10))
				{
					Seg[0]=0;
				}
				else if((Selector == 1)&&(Seg[1]==6))
				{
					Seg[1]=0;
				}
				else if ((Selector==2)&&((Seg[2]==10)||((Seg[2]>3)&&(Seg[3]>=2))))
				{
					Seg[2]=0
				}
				else if ((Selector==3)&&((Seg[3]==3)||((Seg[2]>3)&&(Seg[3]>1))))
				{
					Seg[3]=0;
				}
				else
				{
					/* do nothing */
				}

			}
			else if (Decrement ==BTN_JPRSD)
			{
				Seg[Selector]--;
				if ((Selector==0)&&(Seg[0]<0))
				{
					Seg[0]=9;
				}
				else if ((Selector==1)&&(Seg[1]== -1))
				{
					Seg[1]=5;
				}
				else if ((Selector==2)&&((Seg[2]== -1)&&(Seg[3]>1)))
				{
					seg[2]=3;
				}
				else if ((Selector==2)&&(Seg[2]== -1))
				{
					Seg[2]=9;
				}
				else if ((Selector ==3)&&((Seg[3]== -1)&&(Seg[2]>3)))
				{
					Seg[3]=1;
				}
				else if ((Selector ==3)&&(Seg[3]==-1))
				{
					Seg[3]=2;
				}
				else
				{
					/* Do nothing */
				}
			}
			else
			{
				/* Do nothing */
			}
		}
		else if ((OnOff == BTN_OFF)&&(Count==60))
		{
			Count=0;
			if((Seg[3]==2)&&(Seg[2]==3)&&(Seg[1]==5)&&(Seg[0]==9))
			{
				Seg[0]=0;
				Seg[1]=0;
				Seg[2]=0;
				Seg[3]=0;
			}
			else if (Seg[0]==9)
			{
				Seg[1]++;
				Seg[0]=0;
				if(Seg[1]==6)
				{
					Seg[2]++;
					Seg[1]=0;
					if (Seg[2]==10)
					{
						Seg[3]++;
						Seg[2]=0;
					}
					else
					{
						/* Do nothing */
					}
				}
				else
				{
					/* Do nothing*/
				}
			}
			else
			{
				Seg[0]++;
			}
			_delay_ms(1000);
			count++;
		}
		else
		{
			_delay_ms(1000);
			Count++;
		}
	}
	
	return 0;
}
