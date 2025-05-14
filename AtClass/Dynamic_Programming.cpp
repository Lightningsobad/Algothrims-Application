#include<bits/stdc++.h>

using namespace std;

void algorithm(int w[], int v[], int n, int m, int **F){
    for (int j = 0; j <= m; j++)
    {
        F[0][j] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j]; // không lấy gói thứ i
            if(w[i] <= j){
                int temp = v[i] + F[i - 1][j - w[i]];
                if(F[i][j] < temp)      //lấy gói thứ i
                    F[i][j] = temp;
            }
        }
        
    }
}

void result(int** F, int w[], int n, int m){
    cout << "Max value: " << F[n][m] << endl;
    int i = n;
    int j = m;
    while(i != 0){
        if(F[i][j] != F[i - 1][j]){
            cout << i << " ";
            j = j - w[i];   //lấy gói thứ i
        }
        i--;
    }
    cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main(){
    int n = 6;
    int m = 12;
    int w[n + 1] = {0, 3, 6, 2, 7, 1, 5};
    int v[n + 1] = {0, 4, 5, 2, 6, 1, 3};
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[m + 1];
    }
    algorithm(w, v, n, m, F);
    result(F, w, n, m);
        
    




}