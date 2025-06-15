#include<bits/stdc++.h>

using namespace std;


void A(float a[], float k, int n, float &sum, int &count){
    if(n > 0){
        if(a[n - 1] < k){
            sum += a[n - 1];
            count++;
        }
        A(a, k, n - 1, sum, count);
    }
}


int main() {
    float a[] = {2.5, 5, 6, 3.5, 7, 9, 4, 10, 11, 3.6, 5.5, 15};
    int n = sizeof(a) / sizeof(a[0]);
    float k = 6.5;
    float sum = 0;
    int count = 0;
    A(a, k, n, sum, count);
    if(count == 0){
        cout << "Khong tim duoc phuong an" << endl;
    }
    else{
        cout <<  "Tong so luong cac so nho hon " << k << ": " << count << endl;
        cout << "Tong cua cac so nho hon " << k << ": " << sum << endl;
    }



}