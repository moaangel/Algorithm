#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S,Ss ="", Se="", fs="", fe="";
vector<string> ret;
int main() {
	cin >> N >> S;
	
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '*')
		{
			for (int j = 0; j < i; j++)
			{
				Ss += S[j];
			}
			for (int k = i + 1; k < S.length(); k++)
			{
				Se += S[k];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		string filename = "";
		cin >> filename;
		if (filename.size() >= Ss.size() + Se.size()) {
			for (int j = 0; j < Ss.length(); j++)
			{
				fs += filename[j];
			}
			int k = filename.length() - Se.length();
			for (k; k < filename.length(); k++)
			{
				fe += filename[k];
			}
			if ((fs == Ss) && (fe == Se))
			{
				ret.push_back("DA");
			}
			else ret.push_back("NE");

			filename.erase(filename.begin(), filename.end());
			fs.erase(fs.begin(), fs.end());
			fe.erase(fe.begin(), fe.end());
		}
		else ret.push_back("NE");
	}
	for (int i = 0; i < ret.size(); i++)
	{
		string a;
		a = ret[i];
		if (i == ret.size() - 1) {
			cout << a;
			exit(0);
		}
		cout << a << "\n";
	}
	return 0;
}
