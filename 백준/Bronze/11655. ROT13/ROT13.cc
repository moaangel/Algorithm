#include <iostream>
#include <string>

using namespace std;

string S;
int main() {
	getline(cin, S);
	
	for (int i = 0; i < S.length(); i++)
	{
		if ((S[i] >= 65 && S[i] <= 77) || (S[i] >= 97 && S[i] <= 109))
			S[i] += 13;
		else if ((S[i] >= 78 && S[i] <= 90) || (S[i] >= 110 && S[i] <= 122))
			S[i] -= 13;
	}
	cout << S;
}
