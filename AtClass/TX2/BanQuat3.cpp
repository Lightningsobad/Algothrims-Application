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

void F3(Quat d[], int n, double &p, int &c, Quat* r){
    int i = 0;
    c = 0;
    int sum = 0;
    while (i < n)
    {
        sum += d[i].gia_ban;
        c++;
        r[i] = d[i];
        if(sum > p){
            break;
        }
        i++;
    }
    
}


int main() {
    Quat d[7] {
        {"SamSung", "Do", 900000}, 
        {"Panasonic", "Trang", 100000},
        {"Inverter", "Xanh", 7000},
        {"Daikin", "Tim", 4000},
        {"ThongNhat", "Vang", 3500},
        {"LG", "Trang", 2000},
        {"ShangHai", "Do", 8000}
    };
    double p = 1007500;
    Quat* r = new Quat[7];
    int c;
    F3(d, 7, p, c, r);
    cout << "Mua it nhat " << c << " quat" << endl;
    hien_thi_ket_qua(r, c);
    
}