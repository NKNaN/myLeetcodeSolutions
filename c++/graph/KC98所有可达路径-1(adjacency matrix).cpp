#include <iostream>
#include <vector>
 
using namespace std;
 
int N, M;
vector<vector<int>> result;
 
void dfs(int s, int t, const vector<vector<int>> &graph, vector<int> &path) {
//   cout << "s: " << s << endl;
  for (int next = 1; next <= N; ++next) {
    if (graph[s][next] == 1) {
      path.push_back(next);
        // for (int i=0;i<path.size();++i) {
        //     cout << path[i] << ' ';}
        // cout<<endl;
      if (next == t) {
        result.push_back(path);
      }
    //   cout << "next: " <<next << endl;
      dfs(next, t, graph, path);
      path.pop_back();
    }
  }
}
 
int main() {
  cin >> N >> M;
  vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
 
  int s, t;
  while (M > 0) {
    cin >> s >> t;
    graph[s][t] = 1;
    --M;
  }
 
  vector<int> path(1, 1);
  dfs(1, N, graph, path);
 
  if (result.size() == 0) cout << -1 << endl;
 
  for (auto p : result) {
      int i;
      for (i=0; i<p.size()-1; ++i) {
          cout << p[i] << " ";
      }
      cout << p[i] << endl;
  }
 
  return 0;
}