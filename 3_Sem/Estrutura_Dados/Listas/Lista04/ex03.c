#include <stdio.h>

int simularInspecaoTV();

int main()
{
	printf("Apos 8h sairam %d TVs\n", simularInspecaoTV());
	return 0;
}


int simularInspecaoTV()
{
	int f[480];
	int s = 0;
	int t = 0;
	for (int i = 0; i < (8 * 60); i++) 
	{
		if (i % 3 == 0) {
			f[t] = t;
			t++;
		} else if (i % 4 ==0) {
			s++;
		}
	}
	return s;
}

/*
int simularInspecaoTV()
{
	int e = 0;
	int s = 0;
	for (int i = 0; i < (8 * 60); i++) 
	{
		if (i % 3 == 0) {
			e++;
		} else if (i % 4 ==0) {
			s++;
		}
	}
	return s;
}
*/
