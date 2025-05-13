#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t, n;
int main() {
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        vector<int> v;
        map<int, int> teamCnt, currentTeamCnt, teamScore, fifthRunnerScore;
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;
            v.push_back(num);
            teamCnt[num]++;
        }
        int score = 1;
        for (int i = 0; i < v.size(); i++) {
            if (teamCnt[v[i]] != 6) continue; // 6명 없는 팀은 패스
            currentTeamCnt[v[i]] += 1;

            if (currentTeamCnt[v[i]] <= 4) {
                teamScore[v[i]] += score;
            }
            else if (currentTeamCnt[v[i]] == 5) {
                fifthRunnerScore[v[i]] = score;
            }

            score++;
        }

        int minScore = 2e9, winner = -1;
        for (auto temp : teamScore) {
            int team = temp.first;
            int team_total_score = temp.second;
            if (team_total_score < minScore) {
                minScore = team_total_score;
                winner = team;
            }
            else if (team_total_score == minScore) {
                // 다섯번째 주자 등수 비교
                if (fifthRunnerScore[team] < fifthRunnerScore[winner]) {
                    winner = team;
                }
            }
        }

        cout << winner << endl;
    }
}
