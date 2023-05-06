#include <iostream>
#include <string>
using namespace std;


int main()
{
	int A; // 472
	int B; // 385
	cin >> A;
	cin >> B;
	cout << A * (B % 10) << endl;
	cout << A * ((B / 10) % 10) << endl;
	cout << A * (B / 100) << endl;
	cout << A * B << endl;

}