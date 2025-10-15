#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[103][103];
bool cantVisit[103][103];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (vector<int> v : puddles){
        cantVisit[v[1]][v[0]] = true;
    }
    dp[1][1] = 1;
    for (int i=1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if(cantVisit[i][j])continue;
            if(cantVisit[i-1][j])
                dp[i][j] += dp[i][j-1] % 1000000007;
            else if(cantVisit[i][j-1])
                dp[i][j] += dp[i-1][j] % 1000000007;
            else
                dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            dp[i][j] %= 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}