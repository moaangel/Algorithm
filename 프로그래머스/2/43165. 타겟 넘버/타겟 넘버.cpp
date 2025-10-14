#include <string>
#include <vector>

using namespace std;

int answer = 0;

void go(vector<int> numbers, int target,int sumNumber ,int idx){
    if(idx == numbers.size()){
        if (sumNumber == target){
            answer++;
            return;
        }
        else return;
    }
    
    go(numbers,target,sumNumber + numbers[idx], idx+1);
    go(numbers,target,sumNumber - numbers[idx], idx+1);
    
    return;
}

int solution(vector<int> numbers, int target) {
    go(numbers,target,0,0);
    int temp = answer;
    return temp;
}