#include<bits/stdc++.h>

using namespace std;



struct DienThoai
{
    char nhan_hieu[30];
    int kich_thuoc; 
    int gia_ban;
};

void hien_thi_ket_qua(DienThoai* r, int n){
    for (int i = 0; i < n; i++)
    {
        cout << r[i].nhan_hieu << " - " << r[i].gia_ban << endl;
    }
    
}

void Q1(int k[], int v[], int n, int s, int** F, DienThoai d[], int &count, DienThoai* r){
    for (int j = 0; j <= s; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            F[i][j] = F[i - 1][j];
            if(k[i] <= j){
                int temp = v[i] + F[i - 1][j - k[i]];
                if(F[i][j] < temp)
                    F[i][j] = temp;
            }
        }
        
    }
    count = 0;
    cout << "Result: " << F[n][s] << endl;
    int i = n;
    int j = s;
    while (i != 0)
    {
        if(F[i][j] != F[i - 1][j]){
            count++;
            r[count - 1] = d[i - 1];
            j = j - k[i];
        }
        i--;
    }
    cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s + 1; j++)
        {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    
    
}



int main() {
    int n = 6;
    DienThoai d[n] = {
        {"SamSung", 7, 10000000}, 
        {"iPhone", 10, 20000000},
        {"Xiaomi", 6, 12000000},
        {"LG", 5, 9000000},
        {"Nokia", 9, 11000000},
        {"Bphone",8, 10500000},
    };
    int* k = new int[n + 1];
    int* v = new int[n + 1];
    k[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        k[i] = d[i - 1].kich_thuoc;
    }
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        v[i] = d[i - 1].gia_ban;
    }
    int s = 20;
    int count;
    DienThoai* r = new DienThoai[n];
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[s + 1];
    }
    Q1(k, v, n, s, F, d, count, r);
    cout << "Số lượng điện thoại cần lấy: " << count << endl;
    hien_thi_ket_qua(r, count);
    
    
    




}