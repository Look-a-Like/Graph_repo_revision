#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the length of matrix:";
    cin >> n;
    cout << "Enter the breadth of matrix:";
    int m;
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int tm = 0;
    int drow[] = {0, 1, 0, -1};
    int dcol[] = {1, 0, -1, 0};

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    cout << tm << endl;

    return 0;
}
