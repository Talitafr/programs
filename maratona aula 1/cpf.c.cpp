#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//Lembra do atoi e do isdigit, por favor. 
//Ja adicionei suas respectivas bibliotecas.
int main(){
	char cpf[15];	
	while(fgets(cpf,15,stdin)!=-1){
		int intermediate = 0;
		int n = 1;
		int j = 9;
		int somab1,somab2 = 0;   
		
		printf("aaa");
		for(int i = 0; i<=11; i++){
			if(isdigit(cpf[i])){
				intermediate = (cpf[i] - '0');
				somab1= somab1 + (intermediate*n);
				somab2= somab2 + (intermediate*j);
				n++;
				j--;
			}
		}
		int b1comp = somab1 % 11;
		int b2comp = somab2 % 11;
		printf("%d e %d", b1comp, b2comp);
		int b1 = (cpf[12] - '0');
		int b2 = (cpf[13] - '0');
		printf(" %s",cpf); 
		if((b1comp ==b1) && (b2comp==b2)){
			printf("CPF valido");
		}
		else{
			printf("CPF invalido %d e e %d b1comp\n", b1,b1comp);
		}
		
		printf(" %s a",cpf); 
	
		
	}
	return 0;
	

}