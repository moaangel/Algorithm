#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> mp;
    for (int i=0; i<clothes.size(); i++){
        mp[clothes[i][1]]++;
    }
    for (auto a : mp){
        answer *= (a.second + 1);
    }
    answer--;
    return answer;
}