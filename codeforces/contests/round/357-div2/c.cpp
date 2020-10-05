#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    int n;
    cin >> n;

    vector<pair<string, int> > ans;

    min_heap<int> pq;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;

        if(s == "insert"){
            int x;
            cin >> x;

            pq.ep(x);

            ans.eb(s, x);
        }
        else if(s == "getMin"){
            int x;
            cin >> x;

            while(!pq.empty() and pq.top() < x){
                pq.pop();

                ans.eb("removeMin", 0);
            }
            if(pq.empty() or pq.top() > x){
                pq.ep(x);

                ans.eb("insert", x);
            }

            ans.eb(s, x);
        }
        else{
            if(pq.empty())
                ans.eb("insert", 1);
            else
                pq.pop();

            ans.eb(s, 0);
        }
    }

    cout << ans.size() << endl;
    for(auto p : ans){
        if(p.ff == "removeMin")
            cout << p.ff << endl;
        else
            cout << p << endl;
    }
    return 0;
}
