#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int visited[502][502];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int idx, int n, int m, vector<vector<int>>& land, int& cnt) {
    cnt++;
    visited[y][x] = idx;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || !land[ny][nx]) continue;
        dfs(ny, nx, idx, n, m, land, cnt);
    }
}

int solution(vector<vector<int>> land) {
    int n = land.size();     // Number of rows
    int m = land[0].size();  // Number of columns
    
    // Reset visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Map to store size of each connected component
    map<int, int> component_size;
    int next_component_id = 1;
    
    // Find all connected components
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && land[i][j]) {
                int cnt = 0;
                dfs(i, j, next_component_id, n, m, land, cnt);
                component_size[next_component_id] = cnt;
                next_component_id++;
            }
        }
    }
    
    // Calculate the maximum oil that can be collected by drilling in each column
    vector<int> oil_per_column(m, 0);
    for (int j = 0; j < m; j++) {
        // Set to keep track of components we've already counted in this column
        set<int> counted_components;
        
        for (int i = 0; i < n; i++) {
            int component_id = visited[i][j];
            if (component_id > 0 && counted_components.find(component_id) == counted_components.end()) {
                oil_per_column[j] += component_size[component_id];
                counted_components.insert(component_id);
            }
        }
    }
    
    // Find the maximum oil
    return *max_element(oil_per_column.begin(), oil_per_column.end());
}