#include<iostream>
#include<vector>

using namespace std;

int N, M;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    for (int i=0; i<4; ++i) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) continue;
        if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
            visited[nextx][nexty] = true;
            dfs(nextx, nexty, grid, visited);
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (!visited[i][j] && grid[i][j] == 1) {
                ++result;
                visited[i][j] = true;
                dfs(i, j, grid, visited);
            }
        }
    }

    cout << result << endl;
    return 0;
}