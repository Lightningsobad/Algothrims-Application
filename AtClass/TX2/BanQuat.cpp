#include<bits/stdc++.h> 

using namespace std;

struct Quat{
    char ten_hangsx[50];
    char mau_sac[30];
    double gia_ban;
};

void hien_thi_ket_qua(Quat* d, int n){
    for(int i = 0; i < n; i++){
        cout << d[i].ten_hangsx << " - " << d[i].gia_ban << endl;
    }
}
void F1(Quat d[], int* s, int n, double &p, int &c, Quat* r){
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    int i = 0;
    while (p > 0 && i < n)
    {
        if(d[i].gia_ban < p){
            s[i] = 1;
            p -= d[i].gia_ban;
            r[i] = d[i];
        }
        i++;
    }
    if(s[0] == 0){
        c = 0;
    }
    else{
        c = 0;
        for (int i = 0; i < n; i++)
        {
            c += s[i];
        }       
    }
    
}

int main() {
    Quat d[7] {
        {"SamSung", "Do", 100000}, 
        {"Panasonic", "Trang", 200000},
        {"Inverter", "Xanh", 350000},
        {"Daikin", "Tim", 400000},
        {"ThongNhat", "Vang", 450000},
        {"LG", "Trang", 700000},
        {"ShangHai", "Do", 900000}
    };

    int* s = new int[7];
    double p = 1000000;
    int c;
    Quat* r = new Quat[7];
    F1(d, s, 7, p, c, r);
    cout << "Co the ban duoc nhieu nhat " << c << " quat" << endl;
    hien_thi_ket_qua(r, c);
    
    
}