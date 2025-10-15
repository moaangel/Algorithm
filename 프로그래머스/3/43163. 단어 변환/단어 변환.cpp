#include <string>
#include <vector>
#include <iostream>
using namespace std;

int minCnt = 52;
bool visited[52];

void dfs(string begin, string target, vector<string> words, int cnt){
    if(cnt >= minCnt)return;
    if(begin == target){
        minCnt = minCnt < cnt ? minCnt: cnt;
        return;
    }
    
    for (int i=0; i<words.size(); i++){
        if(visited[i])continue;
        
        int charCnt = 0;
        for (int j = 0; j<begin.length(); j++){
            if(charCnt > 1)break;
            if(begin[j] != words[i][j]){
                charCnt++;
            }
        }
        if(charCnt == 1){
            visited[i] = true;
            dfs(words[i], target, words, cnt+1);
            visited[i] = false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin,target,words, 0);
    if (minCnt != 52) answer = minCnt;
    return answer;
}