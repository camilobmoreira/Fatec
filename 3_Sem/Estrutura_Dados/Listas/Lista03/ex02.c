#include <stdio.h>
#include <stdlib.h>

//void * organizaSubVetor(int v[], int iniSubV1, int finSubV1, int iniSubV2, int finSubV2);
int * organizaSubVetor(int v[], int iniSubV1, int finSubV1, int iniSubV2, int finSubV2);

int main() {
	int v[8] = {1, 3, 5, 6, 2, 4, 7, 8};
	int *p;
	p = organizaSubVetor(v, 0, 4, 4, 8);
	
	for (int i = 0; i < 8; i++) {
		printf("%d \n", p[i]);
	}
}


//void * organizaSubVetor(int v[], int iniSubV1, int finSubV1, int iniSubV2, int finSubV2) {
int * organizaSubVetor(int v[], int iniSubV1, int finSubV1, int iniSubV2, int finSubV2) {
	int n = (finSubV1 - iniSubV1) + (finSubV2 - iniSubV2);
	int temp[n];
	int i = 0;
	
	while (iniSubV1 < finSubV1 || iniSubV1 < finSubV1) {
		if (v[iniSubV1] < v[iniSubV2]) {
			temp[i++] = v[iniSubV1++];
		}
		else if (v[iniSubV2] < v[iniSubV1]) {
			temp[i++] = v[iniSubV2++];
		}
		if (iniSubV1 == finSubV1) {
			for (i; i < n; i++) {
				temp[i] = v[iniSubV2++];
			}
			break;
		} else if (iniSubV2 == finSubV2) {
			for (i; i < n; i++) {
				temp[i] = v[iniSubV1++];
			}
			break;	
		}
	}

	/*
	for (i = 0; i < 8; i++) {
		v[i] = temp[i];
	}
	
	*/
	int *p = malloc(sizeof(int) * n);
	p = temp;
	
	return p;
}
