#include <string>
#include <vector>

using namespace std;

string go(string str, int& cnt){
    string temp = "";
    for (int i=0; i<str.length(); i++){
        if(str[i] == '0'){
            cnt++;
            continue;
        }
        temp += str[i];
    }
    int tempL = temp.length();
    string binary = "";
    while(tempL > 0){
        if(tempL % 2 == 1)binary += '1';
        else binary += '0';
        tempL /= 2;
    }
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    string target = s;
    int tern = 0;
    int eraseCnt = 0;
    while(target != "1"){
        tern++;
        target = go(target,eraseCnt);
    }
    answer.push_back(tern);
    answer.push_back(eraseCnt);
    return answer;
}