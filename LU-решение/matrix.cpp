#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

int variors(){
    int opt = 0;
    printf("Выберите способ ввода элементов матрицы \n(1 - по заданию, 0 - генирация псевдослучайных чисел)\n");
    scanf("%d",&opt);
    return opt;
}

void task_fill(std :: vector <std :: vector <double>> & m){
    m = {
        {6, 7, 4, 7, 8, 32},
        {8, 4, 4, 5, 5, 26},
        {6, 5, 2, 9, 5, 27},
        {3, 5, 1, 8, 5, 22},
        {8, 8, 5, 9, 5, 35}
    };
}

void rand_fill(std :: vector <std :: vector <double>> & m){
    srand(time(0));
    for (unsigned int i = 0; i < m.size(); i++) 
    for (unsigned int j = 0; j <= m.size(); j++)     
    m[i][j] = (double)((rand() % 400) - 200) / 7.0;
}

void matrix_filling (std :: vector <std :: vector <double>> & m ){
    int opt = variors();
    if (opt)    task_fill(m);
    else        rand_fill(m);
}

void printm(std :: vector <std :: vector <double>> m){
    double E = 0.0001;
    for (unsigned int i = 0; i < m.size(); i++) {
        if (m[i][m.size()] < E){
            for (unsigned int j = 0; j < m.size(); j++)
            printf("%9.2f ", m[i][j]);
        }
        else if (m[i][m.size()] > E)
            for (unsigned int j = 0; j <= m.size(); j++)
                printf("%9.2f ", m[i][j]);
        puts("");
    }
}
