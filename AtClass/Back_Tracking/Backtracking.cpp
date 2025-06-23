#include <bits/stdc++.h>

using namespace std;

// void A1(int* a, int n, int k);
// void A1AD(char* a, int n, int k);
// void A2(int* a, bool* flag, int n, int k);
// void A2AD(string* a, bool* flag, string b[], int n, int k);
// void showResult(int* a, int n);
// void showResultString(string* a, int n);

// void showResultSwap(char *G, string *N);








void showResultSwap(char[] G, string *N, int n) {
    cout << "Cach xep thu " << n << ":" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << N[i] << " - " << G[i] << endl;
    }
    



}

void A1Swap(char[] G, string[] N1, string *N2, bool* flag, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false){
            strcpy(N2[k], N1[i]);
            if(k == n - 1){
                count++;
                showResultSwap(G, N2, count);
            }
                
            else{
                flag[i] = true;
                A1Swap(G, N1, N2, flag, n, k + 1);
                flag[i] = false;
            }
            
        }
    }
    
}



void showResult(int* a, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
    
}

void showResultString(string* a, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void A1(int* a, int n, int k) {
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if(k == n - 1){      
            showResult(a, n);   
        }       
        else    
            A1(a, n, k + 1);
    }
    
}
void A1AD(char* a, int n, int k){
    for (char i = 'a'; i <= 'b'; i++)
    {
        a[k] = i;
        if(k == n - 1){
            for (int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        else
            A1AD(a, n, k + 1);
    }
    

}


void A2(int* a, bool* flag, int n, int k) {
    for (int i = 1; i <= n; i++)
    {
        if(flag[i] == false){
            a[k] = i;
            if(k == n - 1)
                showResult(a, n);
            else {
                flag[i] = true;
                A2(a, flag, n, k + 1);
                flag[i] = false;
            }
        }
    }
 }

 void A2AD(string* a, bool* flag, string b[], int n, int k) {
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false) {
            a[k] = b[i];
            if(k == n - 1)
                showResultString(a, n);
            else{
                flag[i] = true;
                A2AD(a, flag, b, n, k + 1);
                flag[i] = false;
            }
        }

    }
}





int main() {    
    // string b[] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
    // int n = sizeof(b) / sizeof(b[0]);
    // string* a = new string[n];
    // bool* flag = new bool[n];
    // for (int i = 0; i < n; i++)
    // {
    //     flag[i] = false;
    // }
    // A2AD(a, flag, b, n, 0);
    
    char G[] = {'A', 'B', 'C', 'D'};
    string N[] = {"Tung", "Cuc", "Truc", "Mai"};
    int n = 4;
    string* N2 = new string[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    A1Swap(G, N, N2, flag, 4, 0);
    

    
    return 0;
}



