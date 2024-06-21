#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int vsize = nums.size() / 2;
    map<int,int> mp;
    for (int num : nums){
        mp[num]++;
    }
    if (mp.size() >= vsize)answer = vsize;
    else answer = mp.size();
    return answer;
}