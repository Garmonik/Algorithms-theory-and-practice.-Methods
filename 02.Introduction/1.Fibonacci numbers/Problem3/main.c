#include<stdio.h>
#include<math.h>

int main(){
    long long n;
    int m;

    scanf("%ld, %d", &n, &m);

    long long a = 0;
    long long b = 1;
    int i = 2;
    long long piz[m * 6];

    piz[0]=0;
    piz[1]=1;

    for (; i <=m * 6; i++){
        long long temp = a + b;
        a = b;
        b = temp % m;
        piz[i] = b;

        if (piz[i]==1 && piz [i-1]==0) break;
    }
    int mod = n % (i-1);
    printf("%ld", piz[mod]); 
    return 0;
}
