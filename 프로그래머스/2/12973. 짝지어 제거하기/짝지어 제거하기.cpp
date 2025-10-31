#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> stk;
    stk.push(s[0]);

    for (int i=1; i<s.length(); i++){
        if(stk.size()){
            if(stk.top() == s[i]){
                stk.pop();
            }
            else stk.push(s[i]);
            
            continue;
        }
        stk.push(s[i]);
    }
    if(stk.size())answer = 0;
    else answer =1;

    return answer;
}