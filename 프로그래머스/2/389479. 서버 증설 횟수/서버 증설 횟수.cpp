#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[24];
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for (int i=0; i<players.size(); i++){
        if((arr[i]+1) * m <= players[i]){
            answer += (players[i] / m - arr[i]);
            for (int j = i+k-1; j >= i; j--){
                if(j >= 24)continue;
                arr[j] += (players[i] / m - arr[i]);
            }
        }
    }
    return answer;
}