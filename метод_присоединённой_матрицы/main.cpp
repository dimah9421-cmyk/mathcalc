#include <stdio.h>
#include <vector>

#include "matrix.h"

int main(){
    std::vector<std::vector<double>> B;
    
    int f = -1;
    while (1){
        puts("Введите свой выбор (1 - по заданию, 0 - рандобное заполнение матрицы)");
        scanf("%d", &f);
        if (f == 1 || f == 0)
        break;
    }
    
    int n = 0;
    switch (f){
        case 1:
        task_fill(B);
        n = B.size();
        break;
    case 0:
        puts("Введите количество переменных СЛУ");
        scanf("%d",&n);
        B.resize(n, std::vector<double>(2*n));
        rand_fill(B);
        break;
    default:
        break;
    }

    printm(B);

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++)
            for (int j = k + 1; j < 2*n; j++)
                if (i != k)
                    B[i][j] = (B[i][j] * B[k][k]
                        - B[k][j] * B[i][k]) / B[k][k];
        for (int i = 0; i < n; i++)
            if (i != k)
            B[i][k] = 0;
        for (int j = 2*n - 1; j >= k; j--)
            B[k][j] = B[k][j] / B[k][k];
        
        printf("\nматрица после %d-го действия\n", k + 1);
        printm(B);
    }
}