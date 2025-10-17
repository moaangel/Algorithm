#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int temp =0;
    for (int i = 0; i < diffs.size(); i++){
        temp = max(temp, diffs[i]);
    }
    int l = 1, r = temp;

    while(l<=r){
        int result = (l+r) / 2;
        long long pTime = 0;
        for (int i = 0; i<diffs.size(); i++){
            if(diffs[i] <= result){
                pTime += times[i];
            }
            else {
                pTime += (((diffs[i] - result) * (times[i] + times[i-1])) + times[i]);
            }
            if(pTime > limit)break;
        }
        if(pTime <= limit){
            answer = result;
            r = result - 1;
        }
        else l = result + 1;
    }
    
    return answer;
}