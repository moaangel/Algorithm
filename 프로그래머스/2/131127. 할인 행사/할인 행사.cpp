#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> wantCnt;
    for (int i = 0; i < want.size(); i++){
        wantCnt[want[i]] += number[i];
    }
    int i =0;
    while(1){
        if(i + 9 <= discount.size() - 1){
            map<string,int> currentCnt;
            for (int j=i; j< i+10; j++){
                currentCnt[discount[j]]++;
            }
            bool flag = false;
            for (int j=0; j<want.size(); j++){
                if (wantCnt[want[j]] > currentCnt[want[j]]){
                    flag = true;
                    break;
                }
            }
            if(!flag)answer++;
            i++;
        }
        else break;
    }

    return answer;
}