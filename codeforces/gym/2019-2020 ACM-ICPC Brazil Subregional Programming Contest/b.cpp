#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int first, other, win = true;
    cin >> first;
    for(int i=1; i<n; ++i){
        cin >> other;
        if(first < other)
            win = false;
    }
    cout << (win? 'S':'N') << endl;
    return 0;
}
