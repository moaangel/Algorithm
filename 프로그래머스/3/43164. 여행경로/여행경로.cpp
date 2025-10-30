#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool flag = false;
vector<string> temp;
void dfs(map<string, vector<pair<string,bool>>>& node, int cnt, int ticketsCnt, string current, vector<string>& ans){
    if(cnt == ticketsCnt){
        flag = true;
        temp = ans;
        return;
    }
    if(flag)return;
    
    for (auto& nextRoot : node[current]){
        if(!nextRoot.second){
            nextRoot.second = true;
            ans.push_back(nextRoot.first);
            dfs(node, cnt+1, ticketsCnt, nextRoot.first, ans);
            ans.pop_back();
            nextRoot.second = false;
            
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<pair<string,bool>>> node;
    for (int i=0; i<tickets.size(); i++){
        node[tickets[i][0]].push_back({tickets[i][1],false});
    }
    for(auto &p : node){
        sort(p.second.begin(), p.second.end());
    }

    int n = tickets.size();
    answer.push_back("ICN");
    dfs(node, 0, n, "ICN", answer);
    answer = temp;
    return answer;
}