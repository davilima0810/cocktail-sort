#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define TAM 10

int cocktailS(int *v, int tam);
void troca(int *x, int *y);

int main(){
	int valor;
	FILE *fp = fopen("C:/Users/Davi Lima/Desktop/vetor10(1).txt","r");

	clock_t tempo;
	int i, j = TAM,//contadores
		vetor[TAM];
	int trocas; //numero de trocas
		

//CASOS DE TESTE SEM ARQUIVO
//--------------------------------------------------------------------------		
	/*for(i = 0; i < TAM; i++){//PIOR CASO: oredem decrescente
        vetor[i] = j;
        j--;
    }*/

    /*for(i = 0; i < TAM; i++){//MELHOR CASO: orem crescente
       vetor[i] = i;
    }*/
//--------------------------------------------------------------------------


//CASOS COM ARQUIVO
    i = 0;
    while((fscanf(fp,"%d\n",&valor)) != EOF){ //colocar os numeros do arquivo dentro de um vetor
        vetor[i] = valor;
        i++;
    }


	tempo = clock();
	trocas = cocktailS(vetor, TAM);
	tempo = clock() - tempo;

	printf("Ordenado = ");
	for(i = 0; i < TAM; i++){
		printf("%d ", vetor[i]);
	}
	printf("\nTempo de processamento %f s", ((float)tempo)/CLOCKS_PER_SEC/1000);
	printf("\nNumero de trocas = %d", trocas);
	return 0;
}

void troca(int *x, int *y){
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

int cocktailS(int *v, int tam){
	bool trocou;
	int nTrocas = 0;
	int i;
	int inicio =0;
	int final = tam - 1;

	while(trocou){
		trocou = false;

		for(i = inicio; i < final; ++i){
			if(v[i] > v[i+1]){
				troca(&v[i],&v[i+1]);
				trocou = true;
			}
			if(trocou)
				nTrocas++;
		}

		if(!trocou)
			break;

		trocou = false;
		--final;

		for(i = final - 1; i >= inicio; --i){
			if(v[i] > v[i+1]){
				troca(&v[i],&v[i+1]);
				trocou = true;
			}
			if(trocou)
				nTrocas++;
		}
		++inicio;
	}
	return nTrocas;
}
