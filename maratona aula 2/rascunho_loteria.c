#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
// 1 - True
// 0 - False
int **tabela;
void preenchetable(int n, int m);
int ehprimo(int num);
long int verificacombLinha(int n,int m, int k);
long int verificacombColuna(int n, int m, int k);
long int Combinacao(int ene, int pe);
long int fatorial(int numb);
void esvaziatable(int n, int m);


int main(){
    int n = -1;
    int m = -1;
    int k = -1;
    int continua = 1;
    long int operator1 = 0;
    long int operator2 = 0;
    while(true){
        scanf("%d %d %d", &n,&m,&k);
        if((n==0) && (m==0) && (k==0)){
            break;
        }
        preenchetable(n,m);
        long int somacombi = 0;
        operator1 = verificacombColuna(n,m,k);
        operator2 = verificacombLinha(n,m,k);
        somacombi = operator1 + operator2;
        printf("%ld\n", somacombi);
        esvaziatable(n,m);

    }
    return 0;
}

void preenchetable(int n, int m){
    tabela = (int**)malloc((ceil(sqrt(n))) * sizeof(int*));
    for (int i = 0; i <=n; i++)
        tabela[i] = (int*)malloc(m * sizeof(int));
    for(int i = 0; i<=n; i++){
       // printf("i am here");
        for (int j = 0; j <=(m-1) ; j++)
        {
            tabela[i][j] = (i*m) + j;
            printf("%d \t", tabela[i][j]);
        }
        printf("\n");
    }
    
}

int ehprimo(int num){
    for(int f=2; f<=(ceil(sqrt(num))); f++){
        printf("i am here2");
        if(num % f == 0){
            return 0;
        }
    }
    return 1;
    
  /*  para  i ← 2 até ⌈√(n)⌉ faça
    		se n mod i = 0 então
			retornar Falso
    retornar Verdadeiro
    */
}

long int verificacombLinha(int n,int m, int k){
    //contanaoprimo eh o n da combinacao
    int contanaoprimo = 0;
    long int somacomb = 0;
    long int comb = 0;
    for(int i = 0; i<=n; i++){
        for (int j = 0; j <=(m-1) ; j++)
        {
            printf("i am here3");
            if ((ehprimo(tabela[i][j]))==0)
            {
                contanaoprimo++;
            }
        }

        comb = Combinacao(contanaoprimo, k);
        somacomb = somacomb + comb;
    }
    return somacomb;
    
}

long int verificacombColuna(int n, int m, int k){
    int contanaoprimo = 0;
    long int somacomb = 0;
    long int comb = 0;
    for(int i = 0; i<=n; i++){
        printf("i am here4");
        for (int j = 0; j <=(m-1) ; j++)
        {
            if ((ehprimo(tabela[j][i]))==0)
            {
                contanaoprimo++;
            }
        }

        comb = Combinacao(contanaoprimo, k);
        somacomb = somacomb + comb;
    }
    return somacomb;
}




long int Combinacao(int ene, int pe){
    long int comb = 0;
    long int op1 = 0;
    long int op2 = 0;
    if (ene == pe)
        {
            comb = 1;
            return comb;
        }
    else if(ene > pe){
        printf("i am here5 %d n e p %d\n", ene, pe);
        op1 = (fatorial(ene));
        op2 = ((fatorial(ene - pe)) * (fatorial(pe)));
        comb = op1/op2;
        return comb;
        
    }
    else{
        comb = 0;
        return 0;
    }
}

long int fatorial(int numb){
    long int fatorialn;
    /*if(numb==1){
        return numb;
    }
    else{
        printf("i am here6 numb %d\n", numb);

        return (numb * (fatorial(numb-1)));
    }*/
    for(fatorialn = 1; numb > 1; numb = numb - 1){
        fatorialn = fatorialn * numb;
        printf("i am here6 numb %d\n", numb);
    }
    return fatorialn;

}
void esvaziatable(int n, int m){
    for(int i = 0; i<=n; i++){
       // printf("i am here");
        for (int j = 0; j <=(m-1) ; j++)
        {
            tabela[i][j] = 0;
            printf("%d \t", tabela[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i <=n; i++){
        free(tabela[i]);
    }
    free(tabela);
    
}