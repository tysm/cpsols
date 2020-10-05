#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int l;
    cin >> l;
    int acc = 0;
    stack<int> stf, sta;
    while(l--){
        string op;
        cin >> op;
        if(op == "end"){
            acc = acc * stf.top() + sta.top();
            stf.pop();
            sta.pop();
        }
        else if(op == "add")
            acc++;
        else{
            int n;
            cin >> n;
            stf.emplace(n);
            sta.emplace(acc);
            acc = 0;
        }
        if(acc > UINT_MAX)
            break;
    }
    if(acc > UINT_MAX)
        cout << "OVERFLOW!!!" << endl;
    else
        cout << acc << endl;
    return 0;
}
