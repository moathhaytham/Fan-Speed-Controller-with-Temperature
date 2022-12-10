#include "lcd.h"
#include "DCMotor.h"
#include "adc.h"
#include "timers.h"

int main(void)
{

	ADC_ConfigType myConf = {Internal_VREFF, PRESCALAR_8}; /*struct with the configuration of the ADC*/
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&myConf); /* initialize ADC driver */

	LCD_displayString("FAN is ");

	LCD_moveCursor(1,0);
	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_displayString("Temp =    C");

	DcMotor_Init();
	//	PWM_Timer0_Init(255);

	DcMotor_Rotate(CW, 100);

	while(1)
	{

		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,7);

		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		if(temp <30)
		{
			DcMotor_Rotate(OFF, 0);

			LCD_moveCursor(0,7);
			LCD_displayString("OFF");
		}

		else if(temp >=30 && temp < 60)
		{
			DcMotor_Rotate(CW, 25);

			LCD_moveCursor(0,7);
			LCD_displayString("ON");
		}

		else if(temp >=60 && temp < 90)
		{
			DcMotor_Rotate(CW, 50);

			LCD_moveCursor(0,7);
			LCD_displayString("ON");
		}

		else if(temp >=90 && temp < 120)
		{
			DcMotor_Rotate(CW, 75);

			LCD_moveCursor(0,7);
			LCD_displayString("ON");
		}

		else if(temp >=120)
		{
			DcMotor_Rotate(CW, 100);

			LCD_moveCursor(0,7);
			LCD_displayString("ON");
		}



	}
}
