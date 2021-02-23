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

void formatToString_v(const colorPair_t* colorPair_p, char* strOutput_p) 
{
    sprintf(strOutput_p, "%s %s",
        majorColorNames_a[colorPair_p->majorColor_e],
        minorColorNames_a[colorPair_p->minorColor_e]);
}

colorPair_t getColorFromPairNumber_s(int pairNumber_i) 
{
    colorPair_t colorPair_s;
    int zeroBasedPairNumber_i = pairNumber_i - GENERIC_VALUE_ONE;
    colorPair_s.majorColor_e = 
        (majorColor_t)(zeroBasedPairNumber_i / NUM_OF_MIN_COLORS);
    colorPair_s.minorColor_e =
        (minorColor_t)(zeroBasedPairNumber_i % NUM_OF_MIN_COLORS);
    return colorPair_s;
}

int getPairNumberFromColor_i(majorColor_t majorColor_e, minorColor_t minorColor_e) 
{
    return ((colorPair_p->majorColor_e * NUM_OF_MIN_COLORS) +
            colorPair_p->minorColor_e + GENERIC_VALUE_ONE);
}

void testNumberToPair_v(int pairNumber,
                        majorColor_t expectedMajor,
                        minorColor_t expectedMinor)
{
    colorPair_t colorPair_s = getColorFromPairNumber_s(pairNumber);
    char colorPairNameStr_a[MAX_COLORPAIR_NAME_CHARS];
    formatToString_v(&colorPair_s, colorPairNameStr_a);
    printf("Got pair %s\n", colorPairNameStr_a);
    assert(colorPair_s.majorColor_e == expectedMajor);
    assert(colorPair_s.minorColor_e == expectedMinor);
}

void testPairToNumber_v(majorColor_t majorColor_e,
                        minorColor_t minorColor_e,
                        int expectedPairNumber_i)
{
    int pairNumber = getPairNumberFromColor_i(majorColor_e, minorColor_e);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber_i);
}

void main() 
{
    testNumberToPair_v(4, WHITE, BROWN);
    testNumberToPair_v(5, WHITE, SLATE);

    testPairToNumber_v(BLACK, ORANGE, 12);
    testPairToNumber_v(VIOLET, SLATE, 25);
}
