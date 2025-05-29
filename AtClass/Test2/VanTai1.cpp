#include<bits/stdc++.h> 

using namespace std;

void Solve(int t[], int n, int m, int* d, int &count){
    count = 0;
    int i = 0;
    while (i < n)
    {
        m -= t[i];
        if(m < 0)
            break;
        else{
            d[i] = i;
            count++;
        }
        i++;
    }
    
}

int main() {
    int n = 6;
    int m = 20;
    int t[n] = {12, 8, 7, 6, 3, 2};
    int* d = new int[n];
    int count;
    Solve(t, n, m, d, count);
    cout << "Danh sách xe tải cần dùng tối thiểu" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << d[i] << " ";
    }
    

}