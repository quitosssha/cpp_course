#include <iostream>
#include <conio.h>

using namespace std;

void printArr(int a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

// сортировка методом мини-макса
void minMaxSort(int a[], int n) {
    int i, j, imin, t;
    for (i = 0; i < n - 1; ++i) {
        imin = i;
        for (j = i + 1; j < n; ++j)
            if (a[j] < a[imin])
                imin = j;
        if (imin == i) 
            continue; // уже на месте
        t = a[i];
        a[i] = a[imin];
        a[imin] = t;
    }
}

// сортировка пузырьком
void bubbleSort(int a[], int n) {
    bool changed = true;
    for (int pass = 0; pass < n - 1 && changed; ++pass) {
        changed = false;
        for (int i = 0; i < n - 1 - pass; ++i) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                changed = true;
            }
        }
    }
}

// разбиение массива для быстрой сортировки
int partitionArr(int a[], int left, int right, bool descending) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        if (!descending) {
            // по возрастанию
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
        } else {
            // по убыванию
            while (a[i] > pivot) ++i;
            while (a[j] < pivot) --j;
        }
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++i;
            --j;
        }
    }
    return i;
}

// быстрая сортировка
void quickSort(int a[], int left, int right, bool descending = false) {
    if (left >= right) return;
    int index = partitionArr(a, left, right, descending);
    quickSort(a, left, index - 1, descending);
    quickSort(a, index, right, descending);
}

// сортировка: чётные по возрастанию, нечётные по убыванию
void sortEvenAscOddDesc(int a[], int n) {
    // 1. Пройти массив и отдельно собрать значения четных и нечетных элементов
    // 2. Отсортировать массив чётных по возрастанию, массив нечётных по убыванию.
    // 3. Вторым проходом по исходному массиву на месте каждого чётного элемента 
    //      брать следующий элемент из отсортированного массива чётных, 
    //      на месте каждого нечётного — следующий из отсортированного массива нечётных.

    int even[n]; // размер n будет в худшем случае, если все элементы четные
    int evenLen = 0;
    int odd[n];
    int oddLen = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] % 2 == 0){
            even[evenLen] = a[i];
            evenLen++;
        }
        else{
            odd[oddLen] = a[i];
            oddLen++;
        }
    }
    
    quickSort(even, 0, evenLen - 1, false);
    quickSort(odd, 0, oddLen - 1, true);

    int evenIdx = 0;
    int oddIdx = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] % 2 == 0){
            a[i] = even[evenIdx];
            evenIdx++;
        }
        else{
            a[i] = odd[oddIdx];
            oddIdx++;
        }
    }
}

// сортировка по возрастанию на интервале индексов [n1, n2]
void sortSubAsc(int a[], int n1, int n2) {
    int left = n1;
    int right = n2;
    for (int i = left; i < right; ++i) {
        int imin = i;
        for (int j = i + 1; j <= right; ++j)
            if (a[j] < a[imin])
                imin = j;
        int t = a[i];
        a[i] = a[imin];
        a[imin] = t;
    }
}

// сортировка по убыванию на интервале индексов [n1, n2]
void sortSubDesc(int a[], int n1, int n2) {
    int left = n1;
    int right = n2;
    for (int i = left; i < right; ++i) {
        int imax = i;
        for (int j = i + 1; j <= right; ++j)
            if (a[j] > a[imax])
                imax = j;
        int t = a[i];
        a[i] = a[imax];
        a[imax] = t;
    }
}

int main() {
    int srcArr[] = {2, 5, 8, 1, 4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(srcArr) / sizeof(int);

    cout << "Source array:\n";
    printArr(srcArr, n);

    // 1. метод мини-макса
    int a1[n];
    for (int i = 0; i < n; ++i) a1[i] = srcArr[i];
    minMaxSort(a1, n);
    cout << "\nMinMax (ascending):\n";
    printArr(a1, n);

    // 2. пузырёк
    int a2[n];
    for (int i = 0; i < n; ++i) a2[i] = srcArr[i];
    bubbleSort(a2, n);
    cout << "\nBubble (ascending):\n";
    printArr(a2, n);

    // 3. быстрая сортировка
    int a3[n];
    for (int i = 0; i < n; ++i) a3[i] = srcArr[i];
    quickSort(a3, 0, n - 1);
    cout << "\nQuicksort (ascending):\n";
    printArr(a3, n);

    int a3d[n];
    for (int i = 0; i < n; ++i) a3d[i] = srcArr[i];
    quickSort(a3d, 0, n - 1, true);
    cout << "\nQuicksort (descending):\n";
    printArr(a3d, n);

    // 4. чётные вверх, нечётные вниз
    int a4[n];
    for (int i = 0; i < n; ++i) a4[i] = srcArr[i];
    sortEvenAscOddDesc(a4, n);
    cout << "\nEven ascending, odd descending:\n";
    printArr(a4, n);

    // 5. интервал [n1, n2] по возрастанию
    int a5[n];
    for (int i = 0; i < n; ++i) a5[i] = srcArr[i];
    sortSubAsc(a5, 2, n - 2);
    cout << "\nInterval [n1, n2] ascending:\n";
    printArr(a5, n);

    // 6. интервал [n1, n2] по убыванию
    int a6[n];
    for (int i = 0; i < n; ++i) a6[i] = srcArr[i];
    sortSubDesc(a6, 2, n - 2);
    cout << "\nInterval [n1, n2] descending:\n";
    printArr(a6, n);

    //getch();
    return 0;
}
