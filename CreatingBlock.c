#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

int Shapes[10][3][2] = {
    {{0, 1},
     {1, 1},
     {0, 1}},
    {{1, 1},
     {0, 1},
     {0, 1}},
    {{1, 0},
     {1, 0},
     {1, 0}}};
char SideValue[2][4] = {"   ", "[#]"};

#define KEY_LEFT 75
#define KEY_RIGHT 77

int Movement[] = {-1, 0, 1};

int KeyboardInput()
{
    if (_kbhit())
    {
        int choice = _getch();
        if (choice == 'q' || choice == 'Q')
        {
            printf("Leaving the Program");
            exit(0);
        }
        if (choice == 0 || choice == 224)
        {

            int keyfinder = _getch();
            if (keyfinder == KEY_LEFT)
                return -1;
            if (keyfinder == KEY_RIGHT)
                return 1;
        }
    }
    return 0;
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
    // printf("%s", block);
    return block;
}

int main()
{

    // char SideValue[2][4] = { ".","[]"};ṇṇ
    srand(time(NULL));
    int index = rand() % 3;
    int value = 0;
    int tabspace = 0;
    while (1)
    {
        // printf("\033[H\033[J");
        for (int i = 0; i < value; i++)
        {
            printf("\n");
        }
        int tap = KeyboardInput();
        tabspace += tap;
        for (int i = 0 ;i < tabspace; i++)
        {
            printf("\t");
        }
        printf("%s",BlockMaker(index));
        sleep(1);
        value++;
    }

    // printf("%s", a);
    return 0;
}