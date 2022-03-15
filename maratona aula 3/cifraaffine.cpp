#include <stdio.h>
#include <math.h>
#include <iostream>
int xa = 0;
int ya = 0;
int *saida = NULL;
int *vdecode = NULL;
int MDCE(int, int, int, int);
void dec_inv(int, int, int);
int MDC(int, int);
int n = -1;



int main(){
    int t = 0;
    int a = 0;
    int b = 0;
    
    while (scanf("%d", &n)>0){
        vdecode = (int *) calloc(n,sizeof(int));
        for(int i=0; i<n; i++){
            std::cin >> vdecode[i];
        }
        scanf("%d %d %d", &t,&a,&b);
        if((MDC(a,t))==1){
            saida = (int *) calloc(n,sizeof(int));

            dec_inv(a,b,t);
            for(int i=0; i<n; i++){
                printf("%d\t", saida[i]);
            }
            printf("\n");
            free(saida);
            free(vdecode);
        }
        else{
            printf("DECIFRAGEM AMBIGUA\n");
        }
    }
}

int MDCE(int a, int b, int x, int y){
    if( b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        int d = MDCE(b,a%b,xa,ya);
        x = ya;
        y = xa - floor(a/b) * y;
        return d;
    }
    
}

void dec_inv(int a, int b, int t){
    for(int i=0; i<n; i++){
        int A = MDCE(a,t,0,0);
        int interm = (vdecode[i] - b) * A;
        saida[i] = (interm % t);
    }
}

int MDC(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}