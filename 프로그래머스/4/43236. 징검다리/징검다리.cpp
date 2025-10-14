#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int solution(int distance, vector<int> rocks, int n) {
    if(n == rocks.size())return distance;
    int answer = 0;        
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    int l = 1, r = distance;
    while(l<=r){
        int mid = (l + r) / 2;
        int prev = 0;
        int removeCnt = 0;
            
        for (int i = 1; i<rocks.size(); i++){
            if(rocks[i] - prev < mid){
                removeCnt++;
            }
            else{
                prev = rocks[i];
            }
                
                
        }
        if(removeCnt > n){
            r= mid-1;
        } else {
            answer = mid;
            l = mid+1;
        }
    }
        
    return answer;
}