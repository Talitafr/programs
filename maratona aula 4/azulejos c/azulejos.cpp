#include <stdio.h>
#include <math.h>
long long int cont_azul(int, int, int);
long long int MDC(int, int);
long long int MMC(int, int);



int main(){
    int N =-1;
    int A = -1; 
    int B = -1;
    while(true){
        scanf("%d %d %d", &N, &A, &B);
        if((N==0)&&(A==0)&&(B==0)){
            break;
        }
        else{
            printf("%lld\n",cont_azul(N,A,B));
        }
    }
}

long long int cont_azul(int n, int a, int b){
    int ab = 0;
    int qa = 0;
    int qb = 0; 
    int qab = 0;
    int result = 0;

    qa = n/a;
    qb = n/b;
    ab = MMC(a,b);
    qab = n/ab;
    result = qa + qb - qab;
    return result;
}

long long int MDC(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return MDC(b,a%b);
    }
}

long long int MMC(int a, int b){
    int d = MDC(a,b);
    int m = a*(b/d);
    return m;
}