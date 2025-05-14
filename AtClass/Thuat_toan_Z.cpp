#include<bits/stdc++.h>

using namespace std;

void z_algo(char* s, int* z){
    int n = strlen(s), left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if(i > right) {
            left = right = i;
            while (right < n && s[right - left] == s[right])
            {
                right++;
            }
            z[i] = right - left;
            right--;
        }
        else if(z[i - left] < right - i + 1)
            z[i] = z[i - left];
        else{
            left = i;
            while(right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }
    }
}

int z_app(char* t, char* p){
    int p_size = strlen(p);
    int t_size = strlen(t);
    char s[p_size + t_size + 2];
    strcpy(s, p);
    strcat(s, "$");
    strcat(s, t);
    int n = strlen(s);
    int count = 0;
    int* z = new int[n];
    z_algo(s, z);
    for (int i = 0; i < n; i++)
    {
        if(z[i] == p_size)
            count++;
    }
    return count;
}

int main() {
    char t[] = "Ban Viet o Viet Nam, Viet co ban gai ten la Viet Ngan";
    char p[] = "Viet";
    int count = z_app(t, p);
    cout << count << endl;


}