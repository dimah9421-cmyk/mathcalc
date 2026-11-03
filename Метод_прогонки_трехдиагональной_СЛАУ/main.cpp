#include <stdio.h>
#include <vector>

int main(){
    // f = A[k][n]
    // if (k >= 1) l = A[k][k - 1]
    // if (k < n - 1) r = A[k][k + 1]
    // c = A[k][k]
    std::vector<std::vector<double>> A;
    A = {   {2, 6, 0, 0, 0, 8},
            {4, 7, 4, 0, 0, 15},
            {0, 6, 8, 4, 0, 18},
            {0, 0, 5, 5, 7, 17},
            {0, 0, 0, 5, 5, 10}};
    const int n = 5;
    std::vector<double> p, q, x;
    p.resize(n); q.resize(n); x.resize(n);
    
    p[0] = A[0][n] / A[0][0];
    q[0] = A[0][1] / A[0][0];
    for (unsigned int k = 1; k < n; k++){
        p[k] = (A[k][n] - A[k][k - 1] * p[k - 1])/
            (A[k][k] - A[k][k - 1] * q[k - 1]);
        if (k < (n - 1))
            q[k] = A[k][k + 1] / (A[k][k] - A[k][k - 1] * q[k - 1]);
    }
    
    puts("p:");
    for (int i = 0; i < n; i++){
        printf("%.2f\n",p[i]);
    }
    
    puts("q:");
    for (int i = 0; i < n; i++){
        printf("%.2f\n",q[i]);
    }

    x[n - 1] = p[n - 1];
    for (int k = n - 2; k >= 0; k--){
        x[k] = p[k] - q[k] * x[k + 1];
    }
    
    puts("x:");
    for (int i = 0; i < n; i++){
        printf("%.2f\n",x[i]);
    }
}