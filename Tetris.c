#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Shapes.h"
#include 
/*
To compile 
gcc Tetris.c shapes.c -o Tetris
.\Tetris

*/

// ***You Shoudl change the Left variabe not the rigth variable
#define Length (19 + 1)
#define Height (19 + 1)

char grid[Height][Length];


void GridPrinting();
void BorderMaker();
void blocksCreation();
char *BlockMaker(int BlockValue);


typedef struct
{
    int horsides;
    int versides;
    int closed;

} Block;

int main()
{

    BorderMaker();
    int c = 0;

    GridPrinting();
}


void BorderMaker()
{

    for (int row = 0; row < Height; row++)
    {
        for (int col = 0; col < Length; col++)
        {
            if ((row == 0) || (row == Height - 1))
            {
                grid[row][col] = '-';
                Horsize++;
            }
            else if ((col == 0) || (col == Length - 1))
            {
                grid[row][col] = '|';
                Lensize++;
            }
            else
            {
                grid[row][col] = '.';
                check++;
            }
        }
    }
}

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

void GridPrinting()
{
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Length; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}