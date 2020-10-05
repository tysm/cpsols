#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int p, f;
        cin >> p >> f;
        if(p < f)
            swap(p, f);

        int n, m;
        cin >> n >> m;

        int s, w;
        cin >> s >> w;

        if(s > w){
            swap(n, m);
            swap(s, w);
        }

        int ans = 0;
        for(int i=0; i<=n; ++i){
            int auxn = n, auxm = m;
            int auxp = p, auxf = f;

            auxp -= i*s;
            if(auxp < 0)
                continue;
            auxn -= i;
            int cur = i;

            int j = min(auxm, auxp/w);
            auxp -= j*w;
            auxm -= j;
            cur += j;

            int l = min(auxn, auxf/s);
            auxf -= l*s;
            auxn -= l;
            cur += l;

            int k = min(auxm, auxf/w);
            auxf -= k*w;
            auxm -= k;
            cur += k;

            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
