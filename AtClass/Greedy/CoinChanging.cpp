#include<bits/stdc++.h>

using namespace std;



void BubbleSort(int a[], int n){
    for(int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
        {
            if(a[j - 1] < a[j]){
                int tg = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tg;
            }
        }
        
    }
}

int A1(int a[], int* s, int n, int m){ //Change Coin
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    int i = 0;
    while (m > 0 && i < n)
    {
        s[i] = m / a[i];
        m = m - s[i] * a[i];
        i++;
    }
    if(m > 0)
        return 0;
    else{
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += s[i];
        }
        return sum;
    }
    
    
}
int main() {
    int a[] = {25, 5, 100, 30, 15, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int* s = new int[n];
    int m = 55;
    int c = A1(a, s, n, m);
    if(c == 0)
        cout << "Khong co phuong an nao";
    else
        cout << "Lay duoc it nhat " << c << " dong xu" << endl; 
    

}