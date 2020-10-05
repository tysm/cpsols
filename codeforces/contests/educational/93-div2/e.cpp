#include <cpplib/stdinc.hpp>

int lcnt, lin, fin, lout, fout, ans;
multiset<int> cur2l, cur2f, curl, curf;

void balance(){
    if(lin + fin > lcnt){
        if(lin > 0 and lin == lcnt){
            int x = *cur2l.begin();
            cur2l.erase(cur2l.begin());
            ans -= x;
            lin--;
            lout++;
            curl.ep(x);
        }
        else{
            int x = *cur2f.begin();
            cur2f.erase(cur2f.begin());
            ans -= x;
            fin--;
            fout++;
            curf.ep(x);
        }
    }
    while(lin + fin < lcnt and (lin < lcnt-1 and lout or fout)){
        if(lin < lcnt-1 and lout and fout){
            int x = -(*curl.begin()), y = -(*curf.begin());
            if(x > y){
            }
        }
        else if(lin < lcnt-1 and lout){
        }
        else{
        }
    }
}

void insert(int tp, int x){
    if(tp){
        lcnt++;
        curl.ep(-x);
        lout++;
    }
    else{
        curf.ep(-x);
        fout++;
    }
    ans += x;
    balance();
}

void remove(int tp, int x){
    if(tp){
        lcnt--;
        if(curl.count(-x)){
            curl.erase(curl.find(-x));
            lout--;
        }
        else{
            cur2l.erase(cur2l.find(x));
            lin--;
        }
    }
    else{
        if(curf.count(-x)){
            curf.erase(curf.find(-x));
            fout--;
        }
        else{
            cur2f.erase(cur2f.find(x));
            fin--;
        }
    }
    ans -= x;
    balance();
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int tp, x;
        cin >> tp >> x;

        if(x > 0)
            insert(tp, x);
        else
            remove(tp, -x);

        cout << ans << endl;
    }
    return 0;
}
