#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    char str1[100] = "Hello";
    char str2[100] = "World";
    char buffer[200];

    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    cout << "strlen(str1) = " << strlen(str1) << endl;
    cout << "strlen(str2) = " << strlen(str2) << endl << endl;

    strcpy(buffer, str1);
    cout << "After strcpy(buffer, str1): buffer = \"" << buffer << "\"\n\n";

    strcat(buffer, " ");
    strcat(buffer, str2);
    cout << "After strcat(buffer, \" \") and strcat(buffer, str2):\n";
    cout << "buffer = \"" << buffer << "\"\n\n";

    cout << "strcmp(str1, str2) = " << strcmp(str1, str2) << endl;
    cout << "strcmp(str1, \"Hello\") = " << strcmp(str1, "Hello") << endl;
    cout << "strcmp(str2, \"World\") = " << strcmp(str2, "World") << endl;

    return 0;
}