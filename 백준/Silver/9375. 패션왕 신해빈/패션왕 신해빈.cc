#include <iostream>
#include <map>
#include <string>

using namespace std;

int t,n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	
	for (int i = 0; i < t; i++){
		map<string, int> cloth;
		cin >> n;
		
		for (int j = 0; j < n; j++){
			cin.ignore();
			string s,r;
			getline(cin, s);
			int a = s.find(" ");
			r = s.substr(a+1);
			cloth[r]++;
		}
		long long ret = 1;
		for (auto e : cloth){
			ret *= (e.second + 1);
		}
		ret--;
		cout << ret << "\n";
	}
}