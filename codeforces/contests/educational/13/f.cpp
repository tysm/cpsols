#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int q;
    cin >> q;
    map<int, ii> arr;
    multiset<ii> byap, byan, bybp, bybn;
    multiset<ii> byap1, byan1, bybp1, bybn1;
    for(int i=1; i<=q; ++i){
        int op;
        cin >> op;
        if(op == 1){
            int a, b;
            cin >> a >> b;
            arr[i] = {a, b};

            byap.insert({-a, -b});
            byap1.insert({-a, b});
            bybp.insert({-b, -a});
            bybp1.insert({b, -a});
            byan.insert({a, -b});
            byan1.insert({a, b});
            bybn.insert({-b, a});
            bybn1.insert({b, a});
        }
        else if(op == 2){
            int j;
            cin >> j;
            int a = arr[j].ff, b = arr[j].ss;
            if(byap.lower_bound({-a, -b}) != byap.end()){
                byap.erase(byap.lower_bound({-a, -b}));
                bybp.erase(bybp.lower_bound({-b, -a}));
                byan.erase(byan.lower_bound({a, -b}));
                bybn.erase(bybn.lower_bound({-b, a}));
                byap1.erase(byap1.lower_bound({-a, b}));
                bybp1.erase(bybp1.lower_bound({b, -a}));
                byan1.erase(byan1.lower_bound({a, b}));
                bybn1.erase(bybn1.lower_bound({b, a}));
            }
        }
        else{
            int x;
            cin >> x;
            if(byap.empty())
                cout << "EMPTY SET" << endl;
            else{
                set<int> ans;
                int a = -(*byap.begin()).ff, b = -(*byap.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                b = -(*bybp.begin()).ff;
                a = -(*bybp.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                a = (*byan.begin()).ff;
                b = -(*byan.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                b = -(*bybn.begin()).ff;
                a = (*bybn.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                a = -(*byap1.begin()).ff;
                b = (*byap1.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                b = (*bybp1.begin()).ff;
                a = -(*bybp1.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                a = (*byan1.begin()).ff;
                b = (*byan1.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                b = (*bybn1.begin()).ff;
                a = (*bybn1.begin()).ss;
                ans.insert(-(a*x + b));
                ans.insert(-(b*x + a));

                cout << -(*ans.begin()) << endl;
            }
        }
    }
    return 0;
}

