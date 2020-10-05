#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<string> arr(n);
    for(string &s:arr)
        cin >> s;
    reverse(all(arr));

    multiset<int> res;
    min_heap<pair<string, int> > pq;
    for(int msc=1; msc < (1<<arr[0].size()); ++msc){
        string gen;
        for(int j=0; j<arr[0].size(); ++j){
            if(msc & (1<<j))
                gen += arr[0][j];
        }
        debug(gen, -(int)gen.size());
        pq.ep(gen, gen.size());
        res.ep(-(int)gen.size());
    }

    bool ok = true;
    for(int i=1; i<n; ++i){
        multiset<int> new_res;
        min_heap<pair<string, int> > new_pq;

        vector<string> to_process;
        for(int msc=1; msc < (1<<arr[i].size()); ++msc){
            string gen;
            for(int j=0; j<arr[i].size(); ++j){
                if(msc & (1<<j))
                    gen += arr[i][j];
            }
            to_process.eb(gen);
        }
        sort(all(to_process));

        debug(i);
        for(string &s:to_process){
            debug(s, pq.top());
            while(!pq.empty() and pq.top().ff <= s){
                auto [t, v] = pq.top();
                pq.pop();
                res.erase(res.find(-v));
            }
            if(pq.empty())
                break;
            int v = -(*res.begin()) + s.size();
            new_res.ep(-v);
            new_pq.ep(s, v);
        }

        swap(res, new_res);
        swap(pq, new_pq);

        if(pq.empty())
            ok = false;
    }
    if(!ok)
        cout << -1 << endl;
    else
        cout << -(*res.begin()) << endl;
    return 0;
}
