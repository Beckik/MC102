#include <stdio.h>
#include <stdlib.h>
// Vicenzo Cano Cesconetto
// 206456
/*
void ordena(int *conj, int tam);


Esta funcao deve ordenar um conjunto dado como parametro.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;

*/

void ordena(int *conj, int tam) {
	int aux = 0;
	for (int j = tam-1; j > 0; --j) {
		for (int i = 0; i < j; ++i) {
			if (conj[i] > conj[i+1]) {
				aux = conj[i];
				conj[i] = conj[i+1];
				conj[i+1] = aux;
			}
		}
	}
}

/*
int pertence(int *conj, int tam, int elemento);


Esta funcao deve verificar se um elemento esta presente no conjunto.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;
- elemento -> Elemento no qual deve ser ser verificado se esta presente no conjunto;

Retorno

- 1 Caso o elemento PERTENCA conjunto;
- 0 Caso o elemento NAO PERTENCA ao conjunto;

*/
int pertence(int *conj, int tam, int elemento) {
	for (int i = 0; i < tam; ++i) {
		if (conj[i] == elemento) {
			return 1;
		}
	}
  return 0;
}

/*
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);


Esta funcao deve verificar se o conjunto A esta contido no conjunto B.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;

Retorno

- 1 Caso o conjunto A ESTEJA CONTIDO no conjunto B;
- 0 Caso o conjunto A NAO ESTEJA CONTIDO no conjunto B;

*/

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {
	int cont = 0;
	for (int i = 0; i < tam_A; ++i) {
		for (int j = 0; j < tam_B; ++j) {
			if (conj_A[i] == conj_B[j]) {
				++cont;
			}
		}
	}
	if (tam_A == cont) {
		return 1;
	}
  return 0;
}

/*
            
int* init(int *tam, int *cap);


Esta funcao deve inicializar um vetor(conjunto).

Parametros:
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;

OBS:
- A capacidade inicial do vetor(conjunto) deve ser 2.
- O quantidade inicial de elementos no vetor(conjunto) deve ser zero.
- Nao confundir capacidade com quantidade de elementos.

Retorno

- Ponteiro para o conjunto;

            
*/

int* init(int *tam, int *cap) {
	int *conj;
	*tam = 0;
	*cap = 2;
	conj = malloc(2 * sizeof(int));
  return conj;
}

/*
            
int* adicao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve adicionar um novo elemento no conjunto, ou seja, se o elemento ja pertence ao 
conjunto o mesmo NAO deve ser adicionado.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser adicionado;

OBS:
- Ao adicionar um novo elemento o tamanho atual do conjunto devera ser atualizado;
- Caso o ponteiro para o conjunto seja NULL, o conjunto devera ser alocado com uma capacidade de dois (02) 
e a atualizacao da capacidade deverar ser feita;
- Caso a quantidade de elementos do conjunto seja igual a capacidade do conjunto e um novo elemento tenha que 
ser inserido, então o conjunto tera de ser realocado com o dobro da capacidade e a capcidade do conjunto 
devera ser atualizada;

Retorno

- Ponteiro para o conjunto;

            
*/

int* adicao(int *conj, int *tam, int *cap, int elemento) {
	if (conj == NULL) {
		conj = init (tam, cap);
	}
	for (int i = 0; i < *tam; ++i) {
		if (conj[i] == elemento) {
			return conj;
		}
	}
	if (*tam == *cap) {
		conj = realloc (conj, (2*(*cap))*sizeof(int));
        *cap = 2*(*tam);
	}
    ++(*tam);
    conj[*tam-1] = elemento;
    return conj;
}

/*
            
int* subtracao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve remover um elemento no conjunto caso ele exista.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser removido;

OBS:
- Ao remover um elemento o tamanho atual do conjunto devera ser atualizado;
- Caso a capacidade seja maior que dois (02) e a quantidade de elementos do conjunto seja menor ou igual que 1/4 da capacidade do conjunto, então 
o conjunto tera de ser realocado com a metade da capacidade e a capacidade do conjunto devera ser atualizada.

Retorno

- Ponteiro para o conjunto;

            
*/

int* subtracao(int *conj, int *tam, int *cap, int elemento) {
	int flag = 0, i;
	for (i = 0; i < *tam; ++i) {
		if (conj[i] == elemento) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		return conj;
	}
	for (;i < *tam-1; ++i) {
		conj[i] = conj[i+1];
	}
    --(*tam);
	if (*tam <= (*cap)/4 && (*cap)/2 >= 2) {
		conj = realloc (conj, ((*cap)/2)*sizeof(int));
		*cap = (*cap)/2;
	}
  return conj;
}

/*
            
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a uniao entre os conjuntos A e B. O resultado dessa uniao deve ser armazenado em 
um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

            
*/

int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int *conj_C = NULL;
	conj_C = init (tam_C, cap_C);
	for (int i = 0; i < tam_A; ++i) {
		conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);
	}
	for (int i = 0; i < tam_B; ++i) {
		conj_C = adicao(conj_C, tam_C, cap_C, conj_B[i]);
	}
	ordena(conj_C, *tam_C);
  return conj_C;
}

/*
            
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a intersecao entre os conjuntos A e B. O resultado dessa intersecao deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

            
*/

int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int flag = 0, *conj_C = NULL;
	conj_C = init(tam_C, cap_C);
	for (int i = 0; i < tam_A; ++i) {
		flag = pertence (conj_B, tam_B, conj_A[i]);
		if (flag == 1) {
			conj_C= adicao (conj_C, tam_C, cap_C, conj_A[i]);
		}
	}
  return conj_C;
}

/*
            
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a diferenca entre os conjuntos A e B. O resultado dessa diferenca deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

            
*/

int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int *conj_C = NULL;
	conj_C = init (tam_C, cap_C);
	for (int i = 0; i < tam_A; ++i) {
		conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);
	}
	for (int i = 0; i < tam_B; ++i) {
		conj_C = subtracao(conj_C, tam_C, cap_C, conj_B[i]);
	}
  return conj_C;
}