#include <cpplib/stdinc.hpp>

string get_day(int val){
    val %= 7;
    if(val == 0)
        return "Sunday";
    else if(val == 1)
        return "Monday";
    else if(val == 2)
        return "Tuesday";
    else if(val == 3)
        return "Wednesday";
    else if(val == 4)
        return "Thursday";
    else if(val == 5)
        return "Friday";
    else
        return "Saturday";
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = n*365;
    for(int i=1867; i<=1867+n; ++i){
        if(i%4 == 0 and i%100 or i%100 == 0 and i%400 == 0)
            ans++;
    }
    cout << get_day(ans) << endl;
    return 0;
}
