/******************************************************************************
*******     (C) COPYRIGHT Robert Bosch GmbH  - All Rights Reserved     ********
******************************************************************************/
/*!
***     \file        ColorCodeMngmnt.h
***     \author      Abinesh KanjiKovil Thatchinamoorthy
***     \brief       Header file of Color Code Management
***    File_description
***                  
*****************************************************************************/
#ifndef COLORCODEMANAGEMENT_H
#define COLORCODEMANAGEMENT_H

/*=============================================================================
=======                       STANDARD INCLUSIONS                       =======
=============================================================================*/
#include <stdio.h>
#include <assert.h>

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
#define MAX_COLORPAIR_NAME_CHARS        16
#define NUM_OF_MIN_COLORS               5
#define GENERIC_VALUE_ONE               1

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/
const char* majorColorNames_a[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* minorColorNames_a[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

typedef enum 
{WHITE, RED, BLACK, YELLOW, VIOLET}majorColor_t;

typedef enum 
{BLUE, ORANGE, GREEN, BROWN, SLATE}minorColor_t;

typedef struct {
    majorColor_t majorColor_e;
    minorColor_t minorColor_e;
} colorPair_t;

/*=============================================================================
=======                      FUNCTION DECLARATIONS                      =======
=============================================================================*/
void formatToString_v(const colorPair_t* colorPair_p, char* strOutput_p);
colorPair_t getColorFromPairNumber_s(int pairNumber_i);
int getPairNumberFromColor_i(majorColor_t majorColor_e,
                             minorColor_t minorColor_e);

#endif

/*EOF*/
