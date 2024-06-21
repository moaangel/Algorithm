#include <string>
#include <vector>

using namespace std;

int visited[202];
int ret =0;

void dfs(int idx, vector<vector<int>> computers){
    for(int i = 0; i < computers[idx].size(); i++){
        if (computers[idx][i] && !visited[i]){
            visited[i] = 1;
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0; i<computers.size(); i++){
        if (!visited[i]){
            visited[i] = 1;
            ret++;
            dfs(i, computers);
        }
        
    }
    answer = ret;
    return answer;
}