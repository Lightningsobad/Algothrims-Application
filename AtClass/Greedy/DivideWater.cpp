#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if(a[j - 1] > a[j]){
                int tg = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tg;
            }
        }
        
    }
    
}

int A2(int x[], int* s, int n, int d){
    BubbleSort(x, n);
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    int i = 0;
    while (d > 0 && i < n)
    {
        if(s[i] < d){
            s[i] = 1;
            d -= x[i];
        }
        i++;
    }
    if(s[0] == 0){
        return 0;
    }
    else{
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += s[i];
        return sum; 
    }
      
}

int main() {
    int x[] = {2, 4, 3, 8, 5};
    int n = sizeof(x) / sizeof(x[0]);
    int* s = new int[n];
    int d = 10;
    int q = A2(x, s, n, d);
    cout << "Do duoc nhieu nhat " << n << " chai" << endl;
    
}