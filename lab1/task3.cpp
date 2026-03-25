#include <iostream>
using namespace std;

int main (void)
{
    int a=2, b=5;

    pair<int, int> swap1 (int, int);
    void swap2 (int*, int*);
    void swap3 (int&, int&);

    cout << "before swapping: a= "<< a <<"b="<<b<< endl;

    pair<int, int> swapResult = swap1 (a, b);
    a = swapResult.first;
    b = swapResult.second;
    cout << "after swapping 1: a= "<< a <<"b="<< b << endl;

    swap2 (&a, &b);
    cout << "after swapping 2: a= "<< a <<"b="<< b << endl;

    swap3 (a, b);
    cout << "after swapping 3: a= "<< a <<"b="<< b << endl;

    return 0;
}

pair<int, int> swap1 (int x, int y) // передаются копии переменных a и b, изменения в функции не влияют на переданные переменные
{
    return make_pair(y, x);
}

void swap2 (int* x, int* y) // передаются указатели на переменные a и b, изменения в функции влияют на переданные переменные через разыменование указателей
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap3 (int& x, int& y) // передаются ссылки на переменные a и b, изменения в функции напрямую влияют на переданные переменные
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}