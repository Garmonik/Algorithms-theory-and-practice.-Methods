#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int F[n];
	F[0] = 0;
	F[1] = 1;
	for(int i = 2; i < n + 2; i++){
		F[i] = (F[i - 1] + F[i - 2]) % 10;
	}
	printf("%d", F[n]);
}
