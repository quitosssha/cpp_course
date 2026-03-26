#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    char *str1, *str2;

    // выделение памяти (как в методичке)
    str1 = (char*)malloc(100);
    str2 = (char*)calloc(100, sizeof(char)); // сразу обнулит память

    // инициализация строк
    strcpy(str1, "hello");
    strcpy(str2, "world");

    cout << "str1 = " << str1 << ", strlen = " << strlen(str1) << endl;
    cout << "str2 = " << str2 << ", strlen = " << strlen(str2) << endl;

    // конкатенация в динамической строке
    strcat(str1, str2);
    cout << "After strcat(str1, str2): str1 = " << str1 << endl;

    // массив строк (массив указателей)
    const int N = 3;
    char *arr[N];
    for (int i = 0; i < N; ++i)
        arr[i] = (char*)malloc(50);

    strcpy(arr[0], "one");
    strcpy(arr[1], "two");
    strcpy(arr[2], "three");

    cout << "\nArray of dynamic strings:\n";
    for (int i = 0; i < N; ++i) {
        cout << "arr[" << i << "] = " << arr[i]
             << ", dlina1 = " << strlen(arr[i]) << endl;
    }

    // освобождение памяти
    free(str1);
    free(str2);
    for (int i = 0; i < N; ++i)
        free(arr[i]);

    return 0;
}