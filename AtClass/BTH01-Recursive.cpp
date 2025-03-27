#include<bits/stdc++.h>

using namespace std;

int A1(int n); //tìm số fibonacci thứ n
vector<int> A1ct(int n);
int timMienLienThong();
int A4(int n);      //tính tổng các chữ số của số nguyên dương
int A5(int a[], int n);
int main() {
    // int n = 5;
    // cout << A1(5) << endl;
    // vector<int> vec = A1ct(n);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }

    // cout << endl;
    // cout << A4(55555555);
    int a[] = {2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << A5(a, n) << endl;
    return 0;
}

int A1(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return A1(n - 2) + A1(n - 1);
}

vector<int> A1ct(int n) {
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(A1(i));
    }
    return vec;
    
}
int A4(int n) {
    if(n < 10)
        return n;
    else    
        return A4(n % 10) + A4(n / 10);
}

int A5(int a[], int n) {
    if(n == 1 && a[n - 1] % 2 != 0)
        return a[n - 1];
    else    
        return A5(a, n - 1); 
}
