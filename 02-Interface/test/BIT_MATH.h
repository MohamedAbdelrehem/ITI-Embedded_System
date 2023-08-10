/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//MY SETTERS and GETTERS
#define SET_BIT(VAR,BIT_NO) (VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR&=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)


#endif /* BIT_MATH_H_ */
