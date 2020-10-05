#include <cpplib/stdinc.hpp>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// #define REVERSE
// #define LAZY
class Treap {
public:
  struct Node {
    Node *left = nullptr, *right = nullptr, *par = nullptr;
    // Priority to be used in the treap
    const int rank;
    int size = 1, val;
    // Contains the result of the range query between the node and its children.
    int ans;
#ifdef LAZY
    int lazy = 0;
#endif
#ifdef REVERSE
    bool rev = false;
#endif

    Node(const int val) : val(val), ans(val), rank(rng()) {}
    Node(const int val, const int rank) : val(val), ans(val), rank(rank) {}
  };

private:
  vector<Node *> nodes;
  int _size = 0;
  Node *root = nullptr;

private:
  // Range Sum
  void merge_nodes(Node *node) {
    node->ans = node->val;
    if (node->left)
      node->ans += node->left->ans;
    if (node->right)
      node->ans += node->right->ans;
  }

  // #ifdef LAZY
  //   void apply_lazy(Node *node) {
  //     node->val += node->lazy;
  //     node->ans += node->lazy * get_size(node);
  //   }
  // #endif

  // // RMQ Min
  // void merge_nodes(Node *node) {
  //   node->ans = node->val;
  //   if (node->left)
  //     node->ans = min(node->ans, node->left->ans);
  //   if (node->right)
  //     node->ans = min(node->ans, node->right->ans);
  // }

  // #ifdef LAZY
  //   void apply_lazy(Node *node) {
  //     node->val += node->lazy;
  //     node->ans += node->lazy;
  //   }
  // #endif

  // // RMQ Max
  // void merge_nodes(Node *node) {
  //   node->ans = node->val;
  //   if (node->left)
  //     node->ans = max(node->ans, node->left->ans);
  //   if (node->right)
  //     node->ans = max(node->ans, node->right->ans);
  // }

  // #ifdef LAZY
  //   void apply_lazy(Node *node) {
  //     node->val += node->lazy;
  //     node->ans += node->lazy;
  //   }
  // #endif

  int get_size(const Node *node) { return node ? node->size : 0; }

  void update_size(Node *node) {
    if (node)
      node->size = 1 + get_size(node->left) + get_size(node->right);
  }

#ifdef REVERSE
  void propagate_reverse(Node *node) {
    if (node && node->rev) {
      swap(node->left, node->right);
      if (node->left)
        node->left->rev ^= 1;
      if (node->right)
        node->right->rev ^= 1;
      node->rev = 0;
    }
  }
#endif

#ifdef LAZY
  void propagate_lazy(Node *node) {
    if (node && node->lazy != 0) {
      apply_lazy(node);
      if (node->left)
        node->left->lazy += node->lazy;
      if (node->right)
        node->right->lazy += node->lazy;
      node->lazy = 0;
    }
  }
#endif

  void update_node(Node *node) {
    if (node) {
      update_size(node);
#ifdef LAZY
      propagate_lazy(node->left);
      propagate_lazy(node->right);
#endif
#ifdef REVERSE
      propagate_reverse(node);
#endif
      merge_nodes(node);
    }
  }

  /// Splits the treap into to different treaps that contains nodes with indexes
  /// <= pos ans indexes > pos. The nodes l and r contains, in the end, these
  /// two different treaps.
  void split(Node *node, Node *&l, Node *&r, const int pos, Node *pl = nullptr,
             Node *pr = nullptr) {
    if (!node)
      l = r = nullptr;
    else {
#ifdef LAZY
      propagate_lazy(node);
#endif
#ifdef REVERSE
      propagate_reverse(node);
#endif
      if (get_size(node->left) <= pos) {
        node->par = pr;
        split(node->right, node->right, r, pos - get_size(node->left) - 1, pl,
              node);
        l = node;
      } else {
        node->par = pl;
        split(node->left, l, node->left, pos, node, pr);
        r = node;
      }
    }
    update_node(node);
  }

  /// Merges to treaps (l and r) into a single one based on the rank of each
  /// node.
  void merge(Node *&node, Node *l, Node *r, Node *par = nullptr) {
#ifdef LAZY
    propagate_lazy(l), propagate_lazy(r);
#endif
#ifdef REVERSE
    propagate_reverse(l), propagate_reverse(r);
#endif
    if (l == nullptr || r == nullptr)
      node = (l == nullptr ? r : l);
    else if (l->rank > r->rank) {
      merge(l->right, l->right, r, l);
      node = l;
    } else {
      merge(r->left, l, r->left, r);
      node = r;
    }
    if (node)
      node->par = par;
    update_node(node);
  }

  Node *build(const int l, const int r, const vector<int> &arr,
              vector<int> &rand) {
    if (l > r)
      return nullptr;

    const int mid = (l + r) / 2;
    Node *node = new Node(arr[mid], rand.back());
    rand.pop_back();
    node->right = build(mid + 1, r, arr, rand);
    node->left = build(l, mid - 1, arr, rand);
    update_node(node);

    return node;
  }

  int _get_ith(const int idx) {
    int ans = 0;
    Node *cur = nodes[idx], *prev = nullptr;
    while (cur) {
      if (cur == nodes[idx] || prev == cur->right)
        ans += 1 + get_size(cur->left);
      prev = cur;
      cur = cur->par;
    }
    return ans - 1;
  }

  vector<int> gen_rand(const int n) {
    vector<int> ans(n);
    for (int &x : ans)
      x = rng();
    sort(ans.begin(), ans.end());
    return ans;
  }

  Node *_query(const int l, const int r) {
    Node *L, *M, *R;
    split(this->root, L, M, l - 1);
    split(M, M, R, r - l);
    Node *ret = new Node(*M);
    merge(L, L, M);
    merge(root, L, R);
    return ret;
  }

  void _update(const int l, const int r, const int delta) {
    Node *L, *M, *R;
    split(this->root, L, M, l - 1);
    split(M, M, R, r - l);

    Node *node = M;
#ifdef LAZY
    node->lazy = delta;
    propagate_lazy(node);
#else
    node->val += delta;
#endif

    merge(L, L, M);
    merge(root, L, R);
  }

  void _insert(const int pos, Node *node) {
    this->_size += node->size;
    Node *L, *R;
    split(this->root, L, R, pos - 1);
    merge(L, L, node);
    merge(this->root, L, R);
  }

  Node *_erase(const int l, const int r) {
    Node *L, *M, *R;
    split(this->root, L, M, l - 1);
    split(M, M, R, r - l);
    merge(root, L, R);
    this->_size -= r - l + 1;
    return M;
  }

  void _move(const int l, const int r, const int new_pos) {
    Node *node = _erase(l, r);
    _insert(new_pos, node);
  }

#ifdef REVERSE
  void _reverse(const int l, const int r) {
    Node *L, *M, *R;
    split(this->root, L, M, l - 1);
    split(M, M, R, r - l);

    Node *node = M;
    node->rev = true;
    propagate_reverse(node);

    merge(L, L, M);
    merge(root, L, R);
  }
#endif

public:
  Treap() {}

  /// Constructor that initializes the treap based on an array.
  ///
  /// Time Complexity: O(n)
  Treap(const vector<int> &arr) : _size(arr.size()) {
    vector<int> r = gen_rand(arr.size());
    this->root = build(0, (int)arr.size() - 1, arr, r);
  }

  int size() { return _size; }

  /// Moves the subarray [l, r] to the position starting at new_pos.
  ///
  /// Time Complexity: O(log n)
  void move(const int l, const int r, const int new_pos) {
    assert(0 <= new_pos), assert(new_pos <= _size - (r - l + 1));
    _move(l, r, new_pos);
  }

  /// Moves the subarray [l, r] to the back of the array.
  ///
  /// Time Complexity: O(log n)
  void move_back(const int l, const int r) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    _move(l, r, _size - (r - l + 1));
  }

  /// Moves the subarray [l, r] to the front of the array.
  ///
  /// Time Complexity: O(log n)
  void move_front(const int l, const int r) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    _move(l, r, 0);
  }

#ifdef REVERSE
  /// Reverses the subarray [l, r].
  ///
  /// Time Complexity: O(log n)
  void reverse(const int l, const int r) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    _reverse(l, r);
  }
#endif

  /// Erases the subarray [l, r].
  ///
  /// Time Complexity: O(log n)
  void erase(const int l, const int r) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    _erase(l, r);
  }

  /// Inserts the value val at the position pos.
  ///
  /// Time Complexity: O(log n)
  void insert(const int pos, const int val) {
    assert(pos <= _size);
    nodes.emplace_back(new Node(val));
    _insert(pos, nodes.back());
  }

  /// Returns the index of the i-th added node.
  ///
  /// Time Complexity: O(log n)
  int get_ith(const int idx) {
    assert(0 <= idx), assert(idx < nodes.size());
    return _get_ith(idx);
  }

  /// Sums the delta value to the position pos.
  ///
  /// Time Complexity: O(log n)
  void update(const int pos, const int delta) {
    assert(0 <= pos), assert(pos < _size);
    _update(pos, pos, delta);
  }

#ifdef LAZY
  /// Sums the delta value to the subarray [l, r].
  ///
  /// Time Complexity: O(log n)
  void update(const int l, const int r, const int delta) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    _update(l, r, delta);
  }
#endif

  /// Query at a single index.
  ///
  /// Time Complexity: O(log n)
  int query(const int pos) {
    assert(0 <= pos), assert(pos < _size);
    return _query(pos, pos)->ans;
  }

  /// Range query from l to r.
  ///
  /// Time Complexity: O(log n)
  int query(const int l, const int r) {
    assert(0 <= l), assert(l <= r), assert(r < _size);
    return _query(l, r)->ans;
  }
};

int32_t main(){
    desync();
    int n;
    cin >> n;
    Treap tp;
    for(int i=0; i<n; ++i){
        char op;
        cin >> op;
        if(op == 'F')
            tp.insert(0, i);
        else if(op == 'B')
            tp.insert(tp.size(), i);
        else{
            int idx;
            cin >> idx;

            int l = tp.get_ith(idx-1), r = tp.size() - l - 1;
            tp.erase(l, l);
            if(l <= r){
                cout << l << endl;
                if(l)
                    tp.move_back(0, l-1);
            }
            else{
                cout << r << endl;
                if(r)
                    tp.move_front(l, tp.size()-1);
            }
        }
    }
    return 0;
}
