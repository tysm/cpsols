#include <cpplib/header.hpp>

enum class SegTreeKind
{
    RMaxQ,
    RMinQ,
    RSumQ,
    RXorQ,
};

/**
 * Segment Tree.
 *
 * Arranges data in a binary tree so that it
 * is possible to perform range queries and
 * modifications over an array effectively.
 *
 * Common kinds of use:
 * - Range Max Query;
 * - Range Min Query;
 * - Range Sum Query;
 * - Range Xor Query.
 *
 * Note: when the tree is constructed by
 * inserting each value one by one using
 * update, the time complexity is
 * actually O(n*log(n)).
 *
 * Note: it's recommended to remove the
 * pair<T, bool> set from SegTree<K, T>::Node
 * when it's not being used since it costs
 * a bunch of memory when many Segment Trees
 * are constructed (e.g., Segment Tree 2D).
 *
 * Time Complexity: O(n).
 * Space Complexity: O(n).
 * Where n is the size of the array.
 */
template<SegTreeKind K, typename T>
class SegTree
{
public:
    /**
     * Segment Tree Node.
     *
     * Helps to hold range data dynamically so
     * that only a small number of nodes are
     * visited per query.
     */
    struct Node {
        T value, lazy;

        Node() :
            lazy(0)
        {
            switch(K){
                case SegTreeKind::RMaxQ:
                    value = -INF;
                    break;
                case SegTreeKind::RMinQ:
                    value = INF;
                    break;
                case SegTreeKind::RSumQ:
                case SegTreeKind::RXorQ:
                default:
                    value = 0;
                    break;
            }
        }

        Node(const T value, const T lazy = 0) :
            value(value), lazy(lazy) {}

        /**
         * Checks if a value matches with this->value
         * according to the kind of the Segment Tree.
         */
        bool match(const T value) const
        {
            switch(K){
                case SegTreeKind::RMaxQ:
                    return this->value >= value;
                    // return this->value > value;
                case SegTreeKind::RMinQ:
                    return this->value <= value;
                    // return this->value < value;
                case SegTreeKind::RSumQ:
                case SegTreeKind::RXorQ:
                default:
                    assert(false);
            }
        }

        void update(const size_t range)
        {
            switch (K){
                case SegTreeKind::RMaxQ:
                case SegTreeKind::RMinQ:
                    value += lazy;
                    break;
                case SegTreeKind::RSumQ:
                    value += range*lazy;
                    break;
                case SegTreeKind::RXorQ:
                default:
                    break;
            }

            lazy = 0;
        }

        /**
         * Merges two nodes into a new one according
         * to the kind of the Segment Tree.
         */
        static Node merge(const Node lhs, const Node rhs)
        {
            assert(lhs.lazy == 0 and rhs.lazy == 0);
            switch(K){
                case SegTreeKind::RMaxQ:
                    return Node(max(lhs.value, rhs.value));
                case SegTreeKind::RMinQ:
                    return Node(min(lhs.value, rhs.value));
                case SegTreeKind::RSumQ:
                    return Node(lhs.value + rhs.value);
                case SegTreeKind::RXorQ:
                    return Node(lhs.value ^ rhs.value);
                default:
                    assert(false);
            }
        }
    };

    SegTree(const size_t arr_size) :
        tree(4*arr_size), arr_size(arr_size) {}

    SegTree(const vector<T> &arr) :
        SegTree(arr.size(), arr) {}

    SegTree(const size_t arr_size, const vector<T> &arr) :
        tree(4*arr_size), arr_size(arr_size)
    {
        build(0, arr_size-1, 0, arr);
    }

    /**
     * Finds the index of the first element over
     * the array that matches with value.
     *
     * It returns the size of the array when the
     * value doesn't match with any array value.
     *
     * Time Complexity: O(log(n)).
     * Where n is the size of the array.
     */
    size_t find(const T value)
    {
        return find(0, arr_size-1, 0, value);
    }

    /**
     * Computes the ith array value.
     *
     * Time Complexity: O(log(n)).
     * Where n is the size of the array.
     */
    T query(const size_t i)
    {
        assert(i < arr_size);
        return query(i, i);
    }

    /**
     * Computes the value corresponding to the
     * range [l, r] of the array.
     *
     * Time Complexity: O(log(n)).
     * Where n is the size of the array.
     */
    T query(const size_t l, const size_t r)
    {
        assert(l <= r and r < arr_size);
        return query(0, arr_size-1, l, r, 0).value;
    }

    /**
     * Updates the ith array value according to
     * the kind of the Segment Tree.
     *
     * Time Complexity: O(log(n)).
     * Where n is the size of the array.
     */
    void update(const size_t i, const T delta)
    {
        assert(i < arr_size);
        update(i, i, delta);
    }

    /**
     * Updates the array values in the range
     * [l, r] according to the kind of the
     * Segment Tree.
     *
     * Time Complexity: O(log(n)).
     * Where n is the size of the array.
     */
    void update(const size_t l, const size_t r, const T delta)
    {
        assert(l <= r and r < arr_size);
        update(0, arr_size-1, l, r, 0, delta);
    }

    /**
     * Merges two trees into a new one according
     * to the kind of the Segment Tree.
     */
    static SegTree merge(const SegTree &lhs, const SegTree &rhs)
    {
        assert(lhs.arr_size == rhs.arr_size);

        SegTree result(lhs.arr_size);
        for(size_t i=0; i<4*lhs.arr_size; ++i)
            result.tree[i] = Node::merge(lhs.tree[i], rhs.tree[i]);
        return result;
    }

private:
    Node build(const size_t l, const size_t r, const size_t pos, const vector<T> &arr)
    {
        if(l == r)
            return tree[pos] = Node(arr[l]);

        size_t mid = (l + r)/2;
        return tree[pos] = Node::merge(build(l, mid, 2*pos+1, arr), build(mid+1, r, 2*pos+2, arr));
    }

    size_t find(const size_t l, const size_t r, const size_t pos, const T value)
    {
        propagate(l, r, pos);

        if(!tree[pos].match(value))
            return arr_size;
        else if(l == r)
            return l;

        size_t mid = (l + r)/2;
        size_t ans = find(l, mid, 2*pos+1, value);
        return ans != arr_size? ans : find(mid+1, r, 2*pos+2, value);
    }

    Node query(const size_t l, const size_t r, const size_t i, const size_t j, const size_t pos)
    {
        propagate(l, r, pos);

        if(l > j or r < i)
            return Node();

        if(l >= i and r <= j)
            return tree[pos];

        size_t mid = (l + r)/2;
        return Node::merge(query(l, mid, i, j, 2*pos+1), query(mid+1, r, i, j, 2*pos+2));
    }

    Node update(const size_t l, const size_t r, const size_t i, const size_t j, const size_t pos, const T delta)
    {
        propagate(l, r, pos);

        if(l > j or r < i)
            return tree[pos];

        if(l >= i and r <= j){
            tree[pos].lazy = delta;
            // it's important to propagate before returning and Node::merge.
            propagate(l, r, pos);
            return tree[pos];
        }

        size_t mid = (l + r)/2;
        return tree[pos] = Node::merge(update(l, mid, i, j, 2*pos+1, delta), update(mid+1, r, i, j, 2*pos+2, delta));
    }

    void propagate(const size_t l, const size_t r, const size_t pos)
    {
        T lazy = tree[pos].lazy;

        if(lazy == 0)
            return;

        tree[pos].update((r - l + 1));

        if(l != r){
            tree[2*pos+1].lazy += lazy;
            tree[2*pos+2].lazy += lazy;
        }
    }

    vector<Node> tree;
    size_t arr_size;
};

/**
 * Segment Tree 2D.
 *
 * Arranges data in a binary tree so that it
 * is possible to perform range queries and
 * point updates over a matrix effectively.
 *
 * Common kinds of use:
 * - Range Max Query;
 * - Range Min Query;
 * - Range Sum Query;
 * - Range Xor Query.
 *
 * Note: when the tree is constructed by
 * inserting each value one by one using
 * update, the time complexity is
 * actually O(n*m*log(n + m)).
 *
 * Time Complexity: O(n*m).
 * Space Complexity: O(n*m).
 * Where n is the height and m is the width of the matrix.
 */
template<SegTreeKind K, typename T>
class SegTree2D
{
public:
    SegTree2D(const size_t mat_height, const size_t mat_width) :
        tree(4*mat_height, SegTree<K, T>(mat_width)),
        mat_height(mat_height), mat_width(mat_width) {}

    SegTree2D(const vector<vector<T> > &mat) :
        SegTree2D(mat.size(), mat[0].size(), mat) {}

    SegTree2D(const size_t mat_height, const size_t mat_width, const vector<vector<T> > &mat) :
        tree(4*mat_height, SegTree<K, T>(mat_width)),
        mat_height(mat_height), mat_width(mat_width)
    {
        for(const vector<T> &arr : mat)
            assert(mat_width == arr.size());
        build(0, mat_height-1, 0, mat);
    }

    /**
     * Computes the matrix value in the ith row
     * and jth column.
     *
     * Time Complexity: O(log(n) + log(m)).
     * Where n is the height and m is the width of the matrix.
     */
    T query(const size_t i, const size_t j)
    {
        assert(i < mat_height);
        assert(j < mat_width);
        return query(i, i, j, j);
    }

    /**
     * Computes the value corresponding to the
     * row range [l1, r1] and column range
     * [l2, r2] of the matrix.
     *
     * Time Complexity: O(log(n) + log(m)).
     * Where n is the height and m is the width of the matrix.
     */
    T query(const size_t l1, const size_t r1, const size_t l2, const size_t r2)
    {
        assert(l1 <= r1 and r1 < mat_height);
        assert(l2 <= r2 and r2 < mat_width);
        return query(0, mat_height-1, l1, r1, 0, l2, r2).value;
    }

    /**
     * Updates the the matrix value in the ith
     * row and jth column according to the kind
     * of the Segment Tree.
     *
     * Time Complexity: O(log(n)*log(m)).
     * Where n is the height and m is the width of the matrix.
     */
    void update(const size_t i, const size_t j, const T value)
    {
        assert(i < mat_height);
        assert(j < mat_width);
        update(0, mat_height-1, i, 0, j, value);
    }

private:
    SegTree<K, T> build(const size_t l, const size_t r, const size_t pos, const vector<vector<T> > &mat)
    {
        if(l == r)
            return tree[pos] = SegTree<K, T>(mat[l]);

        size_t mid = (l + r)/2;
        return tree[pos] = SegTree<K, T>::merge(build(l, mid, 2*pos+1, mat), build(mid+1, r, 2*pos+2, mat));
    }

    typename SegTree<K, T>::Node query(const size_t l, const size_t r, const size_t i1, const size_t i2, const size_t pos, const size_t j1, const size_t j2)
    {
        if(l > i2 or r < i1)
            return typename SegTree<K, T>::Node();

        if(l >= i1 and r <= i2)
            return typename SegTree<K, T>::Node(tree[pos].query(j1, j2));

        size_t mid = (l + r)/2;
        return SegTree<K, T>::Node::merge(query(l, mid, i1, i2, 2*pos+1, j1, j2), query(mid+1, r, i1, i2, 2*pos+2, j1, j2));
    }

    void update(const size_t l, const size_t r, const size_t i, const size_t pos, const size_t j, const T delta)
    {
        if(l > i or r < i)
            return;

        tree[pos].update(j, delta);

        if(l == i and r == i)
            return;

        size_t mid = (l + r)/2;
        update(l, mid, i, 2*pos+1, j, delta);
        update(mid+1, r, i, 2*pos+2, j, delta);
    }

    vector<SegTree<K, T> > tree;
    size_t mat_height, mat_width;
};


int32_t main(){
    // https://cses.fi/problemset/task/1739
    desync();
    int n, q;
    cin >> n >> q;
    vvi arr(n, vi(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char c;
            cin >> c;
            arr[i][j] = (c == '*');
        }
    }
    SegTree2D<SegTreeKind::RSumQ, int> st(arr);
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int y, x;
            cin >> y >> x;
            y--; x--;
            st.update(y, x, (arr[y][x] ^ 1) - arr[y][x]);
            arr[y][x] ^= 1;
        }
        else{
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << st.query(y1-1, y2-1, x1-1, x2-1) << endl;
        }
    }
    return 0;
}
