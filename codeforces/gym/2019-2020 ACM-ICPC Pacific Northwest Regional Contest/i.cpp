#include <cpplib/stdinc.hpp>

class Dinic {
  struct Edge {
    const int v;
    // capacity (maximum flow) of the edge
    // if it is a reverse edge then its capacity should be equal to 0
    const int cap;
    // current flow of the graph
    int flow = 0;
    Edge(const int v, const int cap) : v(v), cap(cap) {}
  };

private:
  bool COMPUTED = false;
  int _max_flow;
  vector<Edge> edges;
  // holds the indexes of each edge present in each vertex.
  vector<vector<int>> adj;
  const int n;
  // src will be always 0 and sink n+1.
  const int src, sink;
  vector<int> level, ptr;

private:
  vector<vector<int>> _flow_table() {
    vector<vector<int>> table(n, vector<int>(n, 0));
    for (int u = 0; u <= sink; ++u)
      for (const int idx : adj[u])
        // checks if it's not a reverse edge
        if (!(idx & 1))
          table[u][edges[idx].v] += edges[idx].flow;
    return table;
  }

  /// Algorithm: Greedily all vertices from the matching will be added and,
  /// after that, edges in which one of the vertices is not covered will also be
  /// added to the answer.
  vector<pair<int, int>> _min_edge_cover() {
    vector<bool> covered(n, false);
    vector<pair<int, int>> ans;
    for (int u = 1; u < sink; ++u) {
      for (const int idx : adj[u]) {
        const Edge &e = edges[idx];
        // ignore if it is a reverse edge or an edge linked to the sink
        if (idx & 1 || e.v == sink)
          continue;
        if (e.flow == e.cap) {
          ans.emplace_back(u, e.v);
          covered[u] = covered[e.v] = true;
          break;
        }
      }
    }

    for (int u = 1; u < sink; ++u) {
      for (const int idx : adj[u]) {
        const Edge &e = edges[idx];
        if (idx & 1 || e.v == sink)
          continue;
        if (e.flow < e.cap && (!covered[u] || !covered[e.v])) {
          ans.emplace_back(u, e.v);
          covered[u] = covered[e.v] = true;
        }
      }
    }
    return ans;
  }

  /// Algorithm: Takes the complement of the vertex cover.
  vector<int> _max_ind_set(const int max_left) {
    const vector<int> mvc = _min_vertex_cover(max_left);
    vector<bool> contains(n);
    for (const int v : mvc)
      contains[v] = true;
    vector<int> ans;
    for (int i = 1; i < sink; ++i)
      if (!contains[i])
        ans.emplace_back(i);
    return ans;
  }

  void dfs_vc(const int u, vector<bool> &vis, const bool left,
              const vector<vector<int>> &paths) {
    vis[u] = true;
    for (const int idx : adj[u]) {
      const Edge &e = edges[idx];
      if (vis[e.v])
        continue;
      // saturated edges goes from right to left
      if (left && paths[u][e.v] == 0)
        dfs_vc(e.v, vis, left ^ 1, paths);
      // non-saturated edges goes from left to right
      else if (!left && paths[e.v][u] == 1)
        dfs_vc(e.v, vis, left ^ 1, paths);
    }
  }

  /// Algorithm: The edges that belong to the Matching M will go from right to
  /// left, all other edges will go from left to right. A DFS will be run
  /// starting at all left vertices that are not incident to edges in M. Some
  /// vertices of the graph will become visited during this DFS and some
  /// not-visited. To get minimum vertex cover all visited right
  /// vertices of M will be taken, and all not-visited left vertices of M.
  /// Source: codeforces.com/blog/entry/17534?#comment-223759
  vector<int> _min_vertex_cover(const int max_left) {
    vector<bool> vis(n, false), saturated(n, false);
    const auto paths = flow_table();

    for (int i = 1; i <= max_left; ++i) {
      for (int j = max_left + 1; j < sink; ++j)
        if (paths[i][j] > 0) {
          saturated[i] = saturated[j] = true;
          break;
        }
      if (!saturated[i] && !vis[i])
        dfs_vc(i, vis, 1, paths);
    }

    vector<int> ans;
    for (int i = 1; i <= max_left; ++i)
      if (saturated[i] && !vis[i])
        ans.emplace_back(i);

    for (int i = max_left + 1; i < sink; ++i)
      if (saturated[i] && vis[i])
        ans.emplace_back(i);

    return ans;
  }

  void dfs_build_path(const int u, vector<int> &path,
                      vector<vector<int>> &table, vector<vector<int>> &ans,
                      const vector<vector<int>> &adj) {
    path.emplace_back(u);

    if (u == sink) {
      ans.emplace_back(path);
      return;
    }

    for (const int v : adj[u]) {
      if (table[u][v]) {
        --table[u][v];
        dfs_build_path(v, path, table, ans, adj);
        return;
      }
    }
  }

  /// Algorithm: Run DFS's from the source and gets the paths when possible.
  vector<vector<int>> _compute_all_paths(const vector<vector<int>> &adj) {
    vector<vector<int>> table = flow_table();
    vector<vector<int>> ans;
    ans.reserve(_max_flow);

    for (int i = 0; i < _max_flow; i++) {
      vector<int> path;
      path.reserve(n);
      dfs_build_path(src, path, table, ans, adj);
    }

    return ans;
  }

  /// Algorithm: Find the set of vertices that are reachable from the source in
  /// the residual graph. All edges which are from a reachable vertex to
  /// non-reachable vertex are minimum cut edges.
  /// Source: geeksforgeeks.org/minimum-cut-in-a-directed-graph
  pair<int, vector<pair<int, int>>> _min_cut() {
    // checks if there's an edge from i to j.
    vector<vector<int>> mat_adj(n, vector<int>(n, 0));
    // checks if if the residual capacity is greater than 0
    vector<vector<bool>> residual(n, vector<bool>(n, 0));
    for (int u = 0; u <= sink; ++u)
      for (const int idx : adj[u])
        // checks if it's not a reverse edge
        if (!(idx & 1)) {
          mat_adj[u][edges[idx].v] = edges[idx].cap;
          // checks if its residual capacity is greater than zero.
          if (edges[idx].flow < edges[idx].cap)
            residual[u][edges[idx].v] = true;
        }

    vector<bool> vis(n);
    queue<int> q;

    q.emplace(src);
    vis[src] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < n; ++v)
        if (residual[u][v] && !vis[v]) {
          q.emplace(v);
          vis[v] = true;
        }
    }

    int weight = 0;
    vector<pair<int, int>> cut;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (vis[i] && !vis[j])
          // if there's an edge from i to j.
          if (mat_adj[i][j] > 0) {
            weight += mat_adj[i][j];
            cut.emplace_back(i, j);
          }

    return make_pair(weight, cut);
  }

  void _add_edge(const int u, const int v, const int cap) {
    adj[u].emplace_back(edges.size());
    edges.emplace_back(v, cap);
    // adding reverse edge
    adj[v].emplace_back(edges.size());
    edges.emplace_back(u, 0);
  }

  bool bfs_flow() {
    queue<int> q;
    memset(level.data(), -1, sizeof(*level.data()) * level.size());
    q.emplace(src);
    level[src] = 0;
    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int idx : adj[u]) {
        const Edge &e = edges[idx];
        if (e.cap == e.flow || level[e.v] != -1)
          continue;
        level[e.v] = level[u] + 1;
        q.emplace(e.v);
      }
    }
    return (level[sink] != -1);
  }

  int dfs_flow(const int u, const int cur_flow) {
    if (u == sink)
      return cur_flow;

    for (int &idx = ptr[u]; idx < adj[u].size(); ++idx) {
      Edge &e = edges[adj[u][idx]];
      if (level[u] + 1 != level[e.v] || e.cap == e.flow)
        continue;
      const int flow = dfs_flow(e.v, min(e.cap - e.flow, cur_flow));
      if (flow == 0)
        continue;
      e.flow += flow;
      edges[adj[u][idx] ^ 1].flow -= flow;
      return flow;
    }
    return 0;
  }

  int compute() {
    int ans = 0;
    while (bfs_flow()) {
      memset(ptr.data(), 0, sizeof(*ptr.data()) * ptr.size());
      while (const int cur = dfs_flow(src, LINF))
        ans += cur;
    }
    return ans;
  }

  void check_computed() {
    if (!COMPUTED) {
      COMPUTED = true;
      this->_max_flow = compute();
    }
  }

public:
  /// Constructor that makes assignments and allocations.
  ///
  /// Time Complexity: O(V)
  Dinic(const int n) : n(n + 2), src(0), sink(n + 1) {
    assert(n >= 0);

    adj.resize(this->n);
    level.resize(this->n);
    ptr.resize(this->n);
  }

  /// Returns the edges from the minimum edge cover of the graph.
  /// A minimum edge cover represents a set of edges such that each vertex
  /// present in the graph is linked to at least one edge from this set.
  ///
  /// Time Complexity: O(V + E)
  vector<pair<int, int>> min_edge_cover() {
    this->check_computed();
    return this->_min_edge_cover();
  }

  /// Returns the maximum independent set for the graph.
  /// An independent set represents a set of vertices such that they're not
  /// adjacent to each other.
  /// It is equal to the complement of the minimum vertex cover.
  ///
  /// Time Complexity: O(V + E)
  vector<int> max_ind_set(const int max_left) {
    this->check_computed();
    return this->_max_ind_set(max_left);
  }

  /// Returns the minimum vertex cover of a bipartite graph.
  /// A minimum vertex cover represents a set of vertices such that each edge of
  /// the graph is incident to at least one vertex of the graph.
  /// Pass the maximum index of a vertex on the left side as an argument.
  ///
  /// Time Complexity: O(V + E)
  vector<int> min_vertex_cover(const int max_left) {
    this->check_computed();
    return this->_min_vertex_cover(max_left);
  }

  /// Computes all paths from src to sink.
  /// Add all edges from the original graph. Its weights should be equal to the
  /// number of edges between the vertices. Pass the adjacency list with
  /// repeated vertices if there are multiple edges.
  ///
  /// Time Complexity: O(max_flow*V + E)
  vector<vector<int>> compute_all_paths(const vector<vector<int>> &adj) {
    this->check_computed();
    return this->_compute_all_paths(adj);
  }

  /// Returns the weight and the edges present in the minimum cut of the graph.
  /// A minimum cut represents a set of edges with minimum weight such that
  /// after removing these edges, it disconnects the graph. If the graph is
  /// undirected you can safely add edges in both directions. It doesn't work
  /// with parallel edges, it's required to merge them.
  ///
  /// Time Complexity: O(V^2 + E)
  pair<int, vector<pair<int, int>>> min_cut() {
    this->check_computed();
    return this->_min_cut();
  }

  /// Returns a table with the flow values for each pair of vertices.
  ///
  /// Time Complexity: O(V^2 + E)
  vector<vector<int>> flow_table() {
    this->check_computed();
    return this->_flow_table();
  }

  /// Adds a directed edge between u and v and its reverse edge.
  ///
  /// Time Complexity: O(1);
  void add_to_sink(const int u, const int cap) {
    assert(!COMPUTED);
    assert(src <= u), assert(u < sink);
    this->_add_edge(u, sink, cap);
  }

  /// Adds a directed edge between u and v and its reverse edge.
  ///
  /// Time Complexity: O(1);
  void add_to_src(const int v, const int cap) {
    assert(!COMPUTED);
    assert(src < v), assert(v <= sink);
    this->_add_edge(src, v, cap);
  }

  /// Adds a directed edge between u and v and its reverse edge.
  ///
  /// Time Complexity: O(1);
  void add_edge(const int u, const int v, const int cap) {
    assert(!COMPUTED);
    assert(src <= u), assert(u <= sink);
    this->_add_edge(u, v, cap);
  }

  /// Computes the maximum flow for the network.
  ///
  /// Time Complexity: O(V^2*E) or O(E*sqrt(V)) for matching.
  int max_flow() {
    this->check_computed();
    return this->_max_flow;
  }
} din(503);

bool check(string &s, string &t){
    int diff = 0;
    for(int i=0; i<s.size(); ++i)
        diff += (s[i] != t[i]);
    return diff == 2;
}

void dfs(int u, int c, vvi &adj, vvi &arr, vb &vis){
    vis[u] = true;
    arr[c].eb(u);
    for(int v:adj[u]){
        if(!vis[v])
            dfs(v, !c, adj, arr, vis);
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<string> arr(n);
    map<string, int> sti;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        sti[arr[i]] = i;
    }

    vvi adj(n);
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(check(arr[i], arr[j])){
                adj[i].eb(j);
                adj[j].eb(i);
            }
        }
    }

    vvi aux(2);
    vb vis(n);
    for(int i=0; i<n; ++i){
        if(!vis[i])
            dfs(i, 0, adj, aux, vis);
    }

    for(int u:aux[0]){
        din.add_to_src(u+1, 1);
        for(int v:adj[u])
            din.add_edge(u+1, v+1, 1);
    }
    for(int u:aux[1])
        din.add_to_sink(u+1, 1);

    cout << n - din.max_flow() << endl;
    return 0;
}
