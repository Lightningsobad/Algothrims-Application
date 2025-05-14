#include<bits/stdc++.h>

using namespace std;

int char_in_string(char ch, char *s){
    int x = 0;
    while (s[x] != '\0')
    {
        if(s[x] == ch)
            return x;
        x++;
    }
    return -1;
}

bool BMH(char* t, char* p){
    int v = strlen(p);
    int i = v - 1;
    while (i < strlen(t))
    {
        int k = v - 1;
        //so sánh xâu con của t với p từ cuối về đầu
        while (k > -1 && t[i] == p[k])
        {
            k--;
            i--;
        }
        if(k < 0) //vượt qua được xâu p
            return true;
        else{
            int x = char_in_string(t[i], p);
            if(x < 0)               //t[i] không có trong p
                i = i + v;
            else                    //p[x] = t[i],  t[i] có trong p
                i = i + v - x - 1;
    }
    }
    return false;
}

int main() {
    char t[] = "hanoivietnam";
    char p[] = "hello";
    bool result = BMH(t, p);
    if(result)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}