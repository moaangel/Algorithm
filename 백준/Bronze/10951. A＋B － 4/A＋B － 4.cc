#include <iostream>
using namespace std;
 
int main(int argc, const char *argv[]) {
 
	int a, b;
	while (!(cin >> a >> b).eof()) {
		cout << a + b << "\n";
	}
 
	return 0;
}