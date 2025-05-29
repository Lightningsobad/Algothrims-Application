#include<bits/stdc++.h>

using namespace std;



int Max(int* a, int l, int r){
    if(l == r)
        return a[l];
    int m = (r + l) / 2;
    int max_left = Max(a, l, m);
    int max_right = Max(a, m + 1, r);
    int max = max_left;
    if(max_right > max)
        return max_right;
    return max_left;
 
}
int main(){
    int a[] = {1, 4, 2, 5, 8, 7, 9, 3, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << Max(a, 0, n - 1);
}