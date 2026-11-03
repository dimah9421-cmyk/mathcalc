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
    m = {{43, 3, 5, 3, 5, 75},
         {5, 49, 2, 2, 5, 118},
         {3, 4, 41, 5, 3, 147},
         {3, 1, 4, 24, 3, 68},
         {3, 4, 2, 2, 33, 54}
    };
}

void rand_fill(std :: vector <std :: vector <double>> & m){
    for (unsigned int i = 0; i < m.size(); i++) 
        for (unsigned int j = 0; j <= m.size(); j++)     
           m[i][j] = (double)((rand() % 400) - 200) / 7.0;

}

void printm(std :: vector <std :: vector <double>> m){
    for (unsigned int i = 0; i < m.size(); i++) {
        for (unsigned int j = 0; j <= m.size(); j++) {
            printf("%9.3f ", m[i][j]);
        }
        puts("");
    }
}
