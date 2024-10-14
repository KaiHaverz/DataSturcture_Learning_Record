#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(vector<vector<char>>& maze, int n, int m) {

    queue<pair<int, int>> q;

    q.push({0, 0});


    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();


        if (x == n - 1 && y == m - 1) {
            return true;
        }


        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];


            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }


    if (bfs(maze, n, m)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}