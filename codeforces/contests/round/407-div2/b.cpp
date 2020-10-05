#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int b1, q, l, m;
    cin >> b1 >> q >> l >> m;

    set<int> bad;
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        bad.ep(x);
    }

    if(abs(b1) > l){
        // don't write.
        cout << 0 << endl;
        return 0;
    }

    if(b1 == 0){
        // inf zero sequence.
        if(bad.count(b1))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }

    if(q == 0){
        // b1 0 0 0 0 ....
        if(bad.count(0)){
            if(bad.count(b1))
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
            cout << "inf" << endl;
        return 0;
    }

    if(q == 1){
        // b1 b1 b1 b1 b1 ...
        if(bad.count(b1))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }

    if(q == -1){
        // b1 -b1 b1 -b1 ....
        if(bad.count(b1) and bad.count(-b1))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }

    set<int> seq;
    int bi = b1;
    while(abs(bi) <= l){
        seq.ep(bi);
        bi = bi*q;
    }

    int ans = seq.size();
    for(int i:bad){
        if(seq.count(i))
            ans--;
    }
    cout << ans << endl;
    return 0;
}
