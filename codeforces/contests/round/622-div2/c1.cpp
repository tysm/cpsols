#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi rgt(n), lft(n);

    stack<ii> st;
    for(int i=n-1; i>=0; --i){
        rgt[i] = arr[i];

        while(!st.empty() and st.top().ff > arr[i])
            st.pop();

        int j = n;
        if(!st.empty())
            j = st.top().ss;

        if(j < n)
            rgt[i] += rgt[j];
        rgt[i] += (j-1-i)*arr[i];

        st.ep(arr[i], i);
    }

    while(!st.empty())
        st.pop();
    for(int i=0; i<n; ++i){
        lft[i] = arr[i];

        while(!st.empty() and st.top().ff > arr[i])
            st.pop();

        int j = -1;
        if(!st.empty())
            j = st.top().ss;

        if(j >= 0)
            lft[i] += lft[j];
        lft[i] += (i-1-j)*arr[i];

        st.ep(arr[i], i);
    }

    vi res(n);
    for(int i=0; i<n; ++i)
        res[i] = lft[i] + rgt[i] - arr[i];

    int ans = 0;
    for(int i=1; i<n; ++i){
        if(res[i] > res[ans])
            ans = i;
    }

    vi out(arr);
    for(int i=ans+1; i<n; ++i)
        out[i] = min(out[i], out[i-1]);
    for(int i=ans-1; i>=0; --i)
        out[i] = min(out[i], out[i+1]);
    cout << out << endl;
    return 0;
}
