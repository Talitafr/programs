#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
// 1 - True
// 0 - False
int **tabela;
void preenchetable(int n, int m);
int ehprimo(int num);
unsigned long long int verificacombLinha(int n,int m, int k);
unsigned long long int verificacombColuna(int n, int m, int k);
unsigned long long int Combinacao(int ene, int pe);
unsigned long long int fatorial(int numb);
void esvaziatable(int n, int m);


int main(){
    int n = -1;
    int m = -1;
    int k = -1;
    int continua = 1;
    unsigned long long int operator1 = 0;
    unsigned long long int operator2 = 0;
    while(true){
        unsigned long long int somacombi = 0;
        scanf("%d %d %d", &n,&m,&k);
        if((n==0) && (m==0) && (k==0)){
            break;
        }
        else if((k>n) && (k>m) ){
            somacombi = 0;
            printf("%llu\n", somacombi);
        }
        else{
            preenchetable(n,m);
            
            operator1 = verificacombColuna(n,m,k);
            operator2 = verificacombLinha(n,m,k);
            somacombi = operator1 + operator2;
            printf("%llu\n", somacombi);
            esvaziatable(n,m);   
        }
        

    }
    return 0;
}

void preenchetable(int n, int m){
    tabela = (int**) malloc((n) * sizeof(int*));
    for (int i = 0; i <n; i++){
        tabela[i] = (int*) malloc(m * sizeof(int));
    }
    for(int i = 0; i<n; i++){
       
        for (int j = 0; j <m ; j++)
        {
            tabela[i][j] = (i*m) + j;
            
        }
        
    }
    
}

int ehprimo(int num){
    if((num == 0) || (num == 1)){
        return 0;
    }
    else if(num==2){
        return 1; //Primo
    }
    else{
        for(int f=2; f<=(ceil(sqrt(num))); f++){
        
            if(num % f == 0){
                return 0;
                // Nao primo
            }
        }
        return 1;
    }

}

unsigned long long int verificacombLinha(int n,int m, int k){
    int contanaoprimo = 0;
    unsigned long long int somacomb = 0;
    unsigned long long int comb = 0;
    for(int i = 0; i<n; i++){
        for (int j = 0; j <m ; j++)
        {
            
            if ((ehprimo(tabela[i][j]))==0)
            {
                
                contanaoprimo++;
                
            }
        }

        
        comb = Combinacao(contanaoprimo, k);
        contanaoprimo = 0;
        somacomb = somacomb + comb;
    }
    return somacomb;
    
}

unsigned long long int verificacombColuna(int n, int m, int k){
    int contanaoprimo = 0;
    unsigned long long int somacomb = 0;
    unsigned long long int comb = 0;
    for(int i = 0; i<m; i++){
        
        for (int j = 0; j <n ; j++)
        {
            if ((ehprimo(tabela[j][i]))==0)
            {
                contanaoprimo++;
                
            }
        }
        
        comb = Combinacao(contanaoprimo, k);
        contanaoprimo = 0;
        somacomb = somacomb + comb;
    }
    return somacomb;
}




unsigned long long int Combinacao(int ene, int pe){
    unsigned long long int comb = 0;
    unsigned long long int op1 = 0;
    unsigned long long int op2 = 0;
    unsigned long long int op3 = 0;
    if (ene == pe)
        {
            comb = 1;
            return comb;
        }
    else if(ene > pe){
        
        op1 = (fatorial(ene));
        op2 = (fatorial((ene - pe)));
        op3 = (fatorial(pe));
        unsigned long long int conta = ((op1)/(op2*op3));
        
        
        return conta;
        
    }
    else if(pe==1){
        comb = ene;
        return comb;
    }
    else{
        comb = 0;
        
        return 0;
    }
}

unsigned long long int fatorial(int numb){
    
    if(numb==1){
        return numb;
    }
    else{
        

        return (numb * (fatorial(numb-1)));
    }
    

}
void esvaziatable(int n, int m){
    for(int i = 0; i<n; i++){
        for (int j = 0; j <=(m-1) ; j++)
        {
            tabela[i][j] = 0;
            
        }
        
    }
    for (int i = 0; i <n; i++){
        free(tabela[i]);
    }
    free(tabela);
    
}