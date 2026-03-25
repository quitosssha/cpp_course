#include <iostream>
using namespace std;

int power (int x, int n)
{
    int p=1;
    for(int i=1; i<n; i++) 
        p*=x;
    return p;
}

int main (int argc, char* argv[])
{
    // argc - количество аргументов командной строки, argv - массив строковых аргументов
    // argv[0] - имя исполняемого файла, argv[1] - первое число, argv[2] - степень
    if (argc != 3) {
        cout << "Error! Use: " << argv[0] << " <number> <exponent>" << endl;
        cout << "Example: " << argv[0] << " 2 5" << endl;
        return 1;
    }

    // Преобразуем строковые аргументы в числа
    int base = atoi(argv[1]);
    int exponent = atoi(argv[2]);
    
    int result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}