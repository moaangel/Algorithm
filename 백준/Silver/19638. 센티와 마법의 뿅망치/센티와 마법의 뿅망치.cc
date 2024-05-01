#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, Hcenti, t;
    cin >> n >> Hcenti >> t;
    priority_queue<int, vector<int>, less<int>> Hgiant;
    int h;
    for(int i = 0; i < n; i++){
        cin >> h;
        Hgiant.push(h);
    }
    for(int i = 0; i < t; i++){
        int tallest = Hgiant.top();
        if(tallest < Hcenti){
            cout << "YES\n" << i << "\n";
            return 0;
        }
        else if(tallest > 1){
            Hgiant.pop();
            Hgiant.push(tallest/2);
        }
    }
    if(Hgiant.top() < Hcenti)
        cout << "YES\n" << t << "\n";
    else
        cout << "NO\n" << Hgiant.top() << "\n";
    return 0;
}