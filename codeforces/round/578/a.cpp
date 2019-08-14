#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int hotel[10]={};
    while(n--){
        char c;
        cin >> c;
        switch(c){
            case 'L':
                for(int i=0; i<10; ++i){
                    if(!hotel[i]){
                        hotel[i] = 1;
                        break;
                    }
                }
                break;
            case 'R':
                for(int i=9; i>=0; --i){
                    if(!hotel[i]){
                        hotel[i] = 1;
                        break;
                    }
                }
                break;
            default:
                int cint = c - '0';
                hotel[cint] = 0;
                break;
        }
    }
    for(int i=0; i<10; ++i)
        cout << hotel[i];
    cout << endl;
}
