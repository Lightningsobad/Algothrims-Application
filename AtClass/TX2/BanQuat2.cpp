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

void F2(Quat d[], int n, double &p, int &c, Quat* r){
    int i = 0;
    c = 0;
    while (i < n && p > 0)
    {
  
            p -= d[i].gia_ban;
            if(p < 0){
                break;
            }
            else{
                c++;
                r[i] = d[i];
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
    double p = 900000 + 100000 + 7000 + 50;
    int c;
    Quat* r = new Quat[7];
    F2(d, 7, p, c, r);
    cout << "Lấy được ít nhất " << c << " cái quạt." << endl;
    hien_thi_ket_qua(r, c); 
    
}