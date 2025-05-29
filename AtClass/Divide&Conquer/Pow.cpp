#include<bits/stdc++.h>

using namespace std;

int Pow(int a, int l, int r){
    int m = (l + r) / 2;
    if(l == r)
        return a;
    return Pow(a, l, m) * Pow(a, m + 1, r);
}

int main(){
    int a = 3;
    int n = 4;
    cout << Pow(a, 0, n - 1) << endl;

}