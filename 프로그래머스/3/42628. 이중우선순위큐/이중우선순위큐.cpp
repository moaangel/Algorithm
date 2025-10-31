#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    char lastOrder = ' ';
    for (int i=0; i<operations.size(); i++){
        char order = operations[i][0];
        int orderNum = stoi(operations[i].substr(2, operations[i].size()-2));
        
        if(order == 'I'){
            dq.push_back(orderNum);
            sort(dq.begin(),dq.end());
        }
        else{
            if(dq.size() == 0) continue;
            else{
                if(orderNum == 1){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
        }
    }
    if(dq.size()){
        answer.push_back(dq[dq.size()-1]);        
        answer.push_back(dq[0]);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);

    }
    return answer;
}