#include <stdio.h>

void semiOrganizar(int v[], int n, int p);

int main() {
	int v[8] = {7, 1, 3, 6, 9, 5, 4, 1};
	int n = 8;
	int p = 5;
	printf("Vetor inicial: \n");
	for (int i = 0; i < n; i++) {
		printf("%d \n", v[i]);
	}
	
	semiOrganizar(v, n, p);
	printf("Vetor com menor que %d (p) à esquerda e maior à direita: \n", p);
	for (int i = 0; i < n; i++) {
		printf("%d \n", v[i]);
	}
}

void semiOrganizar(int v[], int n, int p) {
	int menor[n-1];
	int maior[n-1];
	int indexOfP = 0;
	int s = 0;
	int t = 0;
	
	for (int i = 0; i < n; i++) {
		if(v[i] < p) {
			menor[s++] = v[i];
		}
		else if (v[i] > p) {
			maior[t++] = v[i];
		}
	}
	
	indexOfP = s;

	s = 0;
	t = 0;
	for (int i = 0; i < n; i++) {
		if (i < indexOfP) {
			v[i] = menor[s++];
		}
		else if (i > indexOfP) {
			v[i] = maior[t++];
		}
		else if (i == indexOfP) {
			v[i] = p;
		}
	}
}

