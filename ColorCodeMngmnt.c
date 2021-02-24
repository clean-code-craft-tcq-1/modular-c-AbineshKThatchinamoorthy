/******************************************************************************
*******     (C) COPYRIGHT Robert Bosch GmbH  - All Rights Reserved     ********
******************************************************************************/
/*!
***     \file        ColorCodeMngmnt.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Source Code of Color Code Management for cables
***    File_description
***                  
*****************************************************************************/

/* Standard Inlusions */
#include <stdio.h>
#include <assert.h>

/* Project Inlusions */
#include "ColorCodeMngmnt.h"

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

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    testNumberToPair_v
 */
/*!    \brief       Tests whether the input color names are the corresponding 
 *                  names of the provided pair number
 *
 *     \param       pairNumber_i [IN] - Pairnumber for which the verification
                    has to be done (int)
 *     \param       expectedMajor_e [IN] -  Expected major Color for the
                    provided pair number(minorColor_t)
 *     \param       expectedMinor_e [IN] - Expected minor Color for the
                    provided pair number(majorColor_t)
*     \returns     void
*//*------------------------------------------------------------------------*/
void testNumberToPair_v(int pairNumber_i,
                        majorColor_t expectedMajor_e,
                        minorColor_t expectedMinor_e)
{
    colorPair_t colorPair_s = getColorFromPairNumber_s(pairNumber_i);
    char colorPairNameStr_a[MAX_COLORPAIR_NAME_CHARS];
    formatToString_v(&colorPair_s, colorPairNameStr_a);
    printf("Got pair %s\n", colorPairNameStr_a);
    assert(colorPair_s.majorColor_e == expectedMajor_e);
    assert(colorPair_s.minorColor_e == expectedMinor_e);
} /* EO testNumberToPair_v */

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    testNumberToPair_v
 */
/*!    \brief       Tests whether the pair number is the corresponding 
 *                  pairnumber of the provided color names
 *
 *     \param       expectedMajor_e [IN] - Major Color for which the
                    verification has to be done (majorColor_t)
 *     \param       expectedMinor_e [IN] - Minor Color for which the
                    verification has to be done (minorColor_e)
 *     \param       pairNumber_i [IN] - Expected Pairnumber for the provided
                    color names (int)    
 *     \returns     void
*//*------------------------------------------------------------------------*/
void testPairToNumber_v(majorColor_t majorColor_e,
                        minorColor_t minorColor_e,
                        int expectedPairNumber_i)
{
    int pairNumber = getPairNumberFromColor_i(majorColor_e, minorColor_e);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber_i);
} /* EO testPairToNumber_v */

int main() 
{
    testNumberToPair_v(4, WHITE, BROWN);
    testNumberToPair_v(5, WHITE, SLATE);

    testPairToNumber_v(BLACK, ORANGE, 12);
    testPairToNumber_v(VIOLET, SLATE, 25);
  
    return 0;
} /* EO main */
