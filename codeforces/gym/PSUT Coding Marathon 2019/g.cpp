#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, b;
    cin >> n >> b;

    set<int> st;
    for(int i=0; i<b; ++i)
        st.insert(i);

    vi arr(n);
    int rep = 0;
    map<int, int> cnt;
    for(int &i:arr){
        cin >> i;
        st.erase(i);
        cnt[i]++;
        if(cnt[i] == 2)
            rep++;
    }
    reverse(all(arr));

    bool ok = false;
    for(int i=0; i<n and !ok; ++i){
        int cur = arr[i];

        cnt[cur]--;
        if(cnt[cur] == 1)
            rep--;
        else if(cnt[cur] == 0)
            st.insert(cur);

        if(cur == b-1 or rep)
            continue;

        auto it = st.upper_bound(cur);
        if(it == st.end())
            continue;
        ok = true;

        int res = *it;
        st.erase(it);

        arr[i] = res;
        for(int j=i-1; j>=0; --j){
            arr[j] = *st.begin();
            st.erase(st.begin());
        }
    }
    if(ok){
        reverse(all(arr));
        cout << arr << endl;
    }
    else{
        vi ans(n+1);
        ans[0] = 1;
        ans[1] = 0;
        for(int i=2; i<n+1; ++i)
            ans[i] = i;
        cout << ans << endl;
    }
    return 0;
}
