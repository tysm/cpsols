#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    int acc = 0;
    vi arr(n);
    for(int &i:arr){
        cin >> i;
        acc += (i >= 0);
    }
    sort(all(arr), [](int i, int j){ return abs(i) > abs(j); });

    mint ans = 1;
    if(!acc){
        if(k%2){
            while(k--){
                ans *= arr.back();
                arr.pop_back();
            }
        }
        else{
            for(int i=0; i<k; ++i)
                ans *= arr[i];
        }
    }
    else{
        stack<int> l0, ge0;
        for(int i=0; i<k; ++i){
            if(arr[i] >= 0)
                ge0.ep(arr[i]);
            else
                l0.ep(arr[i]);
        }
        if(l0.size()%2){
            int a = 0, b = -1;
            for(int i=k; i<n; ++i){
                if(arr[i] >= 0){
                    if(b == -1)
                        b = arr[i];
                }
                else if(a == 0)
                    a = arr[i];
            }
            if(a != 0 and b != -1){
                if(ge0.empty() or ge0.top()*b > l0.top()*a){
                    ge0.ep(b);
                    l0.pop();
                }
                else{
                    l0.ep(a);
                    ge0.pop();
                }
            }
            else if(a != 0){
                // b == -1 -> ge0.emtpy() == false.
                l0.ep(a);
                ge0.pop();
            }
            else if(b != -1){
                ge0.ep(b);
                l0.pop();
            }
            // else there's nothing to do :<.
        }
        while(!l0.empty()){
            ans *= l0.top();
            l0.pop();
        }
        while(!ge0.empty()){
            ans *= ge0.top();
            ge0.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
