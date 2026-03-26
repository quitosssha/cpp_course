#include <iostream>
#include <string.h>

using namespace std;

int len1(char *s);       // способ 1: через while
int len2(char *s);       // способ 2: через for и индекс
int len3(char *s);       // способ 3: через указатель
void strCopy(char *dst, char *src);
int strCompare(char *s1, char *s2);   // <0, ==0, >0
void strConcat(char *dst, char *src);

int main(void)
{
    char str1[100] = "qwerty";
    char str2[100] = "1234567890";

    cout << "Source strings:\n";
    cout << "str1 = " << str1 << "\nstr2 = " << str2 << "\n\n";

    // использование стандартных функций библиотеки string.h
    cout << "Default lib functions:\n";
    cout << "strlen(str1) = " << strlen(str1) << endl;
    cout << "strlen(str2) = " << strlen(str2) << endl;

    char tmp[200];
    strcpy(tmp, str1);
    strcat(tmp, str2);
    cout << "strcpy + strcat: \"" << tmp << "\"\n";
    cout << "strcmp(str1, str2) = " << strcmp(str1, str2) << "\n\n";

    // использование своих функций длины
    cout << "My functions:\n";
    cout << "len1(str1) = " << len1(str1)
         << ", len1(str2) = " << len1(str2) << endl;
    cout << "len2(str1) = " << len2(str1)
         << ", len2(str2) = " << len2(str2) << endl;
    cout << "len3(str1) = " << len3(str1)
         << ", len3(str2) = " << len3(str2) << "\n\n";

    // копирование
    char c1[100], c2[100];
    strCopy(c1, str1);
    strCopy(c2, str2);
    cout << "After strCopy:\n";
    cout << "c1 = " << c1 << "\n";
    cout << "c2 = " << c2 << "\n\n";

    // сравнение
    cout << "Comparison strCompare(c1, c2) = " << strCompare(c1, c2) << "\n\n";

    // конкатенация
    strConcat(c1, c2);
    cout << "After strConcat(c1, c2):\n";
    cout << "c1 = " << c1 << "\n";
    cout << "c2 = " << c2 << "\n\n";

    // пример массива строк
    char arr[3][50] = { "one", "two", "three" };
    cout << "Strings array:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "] = " << arr[i]
             << ", len1 = " << len1(arr[i]) << endl;
    }

    return 0;
}

int len1(char *s) {
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int len2(char *s) {
    int len = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        len++;
    return len;
}

int len3(char *s) {
    int len = 0;
    char *p = s;
    while (*p != '\0') {
        len++;
        p++;
    }
    return len;
}

void strCopy(char *dst, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int strCompare(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    int result = (unsigned char)s1[i] - (unsigned char)s2[i];
    if (result > 0)
        return 1;
    if (result < 0)
        return -1;
    return 0;
}

void strConcat(char *dst, char *src) {
    int i = 0;
    while (dst[i] != '\0') i++;     // найти конец dst
    int j = 0;
    while (src[j] != '\0') {
        dst[i] = src[j];
        i++; j++;
    }
    dst[i] = '\0';
}