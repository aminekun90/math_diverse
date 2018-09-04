#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>

#include "menu.h"

using namespace std;

int snaky()
{

    srand(time(NULL));
	system("title Snake");
     slapsh_screen();
    return EXIT_SUCCESS;
}
