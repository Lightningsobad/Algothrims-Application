#include<bits/stdc++.h>

using namespace std;

struct XeKhach
{
    char ten_nha_xe[30];
    int so_hanh_khach;
    int tien_ve;
};

void hien_thi_ket_qua(XeKhach* x, int n){
    printf("|%-15s|%-15s|%-15s|\n", "TEN NHA XE", "SO HANH KHACH", "TIEN VE");
    for (int i = 0; i < n; i++)
    {
        printf("|%-15s|%-15d|%-15d|\n", x[i].ten_nha_xe, x[i].so_hanh_khach, x[i].tien_ve);
    }
}

void A1(XeKhach d[], int n, int m, int &u, int &p, XeKhach* r){
    u = 0;
    p = 0;
    int i = 0;
    while(i < n){
        p += d[i].tien_ve;
        u++;
        r[u - 1] = d[i];
        if(p > m)
            break;
        i++;
    }
}

void A2(int w[], int v[], int n, int m, int** F, int &q, int &t, XeKhach d[], XeKhach* result){
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
    t = F[n][m];
    q = 0;
    int i = n;
    int j = m;
    while (i != 0)
    {
        if(F[i][j] != F[i - 1][j]){
            q++;
            result[q - 1] = d[i - 1];
            j = j - w[i];
        }
        i--;
    }
}


int main() {
    int n = 8;
    XeKhach d[8] = {
        {"Hong Bang", 55, 5000000}, 
        {"Giai Phong", 45, 4550000},
        {"Tam An", 50, 4500000}, 
        {"Thong Nhat", 40, 3500000},
        {"Limosine", 35, 3000000}, 
        {"Binh Yen", 30, 2250000},
        {"Duc Bao", 25, 2000000}, 
        {"Nhat Minh", 30, 1350000},
    };
    //Phan 1:
    int m = 10000000; 
    int u;
    int p;
    XeKhach* r = new XeKhach[n];
    A1(d, n, m, u, p, r);
    if(p < m)
        cout << "Khong tim duoc phuong an nao" << endl;
    else{
        cout << "So chuyen xe it nhat can su dung: " << u << endl;
        cout << "Tong so tien ve thu duoc: " << p << endl;
        hien_thi_ket_qua(r, u);
    }

    //Phan 2:
    int v = 150;
    int q, t;
    int* w = new int[n + 1];
    w[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        w[i] = d[i - 1].so_hanh_khach;
    }
    int* vl = new int[n + 1];
    vl[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        vl[i] = d[i - 1].tien_ve;
    }
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[v + 1];
    }
    XeKhach* result = new XeKhach[n];
    A2(w, vl, n, v, F, q, t, d, result);
    if(q == 0)
        cout << "Khong tim duoc phuong an nao" << endl;
    else{
        cout << "So chuyen xe can dua vao nha cho: " << q << endl;
        cout << "Tong tien ve thu duoc: " << t << endl;
        hien_thi_ket_qua(result, q);
    }
 
}