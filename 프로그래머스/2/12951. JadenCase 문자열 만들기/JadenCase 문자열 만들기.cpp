#include <string>
#include <vector>
using namespace std;

bool checkNum(char c){
    if (c < 65)return true;
    else return false;
}
string solution(string s) {
    string answer = "";
    bool flag = true;
    for (int i=0; i<s.length(); i++){
        if (flag){
            if(!checkNum(s[i]) && s[i] >= 97){
                answer += (s[i] - 32);
            }
            else{
                answer += s[i];
            }
            if(s[i] != ' ')
                flag = false;
            continue;
        }
        else{
            if(s[i] == ' '){
                answer += s[i];
                flag = true;
                continue;
            }
            if(s[i] < 97)
                answer += (s[i] + 32);
            else answer += s[i];
        }
    }
    return answer;
}