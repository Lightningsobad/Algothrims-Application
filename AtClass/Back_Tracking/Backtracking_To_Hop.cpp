#include<bits/stdc++.h>

using namespace std;

void Show_Result(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int s[], int* x, int n, int m, int k, int &count, bool* flag){ //Tổ hợp cho tập S= {1, 2, 3, 4, 5, ...n}
    int last_element;
    if(k == 0)
        last_element = 0;
    else    
        last_element = x[k - 1];
    for (int i = last_element; i < n; i++){
        if(flag[i] == false){
            x[k] = s[i];
            if(k == m - 1){
                Show_Result(x, m);
                count++;
            }
            else{
                flag[i] = true; 
                Try(s, x, n, m, k + 1, count, flag);
                flag[i] = false;
        }
    }
}
 
}

void Try_v2(int s[], int* x, int n, int m, int k, int &count, int index){ //tổ hợp cho tập bất kì
    if(k == m){
        Show_Result(x, m);
        count++;
    }
    for (int i = index; i < n; i++)
    {
        x[k] = s[i];
        Try_v2(s, x, n, m, k + 1, count, i + 1);
    }
    
}

int main() {
    int s[] = {1, 2, 3, 4, 5};
    int n = sizeof(s) / sizeof(s[0]);
    int m = 3;
    int count = 0;
    int* x = new int[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    Try(s, x, n, m, 0, count, flag);
    cout << "Số tổ hợp: " << count << endl;
    //
    //
    int s2[] = {3, 6, 7, 9, 14, 222};
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int m2 = 3;
    int count2;
    int* x2 = new int[n2];
    Try_v2(s2, x2, n2, m2, 0, count2, 0);
    cout << "So to hop: " << count2 << endl;

}