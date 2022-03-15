#include <stdio.h>
#include <ctype.h>

int main(){
	int firsttime = 0;
    int alice = 5;
    int beto = 5;
    int clara = 5;
	while(1){
		if(scanf("%d %d %d", &alice, &beto, &clara)!=3){
			break;
		}
		else{

		
            if((alice!=beto) && (alice!=clara)){
                printf("A\n");
            }
            else if((beto!=alice) && (beto!=clara)){
                printf("B\n");
            }
            else if((clara!=alice) && (clara!=beto)){
                printf("C\n");
            }
            else{
                printf("*\n");
            }
        }
	}
	return 0;
}