#include<bits/stdc++.h>

using namespace std;

struct Laptop
{
    char ten_hangsx[30]; 
    char cau_hinh[80];
    double gia_ban;
};

void hien_thi_ket_qua(Laptop* r, int n){
    for (int i = 0; i < n; i++)
    {
        cout << r[i].ten_hangsx << " - " << r[i].gia_ban << endl;
    }
    
}

int char_in_string(char ch, char* s){
    int x = 0;
    while (s[x] != '\0')
    {
        if(s[x] == ch)
            return x;
        x++;
    }
    return -1;
    
}

int F1(char* t, char * p) {
    int v = strlen(p);
    int i = v - 1;
    while (i < strlen(t))
    {
        int k = v - 1;
        while(k > -1 && t[i] == p[k]){
            k--;
            i--;
        }
        if(k < 0){
            return i + 1;
        }
        else{
            int x = char_in_string(t[i], p);
            if(x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return -1;
}

void F3(Laptop d[], int n, int &r){
    int result[n];
    r = 0;
    char p[] = "RAM 16GB";
    for (int i = 0; i < n; i++)
    {
        result[i] = F1(d[i].cau_hinh, p);
    }
    for (int i = 0; i < n; i++)
    {
        if(result[i] > 0)
            r++;
    }
}

bool F2(char* t, char* p){
    int p_size = strlen(p);
    int t_size = strlen(t);
    char s[p_size + t_size + 2];
    strcpy(s, p);
    strcat(s, "$");
    strcat(s, t);
    int n = strlen(s);
    int* z = new int[n];
    int left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if(i > right){
            left = right = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }else if(z[i - left] < right - i + 1)
            z[i] = z[i - left];
        else{
            left = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(z[i] == p_size)
            return true;
    }
    return false;
}

void F4(Laptop d[], int n, int &s, Laptop* t){
    s = 0;
    char p[] = "SSD";
    Laptop result[n];
    for (int i = 0; i < n; i++)
    {
        if(F2(d[i].cau_hinh, p)){
            s++;
            t[s - 1] = d[i];
        }     
    }   
}


int main() {
    int n = 5;
    Laptop d[n] ={
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 150000},
        {"Lenovo", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-SSD 1TB", 120000},
        {"Acer", "CPU 2.0GHz upto 3.6GHz-RAM 32GB-HDD 512GB", 190000},
        {"Asus", "CPU 3.0GHz upto 4.0GHz-RAM 16GB-SSD 2TB", 250000},
        {"MSI", "CPU 2.5GHz upto 4.0GHz-RAM 16GB-HDD 512GB", 200000},
    };
    int r;
    F3(d, n, r);
    cout << "Số lượng máy tính có RAM 16GB: " << r << endl;
    Laptop* t = new Laptop[5];
    int s;
    F4(d, n, s, t);
    cout << "Số lượng máy tính dùng ổ SSD: " << s << endl;
    hien_thi_ket_qua(t, s);
}