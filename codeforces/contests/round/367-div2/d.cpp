#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/binary-trie.hpp>

int32_t main(){
    desync();
    BTrie<> trie;
    trie.insert(0);
    int n;
    cin >> n;
    while(n--){
        char op;
        int x;
        cin >> op >> x;
        switch(op){
            case '+':
                trie.insert(x);
                break;
            case '-':
                trie.erase(x, 1);
                break;
            case '?':
                cout << (x ^ trie) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
