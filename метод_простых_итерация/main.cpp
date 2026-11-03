#include <stdio.h>
#include <vector>

#include "matrix.h"
int main(){
    std::vector <std::vector<double>> a;
    std::vector <double> x,xx;

    int n = 0;
    int f = -1;
    
    while (1){
        puts("Ввдите 1 - если желаете идти по зданию\nВведите 0 - если котите задать матрицу рандомными значениями");
        scanf("%d",&f);
        if (f == 1 || f == 0)
            break;
    }

    switch (f){
    case 1:
        task_fill(a);
        n = a.size();
        break;
    case 0:
        puts("Введите количество переменных");
        scanf("%d",&n);
        a.resize(n, std::vector<double>(n + 1));
        rand_fill(a);
        break;
    }

    printm(a);

    x.resize(n);
    xx.resize(n);
    double e = 0.00001;
    int k = 0;
    do {
        k++;

        for (int i = 0; i < n; i++){
            xx[i] = a[i][n];
            for (int j = 0; j < n; j ++)
                if (j != i){
                    xx[i] = xx[i] - a[i][j] * x[j];
                }
            xx[i] = xx[i] / a[i][i];
        }
        int count = 0;
        printf("\n%d итерация:\n", k);
        for (int i = 0; i < n; i++){
            printf("%9.2f",xx[i]);
            if (abs(x[i] - xx[i]) < e)
                count ++;
            x[i] = xx[i];    
        }
        if (count == n)
            break;
    } while (1);
}