#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "matrix.h"

int main(){
    srand(time(NULL));

    std::vector<std::vector<double>> a;

    unsigned int n = 0;
    
    printf("Введите количество переменных n = ");
    scanf("%u", &n);

    a.resize(n);

    for (unsigned int i = 0; i < n; i++)
        a[i].resize(n + 1);

    matrix_filling(a);
    puts("Начальная матрица:");
    printm(a);
  
    double E = 0.0001;

    for (unsigned int k = 0; k < n; k++){

        if (abs(a[k][k]) < E)
            for (unsigned int i = k + 1; i < n; i++)
                if (abs(a[i][k]) >= E){
                swap(a[k], a[i]);
                break;
            }
        
        for (unsigned int i = 0; i < n; i++)
            for (unsigned int j = k + 1; j <= n; j++)
                if (i != k)
                    a[i][j] = (a[i][j] * a[k][k] - a[i][k] *
                    a[k][j]) / a[k][k];
                
        for (unsigned int i = 0; i < n; i++)
            if (i != k) a[i][k] = 0;
        
        for (int j = n; j >= (int)k; j--)
            a[k][j] = a[k][j] / a[k][k];
    }
    
    puts("Изменённвя матрица:");
    printm(a);

    std::vector<double> x;
    x.resize(n);
    for (int k = n - 1; k >= 0; k--) {
        x[k] = a[k][n];
    }
    for (unsigned int i = 0; i < n; i++)
        printf("x%d = %.3lf\n", i + 1, x[i]);
}
// x1 = 1.247
// x2 = -0.196
// x3 = -0.729
// x4 = -1.366
// x5 = 4.353