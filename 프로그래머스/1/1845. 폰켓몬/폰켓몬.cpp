#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size() / 2;
    map<int,int> counts;
    
    for (int num : nums){
        counts[num]++;
    }
    int temp =0;
    for (auto a : counts){
        temp++;
    }
    answer = answer < temp ? answer : temp;
    return answer;
}