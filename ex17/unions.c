#include <stdio.h>

typedef union
{
    int Integer;
    char Character;
} OneThingOrAnother;

typedef enum
{
    TheInteger,
    TheCharacter
} WhichThing;

int main()
{
    OneThingOrAnother var;
    var.Integer = 123;

    WhichThing type = TheInteger;

    var.Character = 'V';
    type = TheCharacter;
}
