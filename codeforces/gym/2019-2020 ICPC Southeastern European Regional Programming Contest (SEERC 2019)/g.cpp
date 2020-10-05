#include <cpplib/stdinc.hpp>

int n, m, h;
vtt solve_max(vector<string> &g1, vector<string> &g2){
    vtt res_max;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            for(int k=0; k<h; ++k){
                if(g1[i][j] == '1' and g2[i][k] == '1')
                    res_max.eb(i, j, k);
            }
        }
    }
    return res_max;
}

vtt solve_min(vector<string> &g1, vector<string> &g2){
    vtt res_min;

    for(int i=0; i<n; ++i){
        vi inj, ink;
        for(int j=0; j<m; ++j){
            if(g1[i][j] == '1')
                inj.eb(j);
        }
        for(int k=0; k<h; ++k){
            if(g2[i][k] == '1')
                ink.eb(k);
        }

        if(!inj.empty() and ink.empty())
            return vtt();
        if(inj.empty() and !ink.empty())
            return vtt();


        if(inj.size() == ink.size()){
            for(int l=0; l<inj.size(); ++l)
                res_min.eb(i, inj[l], ink[l]);
        }
        else{
            if(inj.size() > ink.size()){
                int d = inj.size()-ink.size();
                for(int l=0; l<d; ++l)
                    res_min.eb(i, inj[l], ink[0]);
                for(int l=d; l<inj.size(); ++l)
                    res_min.eb(i, inj[l], ink[l-d]);
            }
            else{
                int d = ink.size()-inj.size();
                for(int l=0; l<d; ++l)
                    res_min.eb(i, inj[0], ink[l]);
                for(int l=d; l<ink.size(); ++l)
                    res_min.eb(i, inj[l-d], ink[l]);
            }
        }
    }
    sort(all(res_min));
    return res_min;
}

int32_t main(){
    desync();
    cin >> n >> m >> h;

    bool some = false;
    vector<string> g1(n), g2(n);
    for(string &s:g1){
        cin >> s;
        for(char c:s){
            if(c == '1')
                some = true;
        }
    }
    for(string &s:g2){
        cin >> s;
        for(char c:s){
            if(c == '1')
                some = true;
        }
    }

    auto res_max = solve_max(g1, g2), res_min = solve_min(g1, g2);
    if(some and res_min.empty()){
        cout << -1 << endl;
        return 0;
    }

    cout << res_max.size() << endl;
    for(auto [i, j, k] : res_max){
        cout << i << ' ' << j << ' ' << k << endl;
    }
    cout << res_min.size() << endl;
    for(auto [i, j, k] : res_min){
        cout << i << ' ' << j << ' ' << k << endl;
    }
    return 0;
}
