#include <cpplib/stdinc.hpp>

double intern(int n){
    return (n-2)*180.0/n;
}

double atri(double l, int n){
    double ang = 90-intern(n)/2;
    ang *= PI;
    ang /= 180.0;
    return sin(ang)*cos(ang)*(l/2)*(l/2);
}

double new_l(double l, int n){
    double ang = 90-intern(n)/2;
    ang *= PI;
    ang /= 180.0;
    return 2*cos(ang)*(l/2);
}

double lado(int n, double area){
    return sqrt(area*4*tan(PI/n)/n);
}

int32_t main(){
    int n;
    cin >> n;
    double past = lado(n, 1);
    debug(n*atri(past, n));
    double l = new_l(past, n);
    for(int i=1; i<10; ++i){
        debug(atri(past, n)/atri(l, n));
        debug(atri(l, n)/atri(past, n));
        debug(1.0/(n+1));
        debug(atri(past, n)/atri(l, n));
        debug(atri(past, n));
        debug(atri(l, n));
        past = l;
        l = new_l(l, n);
    }
}
