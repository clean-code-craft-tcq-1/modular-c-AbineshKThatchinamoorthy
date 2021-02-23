/******************************************************************************
***     \file        ColorCodeMngmnt.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Color Code Management for cables
***    File_description
***                  
*****************************************************************************/

/* Standard Inlusions */
#include <stdio.h>
#include <assert.h>

/* Project Inlusions */
#include "ColorCodeMngmnt.h"

void formatToString_v(const colorPair_t* colorPair_p, char* strOutput_p) {
    sprintf(strOutput_p, "%s %s",
        majorColorNames_a[colorPair_p->majorColor],
        minorColorNames_a[colorPair_p->minorColor]);
}

colorPair_t GetColorFromPairNumber(int pairNumber) {
    colorPair_t colorPair_s;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair_s.majorColor = 
        (majorColor_t)(zeroBasedPairNumber / NUM_OF_MIN_COLORS);
    colorPair.minorColor =
        (minorColor_t)(zeroBasedPairNumber % NUM_OF_MIN_COLORS);
    return colorPair_s;
}

int GetPairNumberFromColor(const colorPair_t* colorPair) {
    return colorPair->majorColor * NUM_OF_MIN_COLORS +
            colorPair->minorColor + 1;
}

void testNumberToPair(int pairNumber,
    majorColor_t expectedMajor,
    minorColor_t expectedMinor)
{
    colorPair_t colorPair_s = GetColorFromPairNumber(pairNumber);
    char colorPairNameStr_a[MAX_COLORPAIR_NAME_CHARS];
    formatToString_v(&colorPair_s, colorPairNameStr_a);
    printf("Got pair %s\n", colorPairNameStr_a);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    majorColor_t major,
    minorColor_t minor,
    int expectedPairNumber)
{
    colorPair_t colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
}
