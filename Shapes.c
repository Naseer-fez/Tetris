// #include<stdlib.h>
// #include<string.h>
#include "Shapes.h"

#define Max 10

int Shapes[Max][3][2] = {
    {{0, 1},
     {1, 1},
     {0, 1}}};
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
            int index = (Shapes[BlockValue][i][j] == 1) ? 1 : 0;
            strcat(block, SideValue[index]);
        }
        strcat(block, "\n");
    }
    return block;
}



int RandomvalueGen(int Value)
{
    srand(time(NULL));
    if(Value==0)return rand() % Max;
    else return rand()%Value;
    
}

