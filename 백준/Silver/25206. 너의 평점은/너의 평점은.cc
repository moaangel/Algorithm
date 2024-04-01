#include <stdio.h>

int main() {
	char sub[51], alp[3];
	float num,h=0.0;
	int i;
	float total = 0;
	float a = 20;
	for (i = 1; i <= 20; i++) {
		scanf("%s %f %s", sub, &num, alp);
		if (alp[0] == 'A' && alp[1] == '+') total += 4.5*num;
		if (alp[0] == 'A' && alp[1] == '0') total += 4.0*num;
		if (alp[0] == 'B' && alp[1] == '+') total += 3.5*num;
		if (alp[0] == 'B' && alp[1] == '0') total += 3.0*num;
		if (alp[0] == 'C' && alp[1] == '+') total += 2.5*num;
		if (alp[0] == 'C' && alp[1] == '0') total += 2.0*num;
		if (alp[0] == 'D' && alp[1] == '+') total += 1.5*num;
		if (alp[0] == 'D' && alp[1] == '0') total += 1.0*num;
		if (alp[0] == 'F') total += 0.0*num;
		if (alp[0] == 'P') num =0.0;
		h += num;
	}
	printf("%f", total / h);
}