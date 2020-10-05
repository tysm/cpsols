#include <cpplib/stdinc.hpp>

string del(vi &arr, string &s, int k){
    set<int> vis;
    for(int i=0; i<k; ++i)
        vis.ep(arr[i]);

    string res;
    for(int i=0; i<s.size(); ++i){
        if(vis.count(i))
            continue;
        res += s[i];
    }
    return res;
}

bool check(const string &s, string &t){
    int i=0, j=0;
    for(; i<s.size() and j<t.size(); ++i){
        if(s[i] == t[j])
            j++;
    }
    return j == t.size();
}

int32_t main(){
    desync();
    string s, t;
    cin >> s >> t;

    int n = s.size();
    vi arr(n);
    for(int &i:arr){
        cin >> i;
        i--;
    }

    int lo = 0, hi = n, ans = n;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(check(del(arr, s, mid), t)){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
