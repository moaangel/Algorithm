#include <string>
#include <vector>

using namespace std;

int toSec(string s){
    int ret = 0;
    ret += (s[0]-'0') * 600;
    ret += (s[1]-'0') * 60;
    ret += (s[3]-'0') * 10;
    ret += (s[4]-'0');
    return ret;
}

string toTime(int sec){
    string ret = "";
    ret += (sec/600) + '0';
    sec -= (sec/600) * 600;
    ret += (sec/60) + '0';
    sec -= (sec/60) * 60;
    ret += ':';
    ret += (sec/10) + '0';
    sec -= (sec/10) * 10;
    ret += sec + '0';
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int now = toSec(pos);
    int opStart = toSec(op_start);
    int opEnd = toSec(op_end);
    int videoLen = toSec(video_len);
    if(now >= opStart && now <= opEnd) now = opEnd;
    
    for (int i=0; i<commands.size(); i++){
        if(commands[i] == "next"){
            if(now + 10 > videoLen)now = videoLen;
            else now += 10;
        }
        else {
            if(now - 10 < 0) now = 0;
            else now -= 10;
        }
        if(now >= opStart && now <= opEnd) now = opEnd;
    }
    answer = toTime(now);
    return answer;
}