#define double long double
#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

bool check(point<int> &P, vector<point<int> > &A, point<int> &Q, vector<point<int> > &B){
    double R = distance(P, Q);
    for(auto &K:B){
        point<int> C = P - Q + K;
        for(int i=0; i<A.size(); ++i){
            int j = (i+1)%A.size();
            double D = distance(C, segment<int>(A[i], A[j]));
            if(D <= R and max(distance(C, A[i]), distance(C, A[j])) >= R)
                return true;
        }
    }
    return false;
}

int32_t main(){
    desync();

    point<int> P;
    cin >> P.x >> P.y;

    int n;
    cin >> n;
    vector<point<int> > A(n);
    for(auto &i:A)
        cin >> i.x >> i.y;

    point<int> Q;
    cin >> Q.x >> Q.y;

    int m;
    cin >> m;
    vector<point<int> > B(m);
    for(auto &i:B)
        cin >> i.x >> i.y;

    cout << (check(P, A, Q, B) or check(Q, B, P, A)? "YES" : "NO") << endl;
    return 0;
}
