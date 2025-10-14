#include <string>
#include <vector>

using namespace std;

int visited[202];

void dfs(int idx, vector<vector<int>> computers) {
    for (int i=0; i<computers.size(); i++){
        if(i == idx || computers[idx][i] == 0 || visited[i])continue;
        visited[i] = 1;
        dfs(i,computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0; i<n; i++){
        if(visited[i] == 1)continue;
        else{
            answer++;
            visited[i] = 1;
            dfs(i,computers);
        }
    }
    return answer;
}