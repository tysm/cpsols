#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

int n;
vector<point<int> > arr(6), tab(6);

bool solve(vi &per){
    vector<segment<int> > aux;
    for(int i=0; i<n; ++i){
        int j = per[i];

        segment<int> cur(arr[i], tab[j]);
        for(auto &l:aux){
            if(intersect(cur, l))
                return false;
        }
        aux.eb(cur);
    }
    return true;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for(int i=0; i<n; ++i)
            cin >> arr[i].x >> arr[i].y;

        for(int i=0; i<n; ++i)
            cin >> tab[i].x >> tab[i].y;

        vector<int> per(n);
        iota(all(per), 0);
        do{
            if(!solve(per))
                continue;
            for(int i=0; i<n; ++i){
                int j = per[i];

                cout << 2 << endl;
                cout << arr[i].x << ' ' << arr[i].y << endl;
                cout << tab[j].x << ' ' << tab[j].y << endl;
            }
            break;
        }while(next_permutation(all(per)));
    }
    return 0;
}
