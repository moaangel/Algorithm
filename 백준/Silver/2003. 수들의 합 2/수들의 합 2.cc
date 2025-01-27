#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ret;
vector<int> v;
int pnum[10002];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int num =0;
        cin >> num;
        v.push_back(num);
    }
    for (int i=0; i<n; i++){
        pnum[i+1] = pnum[i] + v[i];
    }
    for (int i=1; i<=n; i++){
        int temp =0;
        if(pnum[i] == m){
            ret++;
            continue;
        }
        else{
            if(pnum[i] < m){
                continue;
            }
            else{
                temp = pnum[i];
                for (int j=0; j<i; j++){
                    int tnum = pnum[i] - pnum[j];
                    if(tnum > m)continue;
                    else if(tnum == m){
                        ret++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    cout << ret << '\n';
}