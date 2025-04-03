#include <bits/stdc++.h>


using namespace std;

int BinarySearchV1(int a[], int l, int r, int x);                                //using while loop
int BinarySearchV2(int a[], int l, int r, int x);                                //using recursive   
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    //cout << BinarySearchV1(a, 0, n - 1, 5);
    cout << BinarySearchV2(a, 0, n - 1, 44);

    return 0;
}

int BinarySearchV1(int a[], int l, int r, int x) {
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] == x)
            return mid;
        if(a[mid] > x)
            r = mid - 1;
        else    
            l = mid + 1;
    }
    return -1;
}

int BinarySearchV2(int a[], int l, int r, int x) {

    if(r >= l){
        int mid = l + (r - l) / 2;
        if(a[mid] == x)
            return mid;
        if(a[mid] > x)
            return BinarySearchV2(a, l, mid - 1, x);
        else    
            return BinarySearchV2(a, mid + 1, r, x);

    }
    return -1;
}








