#include<bits/stdc++.h>

using namespace std;

int Sum_of_Odd(int* a, int l, int r){
    int sum = 0;
    if(l == r){
        if(a[l] % 2 != 0){
            return a[l];
        }
    }
    else{
        int m = (l + r) / 2;
        sum += Sum_of_Odd(a, l, m) + Sum_of_Odd(a, m + 1, r);
        return sum;
    }
}


int main() {
    int a[] = {1, 3, 2, 5, 7, 6, 9, 8, 4, 11, 22, 33};
    int n = sizeof(a) / sizeof(a[0]);
    cout << Sum_of_Odd(a, 0, n - 1) << endl;

}