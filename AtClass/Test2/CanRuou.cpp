#include<bits/stdc++.h>

using namespace std;

struct CanRuou
{
    char nhan_hieu[30];
    int dung_tich;
    int gia_tri;
};

void hien_thi_ket_qua(CanRuou* r, int n){
    for (int i = 0; i < n; i++)
    {
        cout << r[i].nhan_hieu << " - " << r[i].gia_tri << endl;
    } 
}

void hien_thi_chi_tiet(CanRuou* r, int n){
    printf("|%-10s|%-10s|%-10s|\n", "NHÃN HIỆU", "DUNG TÍCH", "GIÁ BÁN");
    for (int i = 0; i < n; i++)
    {
        printf("|%-10s|%-10d|%-10d|\n", r[i].nhan_hieu, r[i].dung_tich, r[i].gia_tri);
    }
    
}
void A(CanRuou d[], int n, int m, int &count, CanRuou* r){
    count = 0;
    int i = 0;
    while (i < n)
    {
        m -= d[i].gia_tri;
        if(m < 0){
            break;
        }
        else{
            count++;
            r[i] = d[i];
        }
        i++;
    }
}

void B(int w[], int v[], int n, int s, int** F, int &count, CanRuou d[], CanRuou* r){
    for (int j = 0; j <= s; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            F[i][j] = F[i - 1][j];
            if(w[i] <= j){
                int temp = v[i] +  F[i - 1][j - w[i]];
                if(F[i][j] < temp)
                    F[i][j] = temp;

            }
        }       
    }

    cout << "Tổng giá trị lớn nhất mua được: " << F[n][s] << endl;
    cout << "Bảng phương án: " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s + 1; j++)
        {
            cout << F[i][j] << "  ";
        }
        cout << endl;
    }
    int i = n;
    int j = s;
    count = 0;
    while (i != 0)
    {
        if(F[i][j] != F[i - 1][j]){
            count++;
            r[count - 1] = d[i - 1];
            j = j - w[i];
        }
        i--;
    }
    
    
    
}

int main(){
    int n = 6;
    CanRuou d[n] = {
        {"Vang Pháp", 10, 120000}, 
        {"Chivas", 20, 280000},
        {"Vodka", 15, 300000},
        {"Bourbon", 35, 450000},
        {"Nếp", 50, 520000},
        {"Táo mèo", 40, 550000},
    };
    //Bài 1
    int m = 700000;
    int count1;
    CanRuou* r = new CanRuou[6];
    A(d, n, m, count1, r);
    cout << "Số can rượu mua được nhiều nhất: " << count1 << endl;
    hien_thi_ket_qua(r, count1);

    //Bài 2
    int* w = new int[n + 1];
    int* v = new int[n + 1];
    w[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        w[i] = d[i - 1].dung_tich;
    }
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        v[i] = d[i - 1].gia_tri;
    }
    int s = 100;
    int count2;
    CanRuou* result = new CanRuou[n];
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[s + 1];
    }
    B(w, v, n, s, F, count2, d, result);
    cout << endl;
    cout << "So luong can ruou mua duoc: " << count2 << endl;
    hien_thi_chi_tiet(result, count2);
    
    

}