#define PR(x) printf("x=%u, *x=%d, &x=%u\n",x,*x,&x)
#include <stdio.h>

template<typename T>
void printPtr(const T* ptr, const char* ptrName) {
    printf("%s = %p, *%s = %d, &%s = %p, size = %d bytes\n", 
           ptrName, 
           ptr, // адрес указателя
           ptrName, 
           *ptr, // значение по адресу
           ptrName,
           &ptr, // адрес переменной указателя
           sizeof(T)); // размер переменной
}

int main (void)
{
    int arr[]={100, 200, 300};
    
    int *ptr1 = arr; // ptr1 указывает на arr[0] = 100
    printPtr(ptr1, "ptr1");
    ptr1++; // ptr1 указывает на arr[1] = 200
    printPtr(ptr1, "ptr1");

    int *ptr2 = &arr[2]; // ptr2 указывает на arr[2] = 300
    printPtr(ptr2, "ptr2");
    ++ptr2; // ptr2 указывает на arr[3] (за пределами массива)
    printPtr(ptr2, "ptr2"); // по указанному адресу будет лежать мусорное значение

    printf("ptr2-ptr1 = %p - %p = %u\n", ptr2, ptr1, ptr2-ptr1);
    // ptr2-ptr1 = (адрес ptr2 - адрес ptr1) / sizeof(int) = 3 - 1 = 2

    return 0;
}