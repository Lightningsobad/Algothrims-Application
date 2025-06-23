#include <iostream> 

using namespace std;

long long tinhGiaiThua(int n);
int timUCLN(int a, int b);
long timFibo(int a);
long C(int k, int n);
long tongNsoTuNhien(int n);


int main() {
    // cout << "9! = " << tinhGiaiThua(9) << endl;
    // cout << timUCLN(150, 15) << endl;
    // cout << timFibo(7) << endl;
    //cout << C(2, 8) << endl;
    cout << tongNsoTuNhien(10) << endl;
    return 0;
}

long long tinhGiaiThua(int n) {
    if(n == 0)
         return 1;
     else
        return n * tinhGiaiThua(n - 1); //đệ quy tuyến tính
}

int timUCLN(int a, int b) {
    if(a % b == 0)
        return b;
    else
        return timUCLN(b, a % b);
}

long timFibo(int a){
    if(a == 1 || a == 2)
        return 1; 
    else
        return timFibo(a - 2) + timFibo(a - 1); //đệ quy nhị phân
}

long C(int k, int n) {
    if(k == 0 || k == n)
        return 1;
    else
        return C(k - 1, n - 1) + C(k, n - 1);
}

long tongNsoTuNhien(int n) {
    if(n == 0)
        return 0;
    else
        return n + tongNsoTuNhien(n - 1); 
}