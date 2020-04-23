#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/trie.hpp>

string s;
Trie<> ptree;
vi dp;

int ways(int i){
    if(i==s.size())
        return 1;

    if(dp[i] != -1)
        return dp[i];

    int ans = 0;
    Trie<>::Node* cur = ptree.node_at("");
    for(int j=i; j<s.size(); ++j){
        if(cur->exists(s[j]))
            cur = cur->next(s[j]);
        else
            break;
        if(cur->words != 0)
            ans = (ans + ways(j+1))%M;
    }
    return dp[i] = ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1731
    desync();
    cin >> s;
    dp.resize(s.size(), -1);

    int k;
    cin >> k;
    while(k--){
        string ki;
        cin >> ki;
        ptree.insert(ki);
    }
    cout << ways(0) << endl;
    return 0;
}
