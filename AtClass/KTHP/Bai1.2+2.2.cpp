#include<bits/stdc++.h> 

using namespace std;


void A(int a[], int n, int &sum){
    if(n > 0){
        if(a[n - 1] % 2 != 0){
            sum += a[n - 1];
        }
        A(a, n - 1, sum);
    }
}


void A2(float a[], int n, float c, int &D, float &M, float* result){
    D = 0;
    M = 0;
    int i = n - 1;
    while(i >= 0){
        M += a[i];
        D++;
        result[D - 1] = a[i];
        if(M > c){
            break;
        }
        i--;
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

int A3(char* t, char *p){
    int n = strlen(t);
    int v = strlen(p);
    int i = v - 1;
    while(i < strlen(t)){
        int k = v - 1;
        while(k > -1 && t[i] == p[k]){
            i--;
            k--;
        }
        if(k < 0)
            return i + 1;
        else{
            int x = char_in_string(p, t[i]);
            if(x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
}

int main() {
    //Bai 1
    int n = 12;
    int a[] = {2, 5, 3, 15, 66, 44, 6, 42, 20, 35, 66, 100};
    int sum = 0;
    A(a, n, sum);
    cout << "Sum of odd: " << sum << endl; //58


    //Bai 2
    int n2 = 9;
    float a2[] = {2, 4, 5, 7, 8, 10, 14, 25, 30};
    float c = 50;
    char p[] = {"Dai hoc cong nghiep ha noi"};
    char q[] = {"cong"};
    int D;
    float M;
    float* result = new float[n2];
    A2(a2, n2, c, D, M, result);
    cout << "So luong phan tu it nhat " << D << endl;
    cout << "Gia tri tong: " << M << endl;
    cout << "Cac phan tu: ";
    for (int i = 0; i < D; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Vi tri xuat hien chuoi P trong chuoi Q: " << A3(p, q) << endl;


}