/******************************************************************************
*******     (C) COPYRIGHT Robert Bosch GmbH  - All Rights Reserved     ********
******************************************************************************/
/*!
***     \file        ColorCodeMngmnt.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Source Code of Color Code Management for cables
***                  
*****************************************************************************/

/* Project Inlusions */
#include "ColorCodeMngmnt.h"

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/
const char* majorColorNames_a[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* minorColorNames_a[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

/*=============================================================================
=======                       FUNCTION DEFINITIONS                      =======
=============================================================================*/
/*---------------------------------------------------------------------------*/
/*     FUNCTION:    formatToString_v
 */
/*!    \brief       Formats the Major and Minor Color names into a single string
 *
 *     \param       colorPair_p [IN] - Structure which contains the input strings
                    to be formatted (const colorPair_t*)
 *     \param       strOutput_p [IN] - Formatted output String(char*)
 *     \returns     void
*//*------------------------------------------------------------------------*/
void formatToString_v(const colorPair_t* colorPair_p, char* strOutput_p) 
{
    sprintf(strOutput_p, "%s %s",
        majorColorNames_a[colorPair_p->majorColor_e],
        minorColorNames_a[colorPair_p->minorColor_e]);
} /* EO formatToString_v */

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    getColorFromPairNumber_s
 */
/*!    \brief       Provides Major and Minor color names based on the input 
 *                  pair number
 *
 *     \param       pairNumber_i [IN] - pairnumber for which the cressponding
                    color names has to be identified (int)
 *     \returns     colorPair_s [OUT] - Identified major and minor names based
 *                  on the input pairnumber (colorPair_t)
*//*------------------------------------------------------------------------*/
colorPair_t getColorFromPairNumber_s(int pairNumber_i) 
{
    colorPair_t colorPair_s;
    int zeroBasedPairNumber_i = pairNumber_i - GENERIC_VALUE_ONE;
    colorPair_s.majorColor_e = 
        (majorColor_t)(zeroBasedPairNumber_i / NUM_OF_MIN_COLORS);
    colorPair_s.minorColor_e =
        (minorColor_t)(zeroBasedPairNumber_i % NUM_OF_MIN_COLORS);
    return colorPair_s;
} /* EO getColorFromPairNumber_s */

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    getPairNumberFromColor_i
 */
/*!    \brief       Provides the Pairnumber based on the input major & minor
 *                  colors
 *
 *     \param       majorColor_e [IN] - Major Color for which pairnumber has to
                    be identified (majorColor_t)
 *     \param       minorColor_e [IN] - Minor Color for which pairnumber has to
                    be identified (minorColor_t)
 *     \returns     pairNumber [OUT] - Identified pairnumber based on the input 
                    major and minor color names (int)
*//*------------------------------------------------------------------------*/
int getPairNumberFromColor_i(majorColor_t majorColor_e,
                             minorColor_t minorColor_e) 
{
    return ((majorColor_e * NUM_OF_MIN_COLORS) +
            minorColor_e + GENERIC_VALUE_ONE);
} /* EO getPairNumberFromColor_i */

/*EOF*/

