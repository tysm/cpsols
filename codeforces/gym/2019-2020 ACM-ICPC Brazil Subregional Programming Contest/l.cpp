#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    bitset<64> s(n);
    cout << (1LL<<s.count()) << endl;
    return 0;
}
