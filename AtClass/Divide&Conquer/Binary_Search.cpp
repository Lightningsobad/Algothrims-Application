#include<bits/stdc++.h>

using namespace std;


//thuật toán tìm kiếm nhị phân theo phương pháp đệ quy
int Binary_Search_Recursive(int x[], int l, int r, int c){
    if(r < l)
        return -1;
    else{
        int mid = (l + r) / 2;
        if(x[mid] == c)
            return mid;
        else if(x[mid] > c)
            return Binary_Search_Recursive(x, l, mid - 1, c);
        else    
            return Binary_Search_Recursive(x, mid + 1, r, c);
    }
}

//thuật toán tìm kiếm nhị phân theo phương pháp lặp
int Binary_Search_Loop(int x[], int n, int c){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m  = (l + r) / 2;
        if(x[m] == c)
            return m;
        else if(x[m] > c)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
    
}

int main() {
    int x[] = {1, 3, 4, 5, 7, 8, 9, 10, 12};
    int n = sizeof(x) / sizeof(x[0]);
    int pos = Binary_Search_Recursive(x, 0, n - 1, 10);
    cout << pos << endl;
    int pos_2 = Binary_Search_Loop(x, n, 10);
    cout << pos_2 << endl;
}
