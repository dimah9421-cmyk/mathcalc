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
        {6.57, 6.82, 8.92, 3.73, 2.93, 8.01},
        {5.2 , 0.97, 7.97, 2.98, 2.46, 7.12},
        {2.37, 2.7,  4.93, 2.57, 3.2,  9.25},
        {7.52, 8.33, 1.01, 1.81, 1.15, 9.54},
        {3.55, 8.89, 0.28, 9.16, 3.24, 4.07}
    };
}

void rand_fill(std :: vector <std :: vector <double>> & m){
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
    for (unsigned int i = 0; i < m.size(); i++) {
        for (unsigned int j = 0; j <= m.size(); j++) {
            printf("%9.3f ", m[i][j]);
        }
        puts("");
    }
}
