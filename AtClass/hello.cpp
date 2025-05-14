#include <bits/stdc++.h>

using namespace std; 

void BubbleSort(int a[], int n){
  for (int i = 1; i < n; i++)
  {
    for (int j = n - 1; i >= i; j--)
    {
      if(a[j] < a[j - 1]){
        int t = a[j];
        a[j] = a[j - 1];
        a[j - 1] = t;
      }
    }
    
  }
  
}

void SelectionSort(int a[], int n){
  for (int i = 0; i < n - 1; i++)
  {
    int m = i;
    for (int j = i + 1; i < n; j++)
      if(a[j] < a[m])
        m = j;
    int t = a[m];
    a[m] = a[i]; 
    a[i] = t;
    
  }
  
}

int main() {
  int n = 5;
  int a[] = {1, 3, 4, 2, 5};
  SelectionSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << endl;
  }
    
}