#include <cpplib/stdinc.hpp>
class Persistent_Seg_Tree {
  struct Node {
    int val;
    Node *left, *right;
    Node(const int v) : val(v), left(nullptr), right(nullptr) {}
  };

private:
  const Node NEUTRAL_NODE = Node(0);
  int merge_nodes(const int x, const int y) { return x + y; }

private:
  const int n;
  vector<Node *> version = {nullptr};

public:
  /// Builds version[0] with the values in the array.
  ///
  /// Time complexity: O(n)
  Node *build(Node *node, const int l, const int r, const vector<int> &arr) {
    node = new Node(NEUTRAL_NODE);
    if (l == r) {
      node->val = arr[l];
      return node;
    }

    const int mid = (l + r) / 2;
    node->left = build(node->left, l, mid, arr);
    node->right = build(node->right, mid + 1, r, arr);
    node->val = merge_nodes(node->left->val, node->right->val);
    return node;
  }

  Node *_update(Node *cur_tree, Node *prev_tree, const int l, const int r,
                const int idx, const int delta) {
    if (l > idx || r < idx)
      return cur_tree != nullptr ? cur_tree : prev_tree;

    if (cur_tree == nullptr && prev_tree == nullptr)
      cur_tree = new Node(NEUTRAL_NODE);
    else
      cur_tree = new Node(cur_tree == nullptr ? *prev_tree : *cur_tree);

    if (l == r) {
      cur_tree->val += delta;
      return cur_tree;
    }

    const int mid = (l + r) / 2;
    cur_tree->left =
        _update(cur_tree->left, prev_tree ? prev_tree->left : nullptr, l, mid,
                idx, delta);
    cur_tree->right =
        _update(cur_tree->right, prev_tree ? prev_tree->right : nullptr,
                mid + 1, r, idx, delta);
    cur_tree->val =
        merge_nodes(cur_tree->left ? cur_tree->left->val : NEUTRAL_NODE.val,
                    cur_tree->right ? cur_tree->right->val : NEUTRAL_NODE.val);
    return cur_tree;
  }

  int _query(Node *node, const int l, const int r, const int i, const int j) {
    if (node == nullptr || l > j || r < i)
      return NEUTRAL_NODE.val;

    if (i <= l && r <= j)
      return node->val;

    int mid = (l + r) / 2;
    return merge_nodes(_query(node->left, l, mid, i, j),
                       _query(node->right, mid + 1, r, i, j));
  }

  void create_version(const int v) {
    if (v >= this->version.size())
      version.resize(v + 1);
  }

public:
  Persistent_Seg_Tree() : n(-1) {}

  /// Constructor that initializes the segment tree empty. It's allowed to query
  /// from 0 to MAXN - 1.
  ///
  /// Time Complexity: O(1)
  Persistent_Seg_Tree(const int MAXN) : n(MAXN) {}

  /// Constructor that allows to pass initial values to the leafs. It's allowed
  /// to query from 0 to n - 1.
  ///
  /// Time Complexity: O(n)
  Persistent_Seg_Tree(const vector<int> &arr) : n(arr.size()) {
    this->version[0] = this->build(this->version[0], 0, this->n - 1, arr);
  }

  /// Links the root of a version to a previous version.
  ///
  /// Time Complexity: O(1)
  void link(const int version, const int prev_version) {
    assert(this->n > -1);
    assert(0 <= prev_version), assert(prev_version <= version);
    this->create_version(version);
    this->version[version] = this->version[prev_version];
  }

  /// Updates an index in cur_tree based on prev_tree with a delta.
  ///
  /// Time Complexity: O(log(n))
  void update(const int cur_version, const int prev_version, const int idx,
              const int delta) {
    assert(this->n > -1);
    assert(0 <= prev_version), assert(prev_version <= cur_version);
    this->create_version(cur_version);
    this->version[cur_version] =
        this->_update(this->version[cur_version], this->version[prev_version],
                      0, this->n - 1, idx, delta);
  }

  /// Query from l to r.
  ///
  /// Time Complexity: O(log(n))
  int query(const int version, const int l, const int r) {
    if(r < l)
        return 0;
    assert(this->n > -1);
    assert(0 <= l), assert(l <= r), assert(r < this->n);
    return this->_query(this->version[version], 0, this->n - 1, l, r);
  }
};

int32_t main(){
    desync();
    int q;
    cin >> q;

    int n = 0;
    map<string, int> sti;

    Persistent_Seg_Tree st(vi(q+2, -1)), cnt(1e9);
    st.create_version(q+1);
    cnt.create_version(q+1);

    vi lv(q+2);
    for(int v=1; v<=q; ++v){
        lv[v+1] = lv[v];
        string op;
        cin >> op;
        if(op == "set"){
            string s;
            int x;
            cin >> s >> x;
            if(!sti.count(s))
                sti[s] = n++;
            int i = sti[s];
            int cur = st.query(lv[v], i, i);
            if(cur != -1){
                cnt.update(v, lv[v], cur, -1);
                cnt.update(v, v, x, 1);
            }
            else
                cnt.update(v, lv[v], x, 1);
            st.update(v, lv[v], i, x-cur);
            lv[v+1] = v;
        }
        else if(op == "query"){
            string s;
            cin >> s;
            if(!sti.count(s))
                sti[s] = n++;
            int i = sti[s];
            int cur = st.query(lv[v], i, i);
            if(cur == -1)
                cout << -1 << endl;
            else
                cout << cnt.query(lv[v], 0, cur-1) << endl;
            cout.flush();
        }
        else if(op == "remove"){
            string s;
            cin >> s;
            if(!sti.count(s))
                sti[s] = n++;
            int i = sti[s];
            int cur = st.query(lv[v], i, i);
            if(cur != -1){
                cnt.update(v, lv[v], cur, -1);
                st.update(v, lv[v], i, -1-cur);
                lv[v+1] = v;
            }
        }
        else{
            int d;
            cin >> d;
            lv[v+1] = lv[v-d];
        }
    }
    return 0;
}
