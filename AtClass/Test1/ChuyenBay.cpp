#include <bits/stdc++.h>

using namespace std;

struct ChuyenBay
{
    char so_hieu[10];
    int gia_ve;
    int so_ghe;
};

void hien_thi_td(){
    printf("|%-10s|%-10s|%-10s|\n", "SO HIEU", "GIA VE", "SO GHE");
}
void hien_thi_kq(ChuyenBay* x, int n){
    for (int i = 0; i < n; i++)
    {
        cout << x[i].so_hieu << " - " << x[i].so_ghe << endl;
    }
    cout <<"------------------------" << endl;
    
}

void A1(ChuyenBay d[], int n){
    if(n > 0){
        A1(d, n - 1);
        if(d[n - 1].gia_ve > 700000){
            printf("|%-10s|%-10d|%-10d|\n", d[n - 1].so_hieu, d[n - 1].gia_ve, d[n - 1].so_ghe);
        }
    }
}

ChuyenBay A2(ChuyenBay d[], int l, int r){
    if(l == r){
        return d[l];
    }
    else{
        int m = (l + r) / 2;
        ChuyenBay min_left = A2(d, l, m);
        ChuyenBay min_right = A2(d, m + 1, r);
        ChuyenBay min = min_left;
        if(min_right.gia_ve < min.gia_ve){
            min = min_right;
        }
        return min;
    }
}

void A3(ChuyenBay d[], ChuyenBay* result, int n, int m, int k, int index, int &count){
    if(k == m){
        hien_thi_kq(result, m);
        count++;
    }
    for (int i = index; i < n; i++)
    {
        result[k] = d[i];
        A3(d, result, n, m, k + 1, i + 1, count);
    }
    
}

int main(){
    int n = 7;
    ChuyenBay d[n] = {
        {"VN001", 650000, 80}, 
        {"VN002", 700000, 85},
        {"VN003", 780000, 90},
        {"VN004", 800000, 45},
        {"VN005", 900000, 100},
        {"VN006", 200000, 20},
        {"VN007", 400000, 50}
    };

    //Cau 1:
    cout << "Tat ca chuyen bay co gia ve tren 700000: " << endl;
    hien_thi_td();
    A1(d, n);

    //Cau 2:
    cout << "Chuyen bay co gia ve thap nhat: " << endl;
    ChuyenBay min = A2(d, 0, n - 1);
    hien_thi_td();
    printf("|%-10s|%-10d|%-10d|\n", min.so_hieu, min.gia_ve, min.so_ghe);

    //Cau 3:
    ChuyenBay* result = new ChuyenBay[n];
    int m = 4;
    int count = 0;
    A3(d, result, n, m, 0, 0, count);
    cout << "So cach chon 4 chuyen bay tu danh sach: " << count << endl;
}