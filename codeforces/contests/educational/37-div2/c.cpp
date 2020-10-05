#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    string s;
    cin >> s;
    s += '0';
    for(int i=0; i<n; ++i){
        if(s[i] == '1'){
            int j = i+1;
            while(s[j] != '0')
                j++;
            sort(arr.begin()+i, arr.begin()+j+1);
            i = j-1;
        }
    }

    cout << (is_sorted(all(arr))? "Yes" : "No") << endl;
    return 0;
}
