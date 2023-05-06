#include <iostream>
#include <string>
using namespace std;


int main()
{
	int A;
	cin >> A;
	if ((A % 4) == 0 && A % 100 != 0 || A % 400 == 0)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}