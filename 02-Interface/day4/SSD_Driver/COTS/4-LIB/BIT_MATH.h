/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  LIB                        *************************/
/************************                                            *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// MY SETTERS and GETTERS
#define SET_BIT(VAR, BIT_NO) (VAR |= (1 << BIT_NO))
#define CLR_BIT(VAR, BIT_NO) (VAR &= (~(1 << BIT_NO)))
#define TOGGLE_BIT(VAR, BIT_NO) (VAR ^= (1 << BIT_NO))
#define GET_BIT(VAR, BIT_NO) ((VAR >> BIT_NO) & 1)

#endif