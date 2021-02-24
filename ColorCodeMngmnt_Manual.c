/******************************************************************************
*******     (C) COPYRIGHT Robert Bosch GmbH  - All Rights Reserved     ********
******************************************************************************/
/*!
***     \file        ColorCodeMngmnt.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Source Code for printing the manual for Color Code
***                  
*****************************************************************************/

/* Project Inlusions */
#include "ColorCodeMngmnt.h"


/*=============================================================================
=======                       FUNCTION DEFINITIONS                      =======
=============================================================================*/

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    printColorCodeManual_v
 */
/*!    \brief       Print the color code and pair number to serve as a manual
 *
 *     \param       void
 *     \returns     void
*//*------------------------------------------------------------------------*/
void printColorCodeManual_v(void)
{
  char colorPairNameStr_a[MAX_COLORPAIR_NAME_CHARS];
  for(int cnt_i = 1; cnt_i <= 25; cnt_i++)
  {
    colorPair_t colorPair_s = getColorFromPairNumber_s(cnt_i);  
    formatToString_v(&colorPair_s, colorPairNameStr_a);
    printf("%d  %s \n", cnt_i, colorPairNameStr_a);
  }
}
