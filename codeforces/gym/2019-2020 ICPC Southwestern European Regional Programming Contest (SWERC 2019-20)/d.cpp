#include <cpplib/stdinc.hpp>

int hsh = 100000;
map<ii, int> pack;
map<int, ii> unpack;

void COPY(stack<int> &st){
    st.ep(st.top());
}

void DELETE(stack<int> &st){
    st.pop();
}

void LEFT_UNPACK(stack<int> &st){
    if(st.top() < 100000){
        st.ep(-1);
        return;
    }
    int u = st.top();
    st.pop();

    st.ep(unpack[u].ff);
}

void PACK(stack<int> &st){
    int u = st.top();
    st.pop();

    int v = st.top();
    st.pop();

    ii res(u, v);
    if(pack.count(res))
        st.ep(pack[res]);
    else{
        st.ep(hsh);
        unpack[hsh] = res;
        pack[res] = hsh++;
    }
}

void RIGHT_UNPACK(stack<int> &st){
    if(st.top() < 100000){
        st.ep(-1);
        return;
    }
    int u = st.top();
    st.pop();

    st.ep(unpack[u].ss);
}

void SWAP(stack<int> &st){
    int u = st.top();
    st.pop();

    int v = st.top();
    st.pop();

    st.ep(u);
    st.ep(v);
}

void UNPACK(stack<int> &st){
    if(st.top() < 100000){
        st.ep(-1);
        return;
    }
    int u = st.top();
    st.pop();

    st.ep(unpack[u].ss);
    st.ep(unpack[u].ff);
}

stack<int> solve(string &s){
    stack<int> st;
    for(int i=0; i<1e5; ++i)
        st.ep(i);

    for(char c:s){
        if(c == 'C')
            COPY(st);
        else if(c == 'D')
            DELETE(st);
        else if(c == 'L')
            LEFT_UNPACK(st);
        else if(c == 'P')
            PACK(st);
        else if(c == 'R')
            RIGHT_UNPACK(st);
        else if(c == 'S')
            SWAP(st);
        else
            UNPACK(st);
        if(st.top() == -1){
            stack<int> res;
            res.ep(-1);
            return res;
        }
    }
    return st;
}

int32_t main(){
    desync();
    string s, t;
    cin >> s >> t;
    cout << (solve(s) == solve(t)? "True" : "False") << endl;
    return 0;
}
