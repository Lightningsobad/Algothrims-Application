#include<bits/stdc++.h>

using namespace std;


// void A1(string person[], char chair[], string* personResult, bool* flag, int n, int k);
// void showResult(string* personResult, char chair[]);

void showResult(string* personResult, char chair[]) {
    for (int i = 0; i < 4; i++)
    {
        cout << personResult[i] << " - " << chair[i] << endl;
    }
    cout << "-----------------" << endl;
    
    


}

void A1(string person[], char chair[], string* personResult, bool* flag, int n, int k) {
    for (int i = 0; i < n; i++)
    {
        if(flag[i] == false){
            personResult[k] = person[i];
            if(k == n - 1){
                showResult(personResult, chair);
            }
            else{
                flag[i] = true;
                A1(person, chair, personResult, flag, n, k + 1);
                flag[i] = false;
            }
                

        }
        
        
    }
    



}

int main() {
    int n = 4;
    char chair[] = {'A', 'B', 'C', 'D'};
    string person[] = {"Tung", "Cuc", "Truc", "Mai"};
    string* personResult = new string[n];
    bool* flag = new bool[n];
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
    }
    A1(person, chair, personResult, flag, n, 0);
    




    return 0;

}




















