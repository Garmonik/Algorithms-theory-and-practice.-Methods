#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, j=0 ,p ,s=0;
    
    scanf("%d", &n);
    p = n;

            for(i = 1; i <= n; i++){
                if(p - i >= 0){
                    p -= i;
                    s = i;
                }
                else{
                    s = s + p;
                    break;
                }
            }

            printf("%d\n", i - 1);

            for(j = 1; j < i - 1; j++)
                printf("%d ", j);

            printf("%d", s);

}

