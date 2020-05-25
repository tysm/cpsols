#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int mid = (1LL<<(m-1))-1, prev = mid-1, next = mid+1;

        set<int> vis;
        for(int i=0, odd=0; i<n; ++i){
            string s;
            cin >> s;

            int si = 0;
            for(int j=1LL<<(m-1), l=0; j>0 and l<m; j>>=1, ++l){
                if(s[l] == '1')
                    si |= j;
            }
            vis.insert(si);

            if(si == prev)
                while(vis.count(--prev));
            if(si == next)
                while(vis.count(++next));

            if(odd){
                if(si >= mid){
                    if(si != mid)
                        next = mid;
                    mid = prev;
                    while(vis.count(--prev));
                }
            }
            else if(si <= mid){
                if(si != mid)
                    prev = mid;
                mid = next;
                while(vis.count(++next));
            }
            odd ^= 1;
        }
        for(int j=1LL<<(m-1); j>0; j>>=1)
            cout << (bool)(mid & j);
        cout << endl;
    }
    return 0;
}
