/******************************************************************************
***     \file        ColorCodeMngmnt.c
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Color Code Management for cables
***    File_description
***                  
*****************************************************************************/

#include <stdio.h>
#include <assert.h>

#include "ColorCodeMngmnt.h"

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (majorColor_t)(zeroBasedPairNumber / NUM_OF_MIN_COLORS);
    colorPair.minorColor =
        (minorColor_t)(zeroBasedPairNumber % NUM_OF_MIN_COLORS);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * NUM_OF_MIN_COLORS +
            colorPair->minorColor + 1;
}

void testNumberToPair(int pairNumber,
    majorColor_t expectedMajor,
    minorColor_t expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    majorColor_t major,
    minorColor_t minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
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
