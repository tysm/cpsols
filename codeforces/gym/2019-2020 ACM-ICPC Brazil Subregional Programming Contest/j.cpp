#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define INF (int32_t(1e9)+1)
using namespace std;

struct player{
    vi cards;

    player() : cards(vi(14, 0)) {}

    bool win(){
        for(auto i:cards){
            if(i >= 4)
                return true;
        }
        return false;
    }

    void add_card(int i){
        cards[i]++;
    }

    int get_card(bool wildcard){
        int res;
        if(wildcard and cards[0])
            res = 0;
        else{
            res = 1;
            for(int i=2; i<14; ++i){
                if(!cards[res] or (cards[i] > 0 and cards[i] < cards[res]))
                    res = i;
            }
        }
        cards[res]--;
        return res;
    }
};


int32_t main(){
    int n, k;
    cin >> n >> k;
    k--;
    map<char, int> ctoint = {
        {'A', 1},
        {'D', 10},
        {'Q', 11},
        {'J', 12},
        {'K', 13}
    };
    for(int i=2; i<=9; ++i)
        ctoint[(char)('0'+i)] = i;

    vector<player> v(n, player());
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            char c;
            cin >> c;
            v[i].add_card(ctoint[c]);
        }
        if(v[i].win() and i != k){
            cout << i+1 << endl;
            return 0;
        }
    }

    int card = 0;
    while(true){
        bool wildcard = card != 0;
        v[k].add_card(card);
        card = v[k].get_card(wildcard);
        if(v[k].win())
            break;
        k = (k+1)%n;
    }
    cout << k+1 << endl;
    return 0;
}
