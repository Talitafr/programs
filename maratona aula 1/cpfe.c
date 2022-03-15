#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//Lembra do atoi e do isdigit, por favor. 
//Ja adicionei suas respectivas bibliotecas.
int main(){
	int firsttime = 0;
	bool continuar = true;
	while(continuar){
		char cpf[15];
		int intermediario = 0;
		int ondemcres = 1;
		int ordemdecres = 9;
		int somab1 = 0;
		int somab2 = 0;   
		if(scanf("%15s",cpf)!=1){
			break;
		}
		else{
			for(int i = 0; i<=10; i++){
				if(isdigit(cpf[i])){
					intermediario = (cpf[i] - '0');
					somab1= somab1 + (intermediario*ondemcres);
					somab2= somab2 + (intermediario*ordemdecres);
					ondemcres++;
					ordemdecres--;
				}
			}
			int b1comp = somab1 % 11;
			int b2comp = somab2 % 11;
			if((b1comp == 10) || (b1comp == -10)){
				b1comp = 0;
			} 
			else if((b2comp == 10) || (b2comp == -10)){
				b2comp = 0;
			}
			else if((b1comp == 10) || (b2comp ==10) || (b1comp == -10) || (b2comp ==-10)){
				b1comp = 0;
				b2comp = 0;
			}
			else{

			}
				int b1 = (cpf[12] - '0');
				int b2 = (cpf[13] - '0');
				if((b1comp == b1) && (b2comp == b2)){
					printf("CPF valido\n");
				}
				else{
					printf("CPF invalido\n");
				}
			 

		}
	}
	return 0;
	

}