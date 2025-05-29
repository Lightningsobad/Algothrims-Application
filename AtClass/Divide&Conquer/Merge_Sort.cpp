#include<bits/stdc++.h>

using namespace std;

void hien_thi(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}
void Merge(int* a, int* b, int n, int m, int* c){   //THUẬT TOÁN TRỘN
    int max = a[n - 1];
    if(b[m - 1] >= max);
        max = b[m - 1];
    int i = 0;
    int j = 0;
    a[n] = b[m] = max + 1;
    for (int k = 0; k < m + n; k++)
    {
        if(a[i] < b[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k] = b[j];
            j++;
        }
    } 
}

void Merge_sort(int* a, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        Merge_sort(a, l, m);
        Merge_sort(a, m + 1, r);
        int* b = new int[r + 1];
        //Sao chép nửa đầu của a sang b
        for (int i = m; i >= l; i--)
        {
            b[i] = a[i];
        }
        //Sao chép nửa sau sang b theo thứ tự ngược lại
        for (int i = m + 1; i <= r; i++)
        {
            b[r + m + 1 - i] = a[i];
        }
        //Trộn hai nửa của b (chuyển về a)
        int i = l;
        int j = r;
        for (int k = l; k <= r; k++)
        {
            if(b[i] < b[j]){
                a[k] = b[i];
                i++;
            }
            else{
                a[k] = b[j];
                j--;
            }
        }
        
        
    }
}


int main() {
    int a[] = {2, 1, 5, 4, 6, 7, 9, 8, 3};
    int n = sizeof(a) / sizeof(a[0]);
    Merge_sort(a, 0, n - 1);
    hien_thi(a, n);
}