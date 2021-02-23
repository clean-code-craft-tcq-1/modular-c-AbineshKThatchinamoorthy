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

#include <stdio.h>

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


/*EOF*/
