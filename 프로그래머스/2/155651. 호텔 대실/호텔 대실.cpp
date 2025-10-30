#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> stringToIntTime(vector<vector<string>> v){
    vector<vector<int>> temp;
    for(int i=0; i<v.size(); i++){
        int sh = stoi(v[i][0].substr(0,2));
        int sm = stoi(v[i][0].substr(3,2));
        int eh = stoi(v[i][1].substr(0,2));
        int em = stoi(v[i][1].substr(3,2));

        int start = sh*60 + sm;
        int end = eh*60 + em + 10; // 청소시간 포함
        temp.push_back({start, end});
    }
    return temp;
}

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> v = stringToIntTime(book_time);
    sort(v.begin(), v.end()); // 시작시간 기준 오름차순

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    for(auto &t : v){
        if(!pq.empty() && pq.top() <= t[0]){
            pq.pop(); // 방 재사용 가능
        }
        pq.push(t[1]);
    }
    return pq.size();
}
