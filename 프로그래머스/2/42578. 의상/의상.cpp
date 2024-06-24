#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> mp;
    for (vector<string> temp : clothes){
        mp[temp[1]]++;
    }
    for (auto a : mp){
        answer *= a.second + 1;
    }
    answer--;
    return answer;
}