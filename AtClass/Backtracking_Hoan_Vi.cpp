#include<bits/stdc++.h>

using namespace std;

void Show_Result(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}

void Try(int a[], int n, bool* flag, int* x, int k, int &count){
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false){
            x[k] = a[i];
            if(k == n - 1){
                Show_Result(x, n);
                count++;
            }
            else{
                flag[i] = true;
                Try(a, n, flag, x, k + 1, count);
                flag[i] = false;
            }
        }
    }
    
}

int main() {
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int *x = new int[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    int count = 0;
    Try(a, n, flag, x, 0, count);
    cout << "Số hoán vị: " << count << endl;
}