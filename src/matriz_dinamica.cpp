#include <bits/stdc++.h>


/* inicializa uma matriz dinamicamente com o numero de linha e colunas passada por parametro,
OBS: a função retorna um ponteiro para um tipo indefinito necessitando dar um cast antes de atribuir o retorno da função na variavel local

Exemplo: 
		int **variavel_local;

	variavel_local = (int**) matrizd_inicializar( 4 , 5);

	variavel_local[0][0] = 7;

*/

void** matrizd_inicializar(int n_linha, int n_coluna){
	
	void** matriz;

	matriz = (void**) malloc( n_linha * sizeof(void*));

	for(int i=0; i<n_linha; i++){
		matriz[i] = (void*) malloc( n_coluna * sizeof(void*));
	}


	return matriz;
} 



/* Essa função realoca a matriz, ou seja aumenta o tamanho dela sem perder os valores já inserido. 
OBS: essa função recebe e retorna um tipo de ponteiro indefinido, e nescessario dar um cast no parametro passado para ela e no retorno da função. 
	
	Tratamento de ERRO:
Se a função retornar NULL, significa que um dos valores passados em n_linha ou n_coluna são menores que o tamanho atual da matriz, 
Isso pode ocasionar perda de dados.
Ou seja você esta tentando diminuir a matriz e para isso existe as funções de liberar.

Exemplo:
		int **variavel_local;

	variavel_local = (int**) matrizd_inicializar( 4 , 5);
	
	if(matrizd_realocar( ((void**) variavel_local) , 5 , 6) == NULL ){
		printf("Erro ao realocar a matriz");
	}
	else{
		variavel_local = (int**) matrizd_realocar( ((void**) variavel_local) , 5 , 6);
	}			
*/


void** matrizd_realocar(void** matriz, int n_linha, int n_coluna){
	
	int min_linha = sizeof(matriz) / sizeof(void**);
	int min_coluna = sizeof(matriz[0]) / sizeof(void*);

	if(n_linha < min_linha || n_coluna < min_coluna ){
		return NULL;
	}
	else{
		matriz = (void**) realloc(matriz, n_linha*sizeof(void*));

		for(int i=0; i<n_linha; i++){
			matriz[i] = (void**) realloc(matriz[i], n_coluna*sizeof(void**));
		}
	}	

	return matriz;
}

/*Essa função desfaz a matriz liberando o espaço de memória ocupado

Exemplo:

	int **variavel_local;

	variavel_local = (int**) matrizd_inicializar( 4 , 5);

	liberar_matriz( (void**) variavel_local)
*/
void liberar_matriz(void** matriz, int n_linha){
	
	for(int i=0; i<n_linha; i++){
		free(matriz[i]);
	}
	free(matriz);
}

/*Essa função elimina uma linha exclusiva de sua matriz
	
Exemplo:
	
	int **variavel_local;

	variavel_local = (int**) matrizd_inicializar( 4 , 5);

	variavel_local = (int**) liberar_linha(((void**) variavel_local), 3);
*/
void** liberar_linha(void** matriz, int linha){
	free(matriz[linha]);

	return matriz;
}

/* Essa função elimina uma coluna exclusiva de sua matriz. 

Exemplo:
	
	int **variavel_local;

	variavel_local = (int**) matrizd_inicializar( 4 , 5);

	variavel_local = (int**) liberar_coluna(((void**) variavel_local), 4);
*/
void** liberar_coluna(void** matriz, int coluna){

	int numero_linhas = sizeof(matriz) / sizeof(void**);

	for(int i=0; i<numero_linhas; i++){
			matriz[i] = (void**) realloc(matriz[i], coluna*sizeof(void**));
		}
}
