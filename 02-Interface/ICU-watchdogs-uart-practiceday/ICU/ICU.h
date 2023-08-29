/*
 * ICU.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mohamed
 */

#ifndef ICU_C_
#define ICU_C_


typedef enum{
	ICU_EDGE_FALLING,
	ICU_EDGE_RAISING
}ICU_EdgeType;

void ICU_Init(void);
void ICU_SetEdge (ICU_EdgeType Copy_edge);
void ICU_EnableNotification(void);
void ICU_DisableNotification(void);

#endif /* ICU_C_ */
