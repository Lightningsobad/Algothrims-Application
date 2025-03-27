#include <bits/stdc++.h> 

using namespace std;

//Easy Problems
void print1toN(int n); //O(n)
void printNto1(int n);
float calculateMeanOfArray(int a[], int n);
int calculateSumOfNatural(int a[], int n);
string reverseString(string str);
string reverseStringV2(string str);
int calculateLengthOfString(string str);
int calculateSumOfDigitOfNumber(int n);
int findFibonacci(int n);
vector<int> printFibonacciNumbers(int n);
long long calculateFactorial(int n);
int findMinOfArray(int a[], int n);
int findMaxOfArray(int a[], int n);
//Medium Problems
string removeDuplicateCharacter(string str);


int main() {
    // vector<int> vec = printFibonacciNumbers(10);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] <<  " ";
    // }
    // int a[] = {10, 4, 3, 5, -2, 6};
    // int n = sizeof(a) / sizeof(a[0]);
    // cout << findMinOfArray(a, n) << endl;
    // cout << findMaxOfArray(a, n);
    cout << calculateSumOfDigitOfNumber(555555);

    return 0;
}

void print1toN(int n) {
    if(n > 0){
        print1toN(n - 1);
        cout << n  << " ";
    }

}

void printNto1(int n) {
    if(n > 0){
        cout << n << " ";
        printNto1(n - 1);
    }

}

float calculateMeanOfArray(int a[], int n) {
    if(n == 1)
        return (float)a[n - 1];
    else
        return ((float)(calculateMeanOfArray(a, n - 1) * (n - 1) + a[n - 1]) / n); 
}

int calculateSumOfNatural(int a[], int n) {
    if(n == 1)
        return a[n - 1];
    else 
        return calculateSumOfNatural(a, n - 1) + a[n - 1];
}

string reverseString(string str) {
    if(str.size() == 0)
        return str;
    else    
        return reverseString(str.substr(1)) + str[0];
}

int calculateLengthOfString(string str) {
    if(str == "")
        return 0;   
    return calculateLengthOfString(str.substr(1)) + 1; 
}

int calculateSumOfDigitOfNumber(int n) {
    if(n == 0)
        return 0;
    return (n % 10 + calculateSumOfDigitOfNumber(n / 10));
}

int findFibonacci(int n) {
    if(n == 0 || n == 1)
        return 1;
    return findFibonacci(n - 2) + findFibonacci(n - 1);
}

vector<int> printFibonacciNumbers(int n){
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(findFibonacci(i));
    }
    return vec;

}

long long calculateFactorial(int n) {
    if(n <= 1)
        return 1;
    return calculateFactorial(n - 1)* n;
}

int findMinOfArray(int a[], int n) {
    if(n == 1)
        return a[0];
    return min(a[n - 1], findMinOfArray(a, n - 1));
}

int findMaxOfArray(int a[], int n) {
    if(n == 1)
        return a[0];
    return max(a[n - 1], findMaxOfArray(a, n - 1));
}

string removeDuplicateCharacter(string str) {


}














