#include<bits/stdc++.h>

using namespace std;

int Find_position_k(int a[], int l, int r, int k){
    if(r < l)
        return -1;
    else{
        int m = (l + r) / 2;
        if(a[m] == k)
            return m;
        else if(a[m] > k)
            return Find_position_k(a, l, m, k);
        else    
            return Find_position_k(a, m + 1, r, k);
    }

}

int main() {
    int a[] = {2, 4, 3, 6, 7, 5, 9, 8, 10, 13, 12, 11, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 10;
    cout << Find_position_k(a, 0, n - 1, k) << endl;
}