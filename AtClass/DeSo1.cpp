#include<bits/stdc++.h>

using namespace std;

struct ManHinh
{
    char tenHangSX[15];
    double kich_thuoc;
    double gia_ban;
};


ManHinh mh[7] {
    {"LG", 14, 2000000}, 
    {"Xiaomi", 27, 6000000},
    {"SamSung", 22, 3000000},
    {"Asus", 24.5, 2500000},
    {"Lenovo", 27, 5000000},
    {"MSI", 25, 3200000},
    {"Acer", 25.1, 3500000},
};

//thiet ke thuat toan A1 tra ve tong gia ban cua tat ca cac man hinh bang chien luoc de quy
long A1(ManHinh mh[], int n){
    if(n == 0)
        return mh[n].gia_ban;
    else
        return mh[n].gia_ban + A1(mh, n - 1);
}

//thiet ke thuat toan A2 tinh va tra ve so luong man hinh co kich thuoc tu 15.6 inch tro len
int count = 0;
void A2(ManHinh mh[], int l, int r){
    if(l == r){
        if(mh[l].kich_thuoc >= 15.6){
            ::count++;
        }
    }
    else {
        int mid = (l + r) / 2;
        A2(mh, l, mid);
        A2(mh, mid + 1, r);
    }
}

//thiet ke thuat toan A3 theo chien luoc quay lui cho biet co tat ca
//bao nhieu phuong an dat n man hinh lenn chiec ban co ghi so thu tu tu 1 den n, hien thi cac phuong an do, moi phuong an
//hien thi so thu tu duoc ghi tren ban va ten nha san suat
int count_result_A3 = 0;
void showResult(ManHinh mh[]){
    ::count_result_A3++;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << " - " << mh[i].tenHangSX << endl;
    }
    cout << " -----------------------------------------" << endl;
}

void A3(ManHinh mh[], ManHinh* mh_result, bool* flag, int n, int k) {
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false){
            strcpy(mh_result[k].tenHangSX, mh[i].tenHangSX);
            if(k == n - 1){
                showResult(mh_result);
            }
            else{
                flag[i] == true;
                A3(mh, mh_result, flag, n, k + 1);
                flag[i] = false;
            }
        }
    }
    
}




int main() {
    int n = 7;
    cout << "TONG GIA BAN CUA TAT CA CAC MAN HINH TRONG DANH SACH: " << A1(mh, n) << endl;
    A2(mh, 0, n - 1);
    cout << "SO LUONG MAN HINH TRONG DANH SACH CO KICH THUOC TU 15.6 INCH TRO LEN: " << ::count << endl;
    ManHinh* mh_result = new ManHinh[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    
    cout << "PHUONG AN XEP" << n << " MAN HINH VAO" << n << " BAN CO GHI SO THU TU:" << endl;
    A3(mh, mh_result, flag, n, 0);
    cout <<"TONG SO CACH XEP: " << ::count_result_A3 << endl;
}