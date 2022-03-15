#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int *C;
int *P;
void GeraCrivo (int);
void GeraPrimos(int);
bool isPrime(int);
int np;
int main(){
    int n;
    int veprimo;
    scanf("%d", &n);
    for(int i = 0; i<3; i++){
        scanf("%d",&veprimo);
        C = (int *) malloc(veprimo*sizeof(int));
        P = (int *) malloc(veprimo*sizeof(int));
        GeraCrivo(veprimo);
        GeraPrimos(veprimo);
        if ((isPrime(veprimo))==true)
        {
            printf("Prime\n");
        }
        else{
            printf("Not Prime\n");
        }
        free(C);
        free(P);
        
    }
    return 0;
}

void GeraCrivo (int n){
    int t = 0;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        C[i] = i;
        
    }
    t = 2;
    for(int i = 1; i<=(n/2); i++){
        C[t] = 2;
        t = t+2;
    }
    for (int i = 3; i <= ceil(sqrt(n)); i++)
    {
        if (C[i]== i)
        {
            t = i*i;
            d = i+i;
            while (t<= n)
            {
                if (C[t] ==t)
                {
                    C[t] = i;
                }
                t =t+d;
            }
            
        }
            
    }
        
}



void GeraPrimos(int n){
    np = 0;
    for (int i = 2; i < n; i++)
    {
        if(C[i]==i){
            np = np + 1;
            P[np] = i;
        }
    }
    
}

bool isPrime(int n){
    
    for (int  i = 1; i < np; i++)
    {
           
        if ((n % P[i]) == 0)
        {
            
            if (n!=P[i])
            {
                return false;
            }
            return true;
            
        }
    }
    return true;
    
}