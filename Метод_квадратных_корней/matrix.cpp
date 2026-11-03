#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <time.h>


void task_fill(std :: vector <std :: vector <double>> & m,  std::vector<double> & m2){
    m = {
        {   {9, 2, 3, 4, 2},
            {2, 9, 3, 5, 1},
            {3, 3, 8, 6, 4},
            {4, 5, 6, 8, 4},
            {2, 1, 4, 4, 7},}
    };
    m2 = {  32,
            40, 
            49, 
            52, 
            31 };
}

void rand_fill(std :: vector <std :: vector <double>> & m, std :: vector<double> & m2){
    srand(time(0));
    for (unsigned int i = 0; i < m.size(); i++){ 
        for (unsigned int j = 0; j < m.size(); j++)     
            m[i][j] = fabs((double)((rand() % 400) - 200) / 7.0);
        }
    for (unsigned int i = 0; i < m2.size(); i++)
        m2[i] = fabs((double)((rand() % 400) - 200) / 7.0);
    }

void printm(std :: vector <std :: vector <double>> m){
    for (unsigned int i = 0; i < m.size(); i++) {
        for (unsigned int j = 0; j < m.size(); j++) {
            printf("%9.3f ", m[i][j]);
        }
        puts("");
    }
}
