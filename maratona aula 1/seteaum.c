#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
    long int minutos = -5;
    long int golale = -5;
    long int golbra = -5;
	while(1){
        scanf("%ld",&minutos);
		if(minutos==0){
			break;
		}
		else{
			
		
        minutos = minutos - 90;
        golbra = 1 + floor((minutos/90.0));
        golale = 7 + ceil(minutos/12.86);



        printf("Brasil %ld x Alemanha %ld",golbra,golale);
		printf("\n");
        
		}

	}
	return 0;
}