#include<bits/stdc++.h>

using namespace std;


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
int main() {
	char t[] = "Ban Viet o Viet Nam, Viet co ban gai ten la Viet Ngan";
    char p[] = "Viet";
	cout << F1(t, p) << endl;


}