#include <cpplib/stdinc.hpp>

struct Node {
    int sum = 0, msum = 0, mpsum = 0, mssum = 0;

    Node(){}

    Node(int val) :
        sum(val), msum(max(val, 0LL)), mpsum(max(val, 0LL)), mssum(max(val, 0LL)) {}

    Node(Node l, Node r) :
        sum(l.sum + r.sum)
    {
        mpsum = max(l.mpsum, l.sum+r.mpsum);
        mssum = max(l.mssum+r.sum, r.mssum);
        msum = max({l.msum, r.msum, l.mssum+r.mpsum});
    }
};

vector<Node> stree(4*MAX);

void build(int l, int r, int pos, vi &arr){
    if(l>r)
        return;

    if(l == r)
        stree[pos] = Node(arr[l]);
    else{
        int mid = (l+r)/2;
        build(l, mid, 2*pos+1, arr);
        build(mid+1, r, 2*pos+2, arr);
        stree[pos] = Node(stree[2*pos+1], stree[2*pos+2]);
    }
}

void update(int l, int r, int pos, int i, int val){
    if(l > i or r < i or l > r)
        return;

    if(l == r)
        stree[pos] = Node(val);
    else{
        int mid = (l+r)/2;
        update(l, mid, 2*pos+1, i, val);
        update(mid+1, r, 2*pos+2, i, val);
        stree[pos] = Node(stree[2*pos+1], stree[2*pos+2]);
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1190
    desync();
    int n, m;
    cin >> n >> m;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    build(0, n-1, 0, arr);
    while(m--){
        int k, x;
        cin >> k >> x;
        update(0, n-1, 0, k-1, x);
        cout << stree[0].msum << endl;
    }
    return 0;
}
