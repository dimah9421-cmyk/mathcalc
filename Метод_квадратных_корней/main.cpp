// Вариант - 19

#include <stdio.h>
#include <vector>

#include "matrix.h"

int main(){
    std :: vector<std :: vector<double>> A, l, lt;
    std :: vector<double> B, x, y;

    puts("1 - идти по заданию, 0 - считать рандомную матрицу");
    int f = 0;
    scanf("%d", &f);
    int n = 5;
    if (f == 1){
        task_fill(A, B);
        
        puts("A:");
        printm(A);

        puts("B:");
        for (unsigned int i = 0; i < B.size(); i++)
            printf("    %.2f\n", B[i]);
    }
    else if (f == 0){
        
        puts("Введите количество переменных");
        
        scanf("%d", &n);

        A.resize(n);
        B.resize(n);
        for (unsigned int i = 0; i < n; i++){
            A[i].resize(n);
        }
        
        rand_fill(A, B);

        puts("A:");
        printm(A);

        puts("B:");
        for(int i = 0; i < n; i++)
            printf("    %.2f\n", B[i]);

    }
    l.resize(n);
    lt.resize(n);
    for (int i = 0; i < n; i++){
        l[i].resize(n);
        lt[i].resize(n);
    }
    l[0][0] = sqrt(A[0][0]);

    for (int i = 0; i < n; i ++)
        l[i][0] = A[i][0] / l[0][0];
    
    for (int k = 0; k < n; k ++){
        double sum_sqrt = 0;
        for (int i = 0; i < k; i ++){
            sum_sqrt = sum_sqrt + pow(l[k][i], 2);
        }
        l[k][k] = sqrt(A[k][k] - sum_sqrt);
        for (int i = k + 1; i < n; i ++){
            double pairsum = 0; 
            for (int m = 0; m < k; m++)
                pairsum = pairsum + l[i][m] * l[k][m];
            l[i][k] = (A[i][k] - pairsum) / l[k][k];
            }
        }

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            lt[i][j] = l[j][i];
    
    puts("матрица L:");
    printm(l);
    
    puts("матрица Lt:");
    printm(lt);
    
    y.resize(n);
    y[0] = B[0] / l[0][0];
    for (int i = 1; i < n; i++){
        y[i] = B[i];
        for (int m = 0; m < i; m++){
            y[i] = y[i] - l[i][m] * y[m];          
        }
        y[i] = y[i] / l[i][i];
    }
    
    x.resize(n);
    x[n - 1] = y[n - 1] / lt[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--){
        x[i] = y[i];
        for (int m = i + 1; m < n; m++)
            x[i] = x[i] - lt[i][m] * x[m];
        x[i] = x[i] / lt[i][i];       
    }
    
    puts("x: ");
    for (int i = 0; i < n; i++)
        printf("%.2f\n", x[i]);
    }