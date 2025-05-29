#include<bits/stdc++.h>

using namespace std;


struct GoiHang{
    int khoi_luong;  //khối lượng
    int gia_tri;  //giá trị
};

float A(float a[], int l, int r){
    float sum = 0;
    if(l == r){
        if(a[l] > 0){
            return a[l];
        }
        else
            return 0;
    }
    else{
        int m = (l + r) / 2;
        sum += A(a, l, m) + A(a, m + 1, r);
        return sum;
    }
}


void A2(GoiHang a[], int n, int &D, int C, int* result){
    int i = 0;
    int sum = 0;
    D = 0;
    while(i < n){
        sum += a[i].gia_tri;
        if(sum > C)
            break;
        else{
            D++;
            result[D - 1] = i + 1;
        }
        i++;
    }
}


void A3(int w[], int v[], int n, int m, int** F, int &P, GoiHang a[], GoiHang* result, int &count){
    for (int j = 0; j <= m; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            F[i][j] = F[i - 1][j];
            if(w[i] <= j){
                int temp = v[i] + F[i - 1][j - w[i]];
                if(temp > F[i][j])
                    F[i][j] = temp;
            }
        }
        
    }
    count = 0;
    P = F[n][m];
    int i = n;
    int j = m;
    while(i != 0){
        if(F[i][j] != F[i - 1][j]){
            count++;
            result[count - 1] = a[i - 1];
            j = j - w[i];
        }
        i--;
    }

    
}

int main() {

    //Bai 1
    float a[] = {-1, 3, 4, 5, 2, -4, 6, -3, 4, -5, -6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "tong so duong: " << A(a, 0, n - 1) << endl;

    //Bai 2
    int n2 = 10;
    GoiHang a2[n2] = {{3, 2}, {4, 4}, {2, 5}, {5, 6}, {10, 7}, {8, 9}, {12, 12}, {6, 20}, {11, 22}, {7, 25}};
    int D;
    int C = 17;
    int* result = new int[n2];
    A2(a2, n, D, C, result);
    if(D == 0){
        cout << "Khong co phuong an" << endl;
    }
    else{
        cout << "So luong goi hang nhieu nhat co the lay: " << D  << endl;
        cout << "Danh sach cac goi hang co the lay: ";
        for (size_t i = 0; i < D; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;      
    }

    int M = 20;
    int* m = new int[n2 + 1];
    int* v = new int[n2 + 1];
    m[0] = 0;
    for (int i = 1; i < n2 + 1; i++)
    {
        m[i] = a2[i - 1].khoi_luong;
    }
    v[0] = 0;
    for (int i = 0; i < n2 + 1; i++)
    {
        v[i] = a2[i - 1].gia_tri;
    }

    int** F = new int*[n2 + 1];
    for (int i = 0; i < n2 + 1; i++)
    {
        F[i] = new int[C + 1];
    }
    GoiHang* result2 = new GoiHang[n2];
    int count;
    int P;
    A3(m, v, n2, M, F, P, a2, result2, count);
    cout << "So goi hang can lay: " << count << endl;
    cout << "Gia tri thu duoc: " << P << endl;
    cout << "Gia tri cac goi hang da lay: ";
    for (int i = 0; i < count; i++)
    {
        cout << result2[i].gia_tri << " ";
    }
    cout << endl;
    
    

    
    
    
}