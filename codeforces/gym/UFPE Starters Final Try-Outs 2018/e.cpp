#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    int n = s.size(), k;
    cin >> k;

    int ans = n;
    map<ii, int> kpal, kpale, kpalo;
    for(int i=0; i<n; ++i)
        kpalo[{i, i}] = 0;
    for(int i=0; i<n-1; ++i){
        if(s[i] == s[i+1])
            kpale[{i, i+1}] = 0;
        else
            kpale[{i, i+1}] = 1;
        if(kpale[{i, i+1}] <= k)
            ans++;
    }
    for(int g=2; g<n; ++g){
        kpal.clear();
        if((g+1)%2){
            for(int i=0; i<n-g; ++i){
                int j = i + g;
                if(s[i] == s[j])
                    kpal[{i, j}] = kpalo[{i+1, j-1}];
                else
                    kpal[{i, j}] = kpalo[{i+1, j-1}]+1;
                if(kpal[{i, j}] <= k)
                    ans++;
            }
            swap(kpal, kpalo);
        }
        else{
            for(int i=0; i<n-g; ++i){
                int j = i + g;
                if(s[i] == s[j])
                    kpal[{i, j}] = kpale[{i+1, j-1}];
                else
                    kpal[{i, j}] = kpale[{i+1, j-1}]+1;
                if(kpal[{i, j}] <= k)
                    ans++;
            }
            swap(kpal, kpale);
        }
    }
    cout << ans << endl;
    return 0;
}
