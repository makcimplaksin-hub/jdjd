#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n, choice;

    cout << "Размер матрицы: ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
        }
    }

    do {
        cout << "\n1. Вывод\n2. Сумма диаг.\n3. Обмен max\n4. Вычесть min\n0. Выход\nВыбор: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) cout << a[i][j] << "\t";
                cout << endl;
            }
        }

        else if (choice == 2) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += a[i][i];
            cout << "Сумма: " << sum << endl;
        }

        else if (choice == 3) {
            int maxUp = a[0][1], maxDown = a[1][0], riUp = 0, cjUp = 1, riDown = 1, cjDown = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i < j && a[i][j] > maxUp) {
                        maxUp = a[i][j]; riUp = i; cjUp = j;
                    }
                    if (i > j && a[i][j] > maxDown) {
                        maxDown = a[i][j]; riDown = i; cjDown = j;
                    }
                }
            }

            swap(a[riUp][cjUp], a[riDown][cjDown]);
            cout << "Обмен выполнен\n";
        }

        else if (choice == 4) {
            int minVal = a[0][0], minCol = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] < minVal) {
                        minVal = a[i][j];
                        minCol = j;
                    }
                }
            }

            if (minCol < n - 1) {
                for (int j = minCol + 1; j < n; j++) {
                    for (int i = 0; i < n; i++) {
                        a[i][j] -= minVal;
                    }
                }
                cout << "Вычтено " << minVal << " из столбцов > " << minCol << endl;
            }
        }

    } while (choice != 0);

    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;

    return 0;
}