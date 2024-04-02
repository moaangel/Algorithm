#include <iostream>
#include <algorithm>
using namespace std;

int a,b,c,d,e,f,retx,rety;
int main() {
	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	if (a == c)
		retx = e;
	else if (a == e)
		retx = c;
	else retx = a;
	if (b == d)
		rety = f;
	else if (b == f)
		rety = d;
	else rety = b;
	cout << retx << " " << rety << endl;
}