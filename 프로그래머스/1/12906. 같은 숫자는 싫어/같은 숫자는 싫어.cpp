#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int visited[10] = {0,};
    for (int i=0; i<arr.size(); i++){
        if (i==0)answer.push_back(arr[i]);
        else{
            if(arr[i] == arr[i-1]) continue;
            else answer.push_back(arr[i]);
        }
    }
    
    return answer;
}