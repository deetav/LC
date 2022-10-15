//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    struct Node {
        int x, y, dist;
    };
    vector<int> row = {-1, 0, 0, 1};
    vector<int> col = {0, -1, 1, 0};
    
    bool isValid(vector<vector<int>> const &mat, vector<vector<bool>> &visited,
                 int row, int col) {
            return (row >= 0 && row < mat.size()) && (col >= 0 && col < mat[0].size())
                   && mat[row][col] && !visited[row][col];
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
            if (grid.size() == 0 || grid[source.first][source.second] == 0 ||
                grid[destination.first][destination.second] == 0) {
                    return -1;
            }
            int M = grid.size();
            int N = grid[0].size();
            vector<vector<bool>> visited;
            visited.resize(M, vector<bool>(N));
            queue<Node> q;
            int i = source.first;
            int j = source.second;
            visited[i][j] = true;
            q.push({i, j, 0});
            int min_dist = INT_MAX;
            while (!q.empty()) {
                    Node node = q.front();
                    q.pop();
                    int i = node.x, j = node.y, dist = node.dist;
                    if (i == destination.first && j == destination.second) {
                            min_dist = dist;
                            break;
                    }
                    for (int k = 0; k < 4; k++) {
                            if (isValid(grid, visited, i + row[k], j + col[k])) {
                                    visited[i + row[k]][j + col[k]] = true;
                                    q.push({i + row[k], j + col[k], dist + 1});
                            }
                    }
            }
            
            if (min_dist != INT_MAX) {
                    return min_dist;
            }
            
            return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends