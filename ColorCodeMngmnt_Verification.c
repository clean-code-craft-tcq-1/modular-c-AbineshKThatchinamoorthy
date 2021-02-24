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

/* Project Inlusions */
#include "ColorCodeMngmnt.h"

/*=============================================================================
=======                      FUNCTION DECLARATIONS                      =======
=============================================================================*/
static void testNumberToPair_v(int pairNumber_i,
                        majorColor_t expectedMajor_e,
                        minorColor_t expectedMinor_e);
static void testPairToNumber_v(majorColor_t majorColor_e,
                        minorColor_t minorColor_e,
                        int expectedPairNumber_i);

/*=============================================================================
=======                       FUNCTION DEFINITIONS                      =======
=============================================================================*/

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
static void testNumberToPair_v(int pairNumber_i,
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
static void testPairToNumber_v(majorColor_t majorColor_e,
                        minorColor_t minorColor_e,
                        int expectedPairNumber_i)
{
    int actualPairNumber_i = getPairNumberFromColor_i(majorColor_e, minorColor_e);
    printf("Got pair number %d\n", actualPairNumber_i);
    assert(actualPairNumber_i == expectedPairNumber_i);
} /* EO testPairToNumber_v */

void main() 
{
    testNumberToPair_v(4, WHITE, BROWN);
    testNumberToPair_v(5, WHITE, SLATE);

    testPairToNumber_v(BLACK, ORANGE, 12);
    testPairToNumber_v(VIOLET, SLATE, 25);
} /* EO main */

/* EOF */
