#include <stdio.h>

int TTT (int x[], int n);
int PPP (int x[], int n);

int main ()
{
	int n = 10;
	int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("TTT %d \n", TTT (x, n-1));
	printf("PPP %d \n", PPP (x, n-1));
	return 0;
}

int TTT (int x[], int n) {
   if (n == 0) return 0;
   if (x[n] > 0) return x[n] + TTT (x, n-1);
   else return TTT (x, n-1);
}

int PPP (int x[], int n) {
	int p = 0;
	for (n; n > 0; n--) {
		p += x[n];
	}
	return p;
}

