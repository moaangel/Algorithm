#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int maxHealth = health;
    int currentTime = 0;
    int successHeal = 0;
    int attackIdx = 0;
    while(1){
        currentTime++;
        if(currentTime == attacks[attackIdx][0]){
            health -= attacks[attackIdx][1];
            if(health <= 0) return -1;
            successHeal = 0;
            attackIdx++;
            if(attackIdx == attacks.size())return health;
        }
        else{
            successHeal++;
            int banding = bandage[1];
            if(successHeal == bandage[0]){
                successHeal = 0;
                banding += bandage[2];
            }
            health = min(maxHealth, health + banding);

        }
    }
    return answer;
}