#include<stdlib.h>
#include<stdio.h>

main(){
    int n,
        f0, f1, f;
    
    scanf( "%d", &n );
    
    for(int i = 0; i <= n; i++){
        if(i == 0)
            f0 = f1 = f = 0;
        else if(i == 1)
            f1 = f = 1;
        else{
            f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
    }
    printf("%d", f);
    return 0;
}
