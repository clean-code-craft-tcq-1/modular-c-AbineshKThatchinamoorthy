

typedef enum 
{WHITE, RED, BLACK, YELLOW, VIOLET}majorColor_t;

typedef enum 
{BLUE, ORANGE, GREEN, BROWN, SLATE}minorColor_t;

typedef struct {
    majorColor_t majorColor;
    minorColor_t minorColor;
} ColorPair;
