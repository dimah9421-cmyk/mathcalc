#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <time.h>


void task_fill(std :: vector <std :: vector <double>> & m){
    m = {
        {{5, 3, 7, 3, 2, 1, 0, 0, 0, 0},
         {4, 2, 8, 6, 7, 0, 1, 0, 0, 0},
         {1, 3, 6, 9, 2, 0, 0, 1, 0, 0},
         {2, 2, 6, 3, 6, 0, 0, 0, 1, 0},
         {4, 3, 8, 7, 4, 0, 0, 0, 0, 1}}
    };

}

void rand_fill(std :: vector <std :: vector <double>> & m){
    srand(time(0));
    for (unsigned int i = 0; i < m.size(); i++) 
        for (unsigned int j = 0; j < m.size(); j++)     
            m[i][j] = fabs((double)((rand() % 400) - 200) / 7.0);
        
    for (unsigned int i = 0; i < m.size(); i++)
        for (unsigned int j = m.size(); j < 2*m.size(); j++){
            m[i][j] = 0;
            if (m.size()+i == j)
                m[i][j] = 1;
            }
    }

void printm(std :: vector <std :: vector <double>> m){
    for (unsigned int i = 0; i < m.size(); i++) {
        for (unsigned int j = 0; j < m[i].size(); j++) {
            printf("%9.2f ", m[i][j]);
        }
        puts("");
    }
}
