#include <cpplib/stdinc.hpp>
#include <cpplib/adt/ost.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));

    multiset<int> ans;
    ans.ep(0);

    ost_set<int> st;
    for(int i=0; i<n; ++i){
        st.insert(arr[i]);
        if(i)
            ans.ep(-(arr[i]-arr[i-1]));
    }
    cout << arr[n-1] - arr[0] + (*ans.begin()) << endl;

    while(q--){
        int op, x;
        cin >> op >> x;
        if(op){
            st.insert(x);
            int i = st.order_of_key(x);

            if(i){
                int lft = *st.find_by_order(i-1);
                ans.ep(-(x-lft));
            }
            if(i < st.size()-1){
                int rgt = *st.find_by_order(i+1);
                ans.ep(-(rgt-x));
            }
            if(i and i < st.size()-1){
                int lft = *st.find_by_order(i-1);
                int rgt = *st.find_by_order(i+1);
                ans.erase(ans.find(-(rgt-lft)));
            }
        }
        else{
            int i = st.order_of_key(x);
            if(i){
                int lft = *st.find_by_order(i-1);
                ans.erase(ans.find(-(x-lft)));
            }
            if(i < st.size()-1){
                int rgt = *st.find_by_order(i+1);
                ans.erase(ans.find(-(rgt-x)));
            }
            if(i and i < st.size()-1){
                int lft = *st.find_by_order(i-1);
                int rgt = *st.find_by_order(i+1);
                ans.ep(-(rgt-lft));
            }
            st.erase(x);
        }
        int rgt = *st.find_by_order(st.size()-1), lft = *st.begin();
        cout << rgt-lft + *ans.begin() << endl;
    }
    return 0;
}
