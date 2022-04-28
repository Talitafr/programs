#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
int **T = NULL; // linha
char **s = NULL;
int test = -1;
void pulando(int, int);
int SCM(int, int);
int testdeagora = -1;


int main() {
    
	int l = -1; 
	int c = -1; 
	scanf("%d", &test);
	for(int k = 1; k<= test; k++){
		testdeagora = k;
		scanf("%d %d", &l,&c);
		T = (int **) calloc(l+1, sizeof(int *));
		for(int i = 0; i<=c; i++){
			T[i] = (int *) calloc(c+1, sizeof(int));
		}
		
			pulando(l,c);
			
			
	    for(int i = 0; i<c; i++){
			free(T[i]);
		}
		free(T);
	}
	return 0;
}

void pulando(int l, int c){
    
    int xinicial[2] = {0,0}; int yinicial[2] = {0,0}; 
    char mapa[l][c];
    for(int i = 0; i<l; i++){
		scanf("%s", mapa[i]);
		
	}
	int npulos[2] = {0,0};
	//npulos[0] é o primeiro caso de teste e o segundo é npulos[1]
    
    
    int n = 0;
	int mediario = 0;
	s = (char **) calloc(2,sizeof(char *));
	while(n<2){
		scanf("%d %d %d", &mediario, &xinicial[n], &yinicial[n]);
		xinicial[n] = xinicial[n] - 1;
		yinicial[n] = yinicial[n] - 1;
		npulos[n] = mediario;
		
    	
			char caminho[npulos[n]];
			if(npulos[n] == 0){
				
				
				
				s[n] = (char *) calloc(1,sizeof(char));
				
			}
			else{
				scanf("%s", caminho);
				s[n] = (char *) calloc((npulos[n]),sizeof(char));
			}

				
			
			
		   	s[n][0] = mapa[xinicial[n]][yinicial[n]];
			
			for(int i = 0; i<npulos[n]; i++){

				switch (caminho[i])
				{
				case 'N':
					xinicial[n] = xinicial[n] - 1;
					s[n][i] = mapa[xinicial[n]][yinicial[n]];
					break;

				case 'S':
					xinicial[n] = xinicial[n] + 1;
					s[n][i] = mapa[xinicial[n]][yinicial[n]];
					
					break;

				case 'W':
					yinicial[n] = yinicial[n] - 1;
					s[n][i] = mapa[xinicial[n]][yinicial[n]];
					break;

				case 'E':
					yinicial[n] = yinicial[n] + 1;
					s[n][i] = mapa[xinicial[n]][yinicial[n]];
					break;

				
					
					
					
			}
				
			}
			n++;
		



	}
	
	int valor = SCM(npulos[0],npulos[1]);
	int sub1 = 0; int sub2 = 0;
	
	sub1 = npulos[0] - valor;
	sub2 = npulos[1] - valor;
	printf("Case %d: %d %d\n", testdeagora, sub1, sub2);
	
	for(int i = 0; i<2; i++){
			
			
			free(s[i]);
			

	}
	free(s);
	
}

int SCM(int l, int c){
		
	
	
	for(int i = 1; i<= l; i++){
		for(int j = 1; j<= c; j++){
			if(s[0][i] == s[1][j]){
				
				T[i][j] = T[i-1][j-1] + 1;
			}
			else{
				T[i][j] = std::max(T[i - 1][j], T[i][j-1]);
			}
			
		}
	}
	return T[l][c];
}
