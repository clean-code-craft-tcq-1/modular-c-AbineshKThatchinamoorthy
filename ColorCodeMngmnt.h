
#include <stdio.h>

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
#define MAX_COLORPAIR_NAME_CHARS        16

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/
typedef enum 
{WHITE, RED, BLACK, YELLOW, VIOLET}majorColor_t;

typedef enum 
{BLUE, ORANGE, GREEN, BROWN, SLATE}minorColor_t;

typedef struct {
    majorColor_t majorColor;
    minorColor_t minorColor;
} ColorPair;


/*EOF*/
