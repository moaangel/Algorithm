#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int totalWorks =0;
    priority_queue<int> pq;
    for (int i=0; i<works.size(); i++){
        pq.push(works[i]);
        totalWorks+= works[i];
    }
    if(totalWorks <= n) return 0;
    for(int i=0; i<n; i++){
        int temp = pq.top();
        temp--;
        pq.pop();
        pq.push(temp);
    }
    while(pq.size()){
        answer += (pq.top() * pq.top());
        pq.pop();
    }
    
    return answer;
}