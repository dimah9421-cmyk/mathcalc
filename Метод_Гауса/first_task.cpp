#include <stdio.h>
#include <vector>

#include "matrix.h"

int main() {

    std::vector<std::vector<double>> matrix;

    unsigned int n = 0;

    printf("Введите количество переменных\n(чтобы выполнить задание необходимо задать 5)\nn = ");
    scanf("%u", &n);

    matrix.resize(n);

    for (unsigned int i = 0; i < n; i++)
        matrix[i].resize(n + 1);

    matrix_filling(matrix);

    puts("Начальная матрица:");
    printm(matrix);

    const double E = 0.0001;

    for (unsigned int k = 0; k < n; k++) {

        if (abs(matrix[k][k]) < E) {
            for (unsigned int i = k + 1; i < n; i++) {
                if (abs(matrix[i][k]) >= E) {
                    swap(matrix[k], matrix[i]);
                    break;
                }
            }
        }

        for (unsigned int i = k + 1; i < n; i++) {
            for (unsigned int j = k + 1; j <= n; j++) {
                matrix[i][j] = (matrix[i][j] * matrix[k][k]
                    - matrix[i][k] * matrix[k][j]) / matrix[k][k];
            }
        }

        for (unsigned int i = k + 1; i < n; i++)
            matrix[i][k] = 0;

        for (int j = n; j >= (int)k; j--)
            matrix[k][j] /= matrix[k][k];
    }

    puts("Изменённая матрица:");
    printm(matrix);

    std::vector<double> x(n);

    for (int k = n - 1; k >= 0; k--) {
        double sum = 0;
        for (unsigned int i = k + 1; i < n; i++){
            sum += matrix[k][i] * x[i];
            printf("%f ", x[i]);}
        x[k] = (matrix[k][n] - sum);
    }

    for (unsigned int i = 0; i < n; i++)
        printf("x%d = %.3lf\n", i + 1, x[i]);
    return 0;
}
    