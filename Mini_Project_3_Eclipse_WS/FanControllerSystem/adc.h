/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Moaz Haytham
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE   	 1023
#define ADC_REF_VOLT_VALUE  	 2.56

#define ADC_PRESCALAR_VALUE

#define ADC_VOLTAGE_REF_BIT_SHIFTER	6

#define ADC_CHANNEL_CLEAR		 0xE0

#define ADC_CHANNEL_PORT_ID		 PORTA_ID

#define ADC_CHANNEL_0_PIN_ID	 PIN0_ID
#define ADC_CHANNEL_1_PIN_ID	 PIN1_ID
#define ADC_CHANNEL_2_PIN_ID	 PIN2_ID
#define ADC_CHANNEL_3_PIN_ID	 PIN3_ID
#define ADC_CHANNEL_4_PIN_ID	 PIN4_ID
#define ADC_CHANNEL_5_PIN_ID	 PIN5_ID
#define ADC_CHANNEL_6_PIN_ID	 PIN6_ID
#define ADC_CHANNEL_7_PIN_ID	 PIN7_ID

#define ADC_ENABLE_PIN_ID		 PIN7_ID


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	AREF,AVCC,RESERVED,Internal_VREFF
} ADC_ReferenceVolatge;

typedef enum
{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_Channel;

typedef enum{
	PRESCALAR_0, PRESCALAR_2, PRESCALAR_4, PRESCALAR_8, PRESCALAR_16, PRESCALAR_32, PRESCALAR_64, PRESCALAR_128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(ADC_Channel channel_num);

#endif /* ADC_H_ */
