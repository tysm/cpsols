#include <cpplib/stdinc.hpp>

double compute(double x, int a, int b){
    return (a*x + b*(x-1))/(2*x-1);
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    while(n--){
        int h, c, t;
        cin >> h >> c >> t;
        if(2*t <= h+c){
            cout << 2 << endl;
            continue;
        }
        int low = 2, high = 2*INF;
        while(low < high){
            int mid = (low + high)>>1;
            double resp = compute(mid-1, h, c); // prev
            double resc = compute(mid, h, c); // cur
            double resn = compute(mid+1, h, c); // next
            if(abs(t - resp) <= abs(t - resc))
                high = mid-1;
            else if(abs(t - resn) < abs(t - resc))
                low = mid+1;
            else
                low = high = mid;
        }
        int ans = abs(t-compute(1, h, c)) <= abs(t-compute(low, h, c))? 1 : low;
        cout << ans*2-1 << endl;
    }
    return 0;
}
