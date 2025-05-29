#include<bits/stdc++.h>

using namespace std;

float Sum(float a[], int l, int r){
    if(l == r)
        return a[l];
    else{
        int m = (l + r) / 2;
        float sum_left = Sum(a, l, m);
        float sum_right = Sum(a, m + 1, r);
        float sum = sum_left + sum_right;
        return sum;
    }
}

void A(float a[], int n, float c, int &D, float &M, float *result){
    D = 0;
    M = 0;
    int i = 0;
    while(i < n){
        M += a[i];
        if(M > c){
            M -= a[i];
            break;
        }
        else{
            D++;
            result[D - 1] = a[i];
        }
        i++;
    }
}

int char_in_string(char* s, char ch){
    int x = 0;
    while(s[x] != '\0'){
        if(s[x] == ch)
            return x;
        x++;
    }
    return -1;
}

bool B(char* t, char* p){
    int n = strlen(t);
    int v = strlen(p);
    int i = n - 1;
    while(i < strlen(t)){
        int k = v - 1;
        while(k > -1 && t[i] == p[k]){
            k--;
            i--;
        }
        if(k < 0)
            return true;
        else{
            int x = char_in_string(p, t[i]);
            if(x < 0)
                i = i + v;
            else    
                i = i + v - x - 1;
    }
    }
    return false; 
}

int main() {
    //BAI 1.1
    int n = 12; 
    float a[] = {1, 3, 2, 4, 5, 6, 8, 9, 7, 10, 11, 12};
    cout << "Sum: " << Sum(a, 0, n - 1) << endl;

    //BAI 1.2
    int n2 = 9;
    float a2[] = {2, 4, 5, 7, 8, 10, 14, 25, 30};
    float c = 20;
    char p[] = {"Dai hoc cong nghiep ha noi"};
    char q[] = {"khoa"};
    int D;
    float M;
    float* result = new float[n];
    A(a2, n2, c, D, M, result);
    cout << "So luong phan tu nhieu nhat " << D << endl;
    cout << "Gia tri tong: " << M << endl;
    for (int i = 0; i < D; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    bool result2 = B(p, q);
    if(result2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}