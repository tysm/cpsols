#include <cpplib/stdinc.hpp>

int n, k;
bool check_win(string &s){
    vi pos0, pos1;
    for(int i=0; i<n; ++i){
        if(s[i] == '0')
            pos0.eb(i);
        else
            pos1.eb(i);
    }

    if(pos0.empty() or pos1.empty())
        return true;
    if(min((int)(pos0.back()-pos0[0]+1), (int)(pos1.back()-pos1[0]+1)) <= k)
        return true;
    return false;
}

int32_t main(){
    desync();
    cin >> n >> k;

    string s;
    cin >> s;


    if(check_win(s)){
        cout << "tokitsukaze" << endl;
        return 0;
    }

    vi pos0, pos1;
    for(int i=0; i<n; ++i){
        if(s[i] == '0')
            pos0.eb(i);
        else
            pos1.eb(i);
    }

    bool lose = true;
    for(int i=0; i<n-k; ++i){
        int l = lower_bound(all(pos0), i) - pos0.begin();
        int r = pos0.end() - lower_bound(all(pos0), i+k);
        if(l and r){
            lose = false;
            break;
        }
        else if(l and pos0[l-1]-pos0[0]+1 > k){
            lose = false;
            break;
        }
        else if(r and pos0.back()-pos0[pos0.size()-r]+1 > k){
            lose = false;
            break;
        }

        l = lower_bound(all(pos1), i) - pos1.begin();
        r = pos1.end() - lower_bound(all(pos1), i+k);
        if(l and r){
            lose = false;
            break;
        }
        else if(l and pos1[l-1]-pos1[0]+1 > k){
            lose = false;
            break;
        }
        else if(r and pos1.back()-pos1[pos1.size()-r]+1 > k){
            lose = false;
            break;
        }
    }

    if(lose){
        cout << "quailty" << endl;
        return 0;
    }

    cout << "once again" << endl;
    return 0;
}
