#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 5

void fillMatrix(float m[N][N]) {
    srand(time(nullptr));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            m[i][j] = rand() / 10.0f;
}

void printMatrix(float m[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
}

// минимум и максимум всей матрицы
float minMatrix(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

float maxMatrix(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

// нижнетреугольная часть
float maxLower(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

float minLower(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

// верхнетреугольная часть
float maxUpper(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

float minUpper(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

// главная диагональ (i == j)
float minMainDiag(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; ++i)
        if (m[i][i] < mn) mn = m[i][i];
    return mn;
}

float maxMainDiag(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; ++i)
        if (m[i][i] > mx) mx = m[i][i];
    return mx;
}

// второстепенная диагональ (i + j == N - 1)
float minSecDiag(float m[N][N]) {
    float mn = m[0][N-1];
    for (int i = 0; i < N; ++i) {
        int j = N - 1 - i;
        if (m[i][j] < mn) mn = m[i][j];
    }
    return mn;
}

float maxSecDiag(float m[N][N]) {
    float mx = m[0][N-1];
    for (int i = 0; i < N; ++i) {
        int j = N - 1 - i;
        if (m[i][j] > mx) mx = m[i][j];
    }
    return mx;
}

// среднее по всей матрице
float avgMatrix(float m[N][N]) {
    float s = 0.0f;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            s += m[i][j];
    return s / (N * N);
}

// среднее по нижней/верхней треугольным частям
float avgLower(float m[N][N]) {
    float s = 0.0f;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j) {
            s += m[i][j];
            ++cnt;
        }
    return s / cnt;
}

float avgUpper(float m[N][N]) {
    float s = 0.0f;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            s += m[i][j];
            ++cnt;
        }
    return s / cnt;
}

// суммы строк и столбцов
void sumRows(float m[N][N], float sumRow[N]) {
    for (int i = 0; i < N; ++i) {
        sumRow[i] = 0.0f;
        for (int j = 0; j < N; ++j)
            sumRow[i] += m[i][j];
    }
}

void sumCols(float m[N][N], float sumCol[N]) {
    for (int j = 0; j < N; ++j) {
        sumCol[j] = 0.0f;
        for (int i = 0; i < N; ++i)
            sumCol[j] += m[i][j];
    }
}

// минимум/максимум по строкам и столбцам
void minRows(float m[N][N], float mnRow[N]) {
    for (int i = 0; i < N; ++i) {
        mnRow[i] = m[i][0];
        for (int j = 1; j < N; ++j)
            if (m[i][j] < mnRow[i]) mnRow[i] = m[i][j];
    }
}

void maxRows(float m[N][N], float mxRow[N]) {
    for (int i = 0; i < N; ++i) {
        mxRow[i] = m[i][0];
        for (int j = 1; j < N; ++j)
            if (m[i][j] > mxRow[i]) mxRow[i] = m[i][j];
    }
}

void minCols(float m[N][N], float mnCol[N]) {
    for (int j = 0; j < N; ++j) {
        mnCol[j] = m[0][j];
        for (int i = 1; i < N; ++i)
            if (m[i][j] < mnCol[j]) mnCol[j] = m[i][j];
    }
}

void maxCols(float m[N][N], float mxCol[N]) {
    for (int j = 0; j < N; ++j) {
        mxCol[j] = m[0][j];
        for (int i = 1; i < N; ++i)
            if (m[i][j] > mxCol[j]) mxCol[j] = m[i][j];
    }
}

// средние по строкам и столбцам
void avgRows(float m[N][N], float avgRow[N]) {
    for (int i = 0; i < N; ++i) {
        float s = 0.0f;
        for (int j = 0; j < N; ++j)
            s += m[i][j];
        avgRow[i] = s / N;
    }
}

void avgCols(float m[N][N], float avgCol[N]) {
    for (int j = 0; j < N; ++j) {
        float s = 0.0f;
        for (int i = 0; i < N; ++i)
            s += m[i][j];
        avgCol[j] = s / N;
    }
}

// суммы нижней и верхней треугольных частей
float sumLower(float m[N][N]) {
    float s = 0.0f;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            s += m[i][j];
    return s;
}

float sumUpper(float m[N][N]) {
    float s = 0.0f;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            s += m[i][j];
    return s;
}

// элемент, ближайший к среднему значению матрицы
float closestToAvg(float m[N][N]) {
    float avg = avgMatrix(m);
    float best = m[0][0];
    float bestDiff = fabs(m[0][0] - avg);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            float d = fabs(m[i][j] - avg);
            if (d < bestDiff) {
                bestDiff = d;
                best = m[i][j];
            }
        }
    return best;
}

int main() {
    float m[N][N];
    fillMatrix(m);
    cout << "Matrix:" << endl;
    printMatrix(m);

    cout << "\nminMatrix = " << minMatrix(m) << endl;
    cout << "maxMatrix = " << maxMatrix(m) << endl;

    cout << "maxLower = " << maxLower(m) << endl;
    cout << "minLower = " << minLower(m) << endl;
    cout << "maxUpper = " << maxUpper(m) << endl;
    cout << "minUpper = " << minUpper(m) << endl;

    cout << "minMainDiag = " << minMainDiag(m) << endl;
    cout << "maxMainDiag = " << maxMainDiag(m) << endl;
    cout << "minSecDiag = " << minSecDiag(m) << endl;
    cout << "maxSecDiag = " << maxSecDiag(m) << endl;

    cout << "avgMatrix = " << avgMatrix(m) << endl;
    cout << "avgLower = " << avgLower(m) << endl;
    cout << "avgUpper = " << avgUpper(m) << endl;

    float sumR[N], sumC[N], mnR[N], mxR[N], mnC[N], mxC[N], avgR[N], avgC[N];
    sumRows(m, sumR);
    sumCols(m, sumC);
    minRows(m, mnR);
    maxRows(m, mxR);
    minCols(m, mnC);
    maxCols(m, mxC);
    avgRows(m, avgR);
    avgCols(m, avgC);

    cout << "\nRow sums: ";
    for (int i = 0; i < N; ++i) cout << sumR[i] << ' ';
    cout << "\nCol sums: ";
    for (int j = 0; j < N; ++j) cout << sumC[j] << ' ';

    cout << "\nRow mins: ";
    for (int i = 0; i < N; ++i) cout << mnR[i] << ' ';
    cout << "\nRow maxs: ";
    for (int i = 0; i < N; ++i) cout << mxR[i] << ' ';

    cout << "\nCol mins: ";
    for (int j = 0; j < N; ++j) cout << mnC[j] << ' ';
    cout << "\nCol maxs: ";
    for (int j = 0; j < N; ++j) cout << mxC[j] << ' ';

    cout << "\nRow avgs: ";
    for (int i = 0; i < N; ++i) cout << avgR[i] << ' ';
    cout << "\nCol avgs: ";
    for (int j = 0; j < N; ++j) cout << avgC[j] << ' ';

    cout << "\n\nsumLower = " << sumLower(m) << endl;
    cout << "sumUpper = " << sumUpper(m) << endl;
    cout << "closestToAvg = " << closestToAvg(m) << endl;

    return 0;
}
