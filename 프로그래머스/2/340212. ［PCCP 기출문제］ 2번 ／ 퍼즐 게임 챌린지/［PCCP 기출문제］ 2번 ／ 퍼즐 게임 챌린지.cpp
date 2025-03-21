#include <string>
#include <vector>

using namespace std;

bool check(int level, vector<int> diffs, vector<int> times, long long limit){
    long long temp = times[0];
    for (int i=1; i<times.size(); i++){
        if(level >= diffs[i]){
            temp += times[i];
        } else{
            temp += (times[i-1] + times[i]) * (diffs[i] - level) + times[i];
        }
        
        if(temp > limit) return false;
    }
    
    return temp <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int l = 1, r = 100000;
    while(l<=r){
        int mid = (l+r) / 2;
        if(check(mid,diffs,times,limit)){
            answer = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    return answer;
}