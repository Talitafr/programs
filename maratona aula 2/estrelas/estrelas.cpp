#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
int pulando(int);

int main(){
    int n = -1;
    int soma = 0;
    int estrelas = -1;
    while (scanf("%d",&n)){
        
        estrelas = pulando(n);
        printf("%d\n", estrelas);
        
    }
    return 0;
    
}

int pulando(int n){
    int array[n];
    int k = 0;
    int somastars = 0;
    bool tem_vazio = false; //indica se foi preenchido, o que indica se tem estrela ou nao 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[j] = 0;
        }
        while (true)
        {
            
            if(array[k]==1){
                break;
            }   
            else{
                
                array[k]=1;
            }
            if((((k+i)%n) - k) <(n-1)){
                 k = (k+i)%n;
              }
            else{
                break;
              }
        }
        for (int j = 0; j < n; j++)
        {
            if (array[j]==0)
            {
               
                tem_vazio = true;
                break;
            }
               
        }

        if (tem_vazio == false)
        {
            somastars++;
        }
        
        tem_vazio = false;
    }
    return somastars;
}