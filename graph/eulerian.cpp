template <typename T>
vector<int> find_eulerian_path(const digraph<T> &g, int &root) {
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  int cnt_edges = 0;
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    cnt_edges++;
    auto &e = g.edges[id];
    out_deg[e.from]++;
    in_deg[e.to]++;
  }
  root = -1;
  int diff = 0;
  for (int i = 0; i < g.n; i++) {
    if (in_deg[i] < out_deg[i]) {
      diff += out_deg[i] - in_deg[i];
      root = i;
    }
  }
  if (diff > 1) {
    root = -1;
    return vector<int>();
  }
  if (root == -1) {
    root = 0;
    while (root < g.n && out_deg[root] == 0) {
      root++;
    }
    if (root == g.n) {
      // but actually an empty path exists...
      root = 0;
      return vector<int>();
    }
  }
  vector<int> ptr(g.n, 0);
  vector<int> res;
  function<void(int)> dfs = [&](int v) {
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ v;
      dfs(to);
      res.push_back(id);
    }
  };
  dfs(root);
  if ((int) res.size() != cnt_edges) {
    root = -1;
    return vector<int>();
  }
  reverse(res.begin(), res.end());
  return res;
  // root == -1 if there is no path
  // (or res.empty(), but this is also true when there are no edges)
}

template <typename T>
vector<int> find_eulerian_path(const undigraph<T> &g, int &root) {
  vector<int> deg(g.n, 0);
  int cnt_edges = 0;
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    cnt_edges++;
    auto &e = g.edges[id];
    deg[e.from]++;
    deg[e.to]++;
  }
  root = -1;
  int odd = 0;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] % 2 == 1) {
      odd++;
      root = i;
    }
  }
  if (odd > 2) {  
    root = -1;
    return vector<int>();
  }
  if (root == -1) {
    root = 0;
    while (root < g.n && deg[root] == 0) {
      root++;
    }
    if (root == g.n) {
      // but actually an empty path exists...
      root = 0;
      return vector<int>();
    }
  }
  vector<bool> used(g.edges.size(), false);
  vector<int> ptr(g.n, 0);
  vector<int> res;
  function<void(int)> dfs = [&](int v) {
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      if (used[id] || (g.ignore != nullptr && g.ignore(id))) {
        continue;
      }
      used[id] = true;
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ v;
      dfs(to);
      res.push_back(id);
    }
  };
  dfs(root);
  if ((int) res.size() != cnt_edges) {
    root = -1;
    return vector<int>();
  }
  reverse(res.begin(), res.end());
  return res;
  // root == -1 if there is no path
  // (or res.empty(), but this is also true when there are no edges)
}