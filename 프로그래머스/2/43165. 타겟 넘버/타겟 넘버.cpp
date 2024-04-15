#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &v,int num,int idx, int tar, int &ret){
    if(idx == v.size()-1){
        if (num==tar) {
            ret++;
            return;
        }
        else return;
    }
    dfs(v,num + v[idx+1],idx +1,tar,ret);
    dfs(v,num - v[idx+1],idx +1,tar,ret);
    
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers,0,-1,target,answer);
    return answer;
}