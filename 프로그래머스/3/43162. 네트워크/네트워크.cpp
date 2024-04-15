#include <string>
#include <vector>

using namespace std;

int visited[202];

void dfs(int here,int n, vector<vector<int>> &com){
    visited[here] = 1;
    
    for (int i =0; i<n; i++){
        if (!visited[i] && com[here][i] == 1)
            dfs(i,n,com);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}