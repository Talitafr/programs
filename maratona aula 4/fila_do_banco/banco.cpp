#include <stdio.h>
#include <math.h>

unsigned long int multimod(long long int, unsigned int, unsigned int);
int InvMod(int, int);
int MDCE(int, int, int &,int &);
long long int fatorial(int);

int main(){
    int N = -1;
    int inv = ((InvMod(6,1000000009)) % 1000000009);
    while(true){
        scanf("%d", &N);
        if(N==0){
            break;
        }
        else{
            long long int resul_fatorial = fatorial(N);
            printf("%lu\n", multimod(resul_fatorial, inv, 1000000009));
        }
    }
}


unsigned long int multimod(long long int a, unsigned int b, unsigned int n){
    long long int la,lb;
    la = a%n;
    lb = b%n;
    return ((la*lb)%n);
}

int InvMod(int b, int n){
    int x;
    int y;
    int d = MDCE(b, n, x, y);
    return ((x+n) % n);
}

int MDCE(int a, int b, int &x,int &y){
    if(b==0){
        x = 1; 
        y = 0;
        return a;
    }
    else{
        int xa;
        int ya;
        int d = MDCE(b, a%b, xa, ya);
        x = ya;
        y = xa - floor(a/b) * ya;
        return d;
    }
} 

long long int fatorial(int n){
    if(n == 1){
        return n;
    }
    else{
        return (n * (fatorial(n-1)));
    }
}