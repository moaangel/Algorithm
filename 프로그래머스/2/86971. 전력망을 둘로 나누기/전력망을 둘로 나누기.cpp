#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dfs(int idx, vector<vector<int>>& v, vector<bool>& visited) {
    visited[idx] = true;
    int cnt = 1;
    for (int next : v[idx]) {
        if (!visited[next])
            cnt += dfs(next, v, visited);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> v(n + 1);
        vector<bool> visited(n + 1, false); 

        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }

        int num1 = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                num1 = dfs(j, v, visited);
                break; 
            }
        }

        int num2 = n - num1;
        int diff = abs(num1 - num2);
        answer = min(answer, diff);
    }
    return answer;
}
