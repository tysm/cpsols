#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vector<set<int> > adj(n+1);
    stack<int> stp;
    for(int i=0; i<2*n; ++i){
        string s;
        cin >> s;
        int x;
        cin >> x;
        if(s == "in"){
            if(!stp.empty()){
                int p = stp.top();
                adj[p].emplace(x);
            }
            stp.emplace(x);
        }
        else
            stp.pop();
    }
    for(int i=1; i<=n; ++i){
        for(int j:adj[i])
            cout << j << ' ' << i << endl;
    }
    return 0;
}
