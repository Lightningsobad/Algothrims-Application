#include<bits/stdc++.h>


using namespace std;


struct PhongMay
{
    char so_hieu[10];
    int so_luong;
    char ho_ten_ql[50]; 
    int gia_thanh_ly; 
};

void hien_thi_kq(PhongMay* result,  int n){
    printf("|%-19s|%-15s|%-19s|%-15s|\n", "SO HIEU", "SO LUONG", "HO TEN QL", "GIA THANH LY");
    for (int i = 0; i < n; i++)
    {
        printf("|%-19s|%-15d|%-19s|%-15d|\n", result[i].so_hieu, result[i].so_luong, result[i].ho_ten_ql, result[i].gia_thanh_ly);
    }   
}

void tim_kiem(PhongMay* result, int n){
    printf("|%-19s|%-15s|%-19s|%-15s|\n", "SO HIEU", "SO LUONG", "HO TEN QL", "GIA THANH LY");
    for (int i = 0; i < n; i++)
    {
        if(strcmp(result[i].ho_ten_ql, "Nguyen Van Hoang") == 0)
        printf("|%-19s|%-15d|%-19s|%-15d|\n", result[i].so_hieu, result[i].so_luong, result[i].ho_ten_ql, result[i].gia_thanh_ly);
    }  
}

void G(PhongMay d[], int n, int m, int &u, PhongMay* p){
    u = 0;
    int sum = 0;
    int i = 0;
    while(i < n){
        sum += d[i].so_luong * d[i].gia_thanh_ly;
        if(sum > m){
            break;
        }
        else{
            u++;
            p[u - 1] = d[i];
        }
        i++;
    }
}

void D(PhongMay d[], int v[], int w[], int n, int m, int**F, int &q, int &t, PhongMay* result){
    for(int j = 0; j <= m; j++){
        F[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j];
            if(w[i] <= j){
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
    while(i != 0){
        if(F[i][j] != F[i - 1][j]){
            q++;
            result[q - 1] = d[i - 1];
            j = j - w[i];
        }
        i--;
    }
}

int main(){
    int n = 7;
    PhongMay d[n] = {
        {"PM001", 11, "Hoang Xuan Vinh", 6},
        {"PM002", 15, "Nguyen Van Hoang", 7},
        {"PM003", 17, "Pham Xuan Chien", 8},
        {"PM004", 18, "Le Thi Huyen", 9},
        {"PM005", 17, "Nguyen Thuy Linh", 11},
        {"PM006", 22, "Tran Xuan Do", 14},
        {"PM007", 30, "Ngo Van Quan", 15}
    };
    int m = 800;
    //Bài toán tham lam  
    int u = 0;
    PhongMay* p = new PhongMay[n];
    G(d, n, m, u, p);
    if(u == 0){
        cout << "Khong co phuong an." << endl;
    }
    else{
        cout << "So phong may thanh ly duoc nhieu nhat: " << u << endl;
        cout << "Danh sach phong may thanh ly: " << endl;
        hien_thi_kq(p, u);
        cout << "Danh sach phong may do nhan vien Nguyen Van Hoang quan li: " << endl;
        tim_kiem(p, u);
    }
    //Bài toán quy hoạch động
    int* v = new int[n + 1];
    int* w = new int[n + 1];
    v[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        v[i] = d[i - 1].so_luong;
    }
    w[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        w[i] = d[i - 1].gia_thanh_ly * d[i - 1].so_luong;
    }
    int** F = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = new int[m + 1];
    }
    PhongMay* result = new PhongMay[n];
    int t;
    int q;
    D(d, v, w, n, m, F, q, t, result);
    if(q == 0){
        cout << "Khong co phuong an." << endl;
    }
    else{
        cout << "Tong so may tinh duoc thanh ly: " << t << endl;
        cout << "So luong cac phong may duoc thanh ly: " << q << endl;
        hien_thi_kq(result, q);
    }
}