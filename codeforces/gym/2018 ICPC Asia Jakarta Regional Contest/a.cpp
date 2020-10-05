#include <cpplib/stdinc.hpp>
#include <cpplib/string/distance.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;

    int cnt[2] = {};
    for(char c:s)
        cnt[c-'0']++;

    if(cnt[0] > cnt[1]){
        for(int i=0; i<s.size(); ++i)
            cout << 1;
        cout << endl;
    }
    else if(cnt[1] > cnt[0]){
        for(int i=0; i<s.size(); ++i)
            cout << 0;
        cout << endl;
    }
    else{
        string ans1 = s, ans2 = s;
        sort(all(ans1));
        sort(rall(ans2));
        if(distance(s, ans1) > distance(s, ans2))
            cout << ans1 << endl;
        else
            cout << ans2 << endl;
    }
    return 0;
}
