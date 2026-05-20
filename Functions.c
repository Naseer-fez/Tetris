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

