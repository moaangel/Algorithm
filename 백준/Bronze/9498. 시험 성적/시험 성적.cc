#include <iostream>
#include <string>
using namespace std;


int main()
{
	int A;
	cin >> A;
	if (A >= 90 && A <= 100)
		cout << "A" << endl;
	else if (A >= 80 && A <= 89)
		cout << "B" << endl;
	else if (A >= 70 && A <= 79)
		cout << "C" << endl;
	else if (A >= 60 && A <= 69)
		cout << "D" << endl;
	else
		cout << "F" << endl;
}