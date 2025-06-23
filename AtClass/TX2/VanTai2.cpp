#include<bits/stdc++.h>

using namespace std;


void A5(int w[], int v[], int** F, int n, int m, int* k, int &u){
    for (int j = 0; j <= m; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j];
            if(w[i] < j){
                int temp = v[i] + F[i - 1][j - w[i]];
                if(F[i][j] < temp)
                    F[i][j] = temp;
            }
        }
        
    }

    u = 0;
    cout << "Tổng khối lượng lớn nhất xếp được: " << F[n][m] << endl;
    int i = n;
    int j = m;
    while (i != 0)
    {
        if(F[i][j] != F[i - 1][j]){
            u++;
            k[u - 1] = i;
            j = j - w[i];
        }
        i--;
    }
    cout << "Bảng phương án: " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 7;
    int k = 20;
    int kt[n + 1] = {0, 3, 5, 9, 8, 10, 2, 6}; 
    int m[n + 1] = {0, 5, 6, 3, 4, 7, 2, 9};
    int u;
    int* v = new int[n];
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[k + 1];
    }
    A5(kt, m, F, n, k, v, u);
    cout << "Danh sách đồ được chọn: " << endl;
    for (int i = 0; i < u; i++)
    {
        cout << v[i] << endl;
    }
    
}