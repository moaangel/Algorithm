#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> mp1,mp2;
    for (string temp : participant){
        mp1[temp]++;
    }
    for (string temp : completion){
        mp2[temp]++;
    }
    for (string temp : participant){
        if (mp1[temp] != mp2[temp]){
            return temp;
        }
    }
    return "";
}