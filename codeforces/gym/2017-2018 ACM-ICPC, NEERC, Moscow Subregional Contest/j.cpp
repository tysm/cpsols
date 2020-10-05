#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

double sqarea2(vector<point<double> > &pol){
    int n = pol.size();
    double res = 0;
    for(int i=0, j=1; i<n; ++i, j = (j+1)%n)
        res += squared_norm(pol[i]^pol[j]);
    return res;
}

vector<point<double> > cutpols(segment<double> l, segment<double> r, segment<double> u, segment<double> d, vector<point<double> > &pol){
    int n = pol.size();
    vector<point<double> > res;
    for(int i=0, j = ; i<n; ++i, j = (j+1)%n)
    for(auto &p:pol){
        vector<point<double> > cur;

        for(int i=
    }
    return res;
}

int32_t main(){
    desync();
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<point<double> > > pols(n);
    for(auto &v:pols){
        int x, y;
        for(int i=0; i<3; ++i){
            cin >> x >> y;
            v.eb(x, y);
        }
    }
    double wlo = 0, whi = w, hlo = 0, hhi = h;
    while(true){
        if(abs(wlo - whi) <= EPS or abs(hlo - hhi) <= EPS)
            break;
        vector<pair<double, int> > aux;
        sort(all(aux));
        int res = aux[0].ss;
        if(res == 1){
        }
        else if(res == 2){
        }
        else if(res == 3){
        }
        else{
        }
    }
    cout << fixed << setprecision(9) << wlo << ' ' << hlo << endl;
    return 0;
}

