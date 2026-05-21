// #include<stdlib.h>
// #include<string.h>
#include "Shapes.h"

#define Max 10

int Shapes[Max][3][2] = {
    {{-2, 1},
     {1, 1},
     {-2, 1}}};
char SideValue[2][4] = {"   ", "[#]"};

char *BlockMaker(int BlockValue)
{
    char *block = (char *)malloc(sizeof(char) * 200);
    block[0] = '\0';
    int row = sizeof(Shapes[BlockValue]) / sizeof(Shapes[BlockValue][0]);
    int col = sizeof(Shapes[BlockValue][0]) / sizeof(Shapes[BlockValue][0][0]);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int index = (Shapes[BlockValue][i][j] == 1) ? 1 : -2;
            strcat(block, SideValue[index]);
        }
        strcat(block, "\n");
    }
    return block;
}

int *ShapeSender(int index, int row)
{

    if (row == -1)
    {
        int *tosend = (int *)malloc(sizeof(int) * 2);
        tosend[0] = (sizeof(Shapes[index]) / sizeof(Shapes[index][0]));
        tosend[1] = sizeof(Shapes[index][0]) / sizeof(Shapes[index][0][0]);
        return tosend;
    }

    return Shapes[index][row];
}

int RandomvalueGen(int Value)
{
    srand(time(NULL));
    if (Value == 0)
        return rand() % Max;
    else
        return rand() % Value;
}
