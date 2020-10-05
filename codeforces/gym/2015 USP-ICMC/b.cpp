#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int k;
    cin >> k;
    vector<pair<string, string> > arr;
    vector<map<char, int> > cnt(k);
    for(int i=0; i<k; ++i){
        string nick, gang;
        cin >> nick >> gang;
        arr.pb({nick, gang});
        for(char c:nick)
            cnt[i][c]++;
        for(char c:gang)
            cnt[i][c]++;
    }
    vii ans;
    for(int i=0; i<k; ++i){
        int n, m;
        cin >> n >> m;
        map<char, int> aux_cnt;
        for(int j=0; j<n; ++j){
            for(int l=0; l<m; ++l){
                char c;
                cin >> c;
                aux_cnt[c]++;
            }
        }
        int acc = INF;
        for(pair<char, int> p:cnt[i]){
            char c = p.ff;
            acc = min(acc, aux_cnt[c]/p.ss);
        }
        ans.pb({-acc, i});
    }
    sort(all(ans));
    cout << arr[ans[0].ss].ff << ' ' << arr[ans[0].ss].ss << endl;
    return 0;
}
