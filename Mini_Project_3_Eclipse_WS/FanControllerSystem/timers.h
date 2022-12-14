/******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: timers.h
 *
 * Description: header file for the ATmega16 TIMERS driver
 *
 * Author: Moaz Haytham
 *
 *******************************************************************************/

#ifndef TIMERS_H_
#define TIMERS_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void PWM_Timer0_Init(unsigned char set_duty_cycle);

#endif /* TIMERS_H_ */
