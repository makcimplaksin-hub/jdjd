
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void createMatrix(vector<vector<int>>& matrix, int n) {
    srand(time(nullptr));
    matrix.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = rand() % 100 + 1;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (auto val : row)
            cout << val << "\t";
        cout << "\n";
    }
    cout << endl;
}

int sumMainDiagonal(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (int i = 0; i < (int)matrix.size(); ++i)
        sum += matrix[i][i];
    return sum;
}

void swapMaxAboveBelowDiagonal(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();

    int maxAbove = INT_MIN;
    int rAbove = -1, cAbove = -1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (matrix[i][j] > maxAbove) {
                maxAbove = matrix[i][j];
                rAbove = i;
                cAbove = j;
            }

    int maxBelow = INT_MIN;
    int rBelow = -1, cBelow = -1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (matrix[i][j] > maxBelow) {
                maxBelow = matrix[i][j];
                rBelow = i;
                cBelow = j;
            }

    if (rAbove != -1 && rBelow != -1)
        swap(matrix[rAbove][cAbove], matrix[rBelow][cBelow]);
}

void subtractMinFromCols(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();

    int minVal = matrix[0][0];
    int minCol = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minCol = j;
            }

    for (int j = minCol + 1; j < n; ++j)
        for (int i = 0; i < n; ++i)
            matrix[i][j] -= minVal;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    vector<vector<int>> matrix;
    createMatrix(matrix, n);

    cout << "Созданная матрица:\n";
    printMatrix(matrix);

    while (true) {
        cout << "Меню:\n";
        cout << "1 - Сумма элементов главной диагонали\n";
        cout << "2 - Поменять местами максимальные элементы выше и ниже главной диагонали\n";
        cout << "3 - Из элементов столбцов, расположенных после столбца с минимальным элементом, вычесть этот минимальный элемент\n";
        cout << "0 - Выйти\n";
        cout << "Выберите пункт: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Сумма элементов главной диагонали: " << sumMainDiagonal(matrix) << "\n\n";
        }
        else if (choice == 2) {
            swapMaxAboveBelowDiagonal(matrix);
            cout << "Матрица после обмена максимальных элементов:\n";
            printMatrix(matrix);
        }
        else if (choice == 3) {
            subtractMinFromCols(matrix);
            cout << "Матрица после вычитания минимального элемента из нужных столбцов:\n";
            printMatrix(matrix);
        }
        else if (choice == 0) {
            cout << "Выход.\n";
            break;
        }
        else {
            cout << "Неверный выбор, попробуйте снова.\n\n";
        }
    }

    return 0;
}
