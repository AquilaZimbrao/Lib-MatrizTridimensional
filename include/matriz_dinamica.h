#ifndef MATRIZ_DINAMICA
#define MATRIZ_DINAMICA

void** matrizd_inicializar(int n_linha, int n_coluna);
void** matrizd_realocar(void** matriz, int n_linha, int n_coluna);
void liberar_matriz(void** matriz, int n_linha);
void** liberar_linha(void** matriz, int linha);
void** liberar_coluna(void** matriz, int coluna);

#endif