#include <string>
#include <vector>

using namespace std;

bool check(long long mid, int n, vector<int> times){
    long long temp = 0;
    long long ans = (long long)n;
    for (int i= 0; i<times.size(); i++){
        temp += (mid / (long long)times[i]);
    }
    return temp >= ans;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l = 0, r = 900000000000000000;
    while(l<=r){
        long long mid = (l + r) / 2;
        if (check(mid, n, times)){
            answer = mid;
            r = mid-1;
        } else l = mid + 1;
    }
    
    return answer;
}