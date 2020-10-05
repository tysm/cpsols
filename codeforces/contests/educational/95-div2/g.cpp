#include <cpplib/stdinc.hpp>
#include <cpplib/utility/random.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<uint> rng(n+1), freq(n+1);
    for(int i=0; i<=n; ++i)
        rng[i] = randint(-1e18, 1e18);
    vector<queue<int> > lst3(n+1);

    vector<uint> hsh(n+1);
    map<uint, int> hsh_freq;
    hsh_freq[0]++;

    int ini = 0, ans = 0;
    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;

        if(lst3[x].size() >= 3){
            int idx = lst3[x].front();
            lst3[x].pop();

            while(ini <= idx){
                hsh_freq[hsh[ini]]--;
                ini++;
            }
        }

        int f = freq[x];
        freq[x] = (freq[x] + 1)%3;
        hsh[i] = hsh[i-1] + (freq[x] - f)*rng[x];
        ans += hsh_freq[hsh[i]];
        hsh_freq[hsh[i]]++;
        lst3[x].ep(i-1);
    }
    cout << ans << endl;
    return 0;
}
