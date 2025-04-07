#include <iostream>
#include <list>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> result;

void dfs(int s, int t, const vector<list<int>> &graph, vector<int> &path) {
  //   cout << "s: " << s << endl;
  for (auto next : graph[s]) {
    path.push_back(next);
    if (next == t) {
      result.push_back(path);
    }
    dfs(next, t, graph, path);
    path.pop_back();
  }
}

int main() {
  cin >> N >> M;
  vector<list<int>> graph(N + 1);

  int s, t;
  while (M > 0) {
    cin >> s >> t;
    graph[s].push_back(t);
    --M;
  }

  vector<int> path(1, 1);
  dfs(1, N, graph, path);

  if (result.size() == 0)
    cout << -1 << endl;

  for (auto p : result) {
    int i;
    for (i = 0; i < p.size() - 1; ++i) {
      cout << p[i] << " ";
    }
    cout << p[i] << endl;
  }

  return 0;
}