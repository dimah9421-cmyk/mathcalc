#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

void task_fill(std :: vector <std :: vector <double>> & m){
    m = {   {9, 2, 2, 1, 7},
            {2, 4, 3, 3, 2},
            {2, 3, 8, 1, 3},
            {1, 3, 1, 4, 2},
            {7, 2, 3, 2, 7}};
}


void size_matrix(std :: vector <std:: vector <double>> & m){
    int n = 0;
    puts("введите размерность матрицы");
        scanf("%d", &n);
    m.resize(n);
    for (int i = 0; i < n; i ++)
        m[i].resize(n);
}

void person_fill(std:: vector <std :: vector<double>> & m){
    size_matrix(m);
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m.size(); j++){
            printf("a[%d,%d]",i + 1, j + 1);
            double p = 0;
            scanf("%f", &p);
            m[i][j] = p;
        }
    
}

void rand_fill(std :: vector <std :: vector <double>> & m){
    size_matrix(m);
    srand(time(0));
    for (unsigned int i = 0; i < m.size(); i++) 
        for (unsigned int j = 0; j < m.size(); j++)     
           m[i][j] = (double)((rand() % 400) - 200) / 7.0;

}

void printm(std :: vector <std :: vector <double>> m){
    for (unsigned int i = 0; i < m.size(); i++) {
        for (unsigned int j = 0; j < m.size(); j++) {
            printf("%9.3f ", m[i][j]);
        }
        puts("");
    }
}
