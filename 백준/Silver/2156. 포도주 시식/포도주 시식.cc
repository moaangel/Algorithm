#include <bits/stdc++.h>
using namespace std; 
int arr[10010], d[10010];   
int main(){   
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];   
    d[1] = arr[1]; d[2] = arr[1] + arr[2]; 
    for(int i = 3; i <= n; i++)   
        d[i] = max({d[i - 3] + arr[i - 1]+ arr[i], d[i - 2] + arr[i], d[i - 1]});  
    cout << d[n];
}
