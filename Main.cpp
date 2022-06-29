
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "String.h"

using namespace std;

int main()
{
    String str1;
    str1.SetName("Hello!");
    str1.Out("str1");

    String str2;
    str2.Input();
    str2.Out("str2");

    String str3(64);
    str3.Input();
    str3.Out("str3");

    String str4("world");
    str4.Out("str4");

    _getch();
    return 0;
}