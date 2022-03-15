#include <stdio.h>
#include <ctype.h>

int main(){
    
    int base1=0;
    int base2 = 0;
    int altura1 = 0;
    int altura2 = 0;
    int largura1 = 0;
    int largura2 = 0;
	int testes=0;
    int firsttime = 0;
    scanf("%d", &testes);
	for(int i=0; i<testes; i++){
		if(firsttime==0){
			firsttime++;
		}
		else{
			printf("\n");
		}
        scanf("%d %d %d %d %d %d", &base1, &base2, &altura1, &altura2, &largura1, &largura2);
        
        if(((base1> base2)||(base1>altura2)||(base1>largura2))){

            
            if((largura1>altura2)||(largura1>largura2)) || ((altura1> base2)||(altura1>altura2)||(altura1>largura2))){

            }

            }
            //if((largura1> base2)||(largura1>altura2)||(largura1>largura2)){
              //   if((altura1> base2)||(altura1>altura2)||(altura1>largura2)){
                     
                // }
            //}
        }
    
    }
	return 0;
}