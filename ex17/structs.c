#include <stdio.h>

typedef struct
{
    float X;
    float Y;
} Pixel;

typedef unsigned char byte;

typedef struct
{
    byte Red;
    byte Green;
    byte Blue;
} Color;

int main(void)
{
    Pixel p = { 10.0f, 20.0f };

    Color c = { 255, 128 };

    float x = p.X;

    c.Blue = 255;
}

