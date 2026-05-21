#include "Allimports.h"
#include "Shapes.h"
#include "Functions.h"
/*
To compile
 gcc Tetris.c Shapes.c Functions.c -o Tetris; if ($?) { .\Tetris }

*/

// ***You Shoudl change the Left variabe not the rigth variable
#define Length (10 + 1)
#define Height (10 + 1)

// char grid[Height][Length];
int Postion[Height][Length];
void GridPrinting();
void BlockPlacement(int HorPlacement, int virPlacement);
bool isvalid(int *block, int len, int hor, int ver);
// char *BlockMaker(int BlockValue);


// Start from 1 and go till Length -2 for the values
void timepass()
{

    for (int i = 0; i < Height; i++)
    {
        printf("%d::", i + 1);
        for (int j = 0; j < Length; j++)
        {
            printf("%d\t", Postion[i][j]);
        }
        printf("\n");
    }
    sleep(3);
    system("cls");
}

int main()
{
    BlockPlacement(-1, -1);
    // timepass();
    GridPrinting();
}

bool isvalid(int *block, int len, int hor, int ver)
{
    // Directions[hor];
    for (int i = 0; i < len; i++)
    {
        if (block[i] == 1)
        {

            int row = ver;
            int col = hor + i;
            if (row < 0 || row >= Height || col < 0 || col >= Length)
            {
                return false;
            }
            if (Postion[row][col] == -1 || Postion[row][col] == 2)
            {

                return false;
            }
        }
    }
    return true;
}

void BlockPlacement(int HorPlacement, int virPlacement)
{

    // This zero have to be replace with randoem value gen
    char *Block = BlockMaker(0);
    if (HorPlacement == -1 && virPlacement == -1)
    {
        HorPlacement = Length / 2;
        virPlacement = 1;
    }
    int *demcount = ShapeSender(0, -1); // 0 is row , 1 is col

    for (int i = 0; i < demcount[0]; i++)
    {
        int *check = ShapeSender(0, i);
        int len = sizeof(check) / sizeof(int);
        if (!(isvalid(check, len, HorPlacement, virPlacement)))
        {
            // system("cls");
            fprintf(stderr, "Sorry Game Over\n");
            exit(0);
        }

        for (int j = 0; j < len; j++)
        {
            Postion[virPlacement][HorPlacement + j] = check[j];
        }
        virPlacement++;
    }
}

void GridPrinting()
{
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Length; j++)
        {
            int value = Postion[i][j];
            if (value == -1)
            {
                if (i == 0 || i == Height - 1)
                {
                    printf("-");
                }
                else
                {
                    printf("|");
                }
            }
            else
            {
                if (value == 0)
                {
                    printf(".");
                }
                else if (value == -2)
                {
                    printf("#");
                }
                else if (value == 1)
                {
                    printf("$");
                }
            }
        }
        printf("\n");
    }
}