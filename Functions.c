// #include "Allimports.h"
// #include "Functions.h"
// #include <conio.h>
#include "Functions.h"

int KeyboardInput()
{
    if (_kbhit())
    {
        int choice = _getch();
        if (choice == 'q' || choice == 'Q')
        {
            return 2;
        }
        if (choice == 0 || choice == 224)
        {

            int keyfinder = _getch();
            if (keyfinder == 75)
                return -1;
            if (keyfinder == 77)
                return 1;
        }
    }
    return 0;
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