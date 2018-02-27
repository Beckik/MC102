#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ra, telefone;
    char nome[100];
} Aluno;

typedef struct {
    int armazenado;
    int capacidade;
    Aluno *alunos;
} Base;

/* Funcao: criar_base
 *
 * Inicializa a base ja com a capacidade.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   n: quantidade maxima de alunos
 */
void criar_base(Base *base, int n) {
    printf ("Base criada.\n");
	base->alunos = malloc (n*sizeof(Aluno));
	base->capacidade = n;
	base->armazenado = 0;
}

/* Funcao: buscar
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *
 * Retorno:
 *   Indice do registro com RA no vetor de alunos
 *   -1 caso contrario.
 */
int buscar(Base *base, int ra) {
    int i = 0;
    for (i = 0; i < (base->armazenado); ++i) {
        if ((base->alunos[i].ra) == ra) {
            return i;
        }
    }
    return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {
    int i = buscar (base, ra);
    if (i == -1) {
        printf("Aluno %d nao encontrado.\n", ra);
    }
    else {
        printf("%d - %d - %s\n", ra, base->alunos[i].telefone, base->alunos[i].nome);
    }
}

/* Funcoes: adicionar
 *
 * Inclui um registro sem permitir RAs duplicados.
 * O quantidade de alunos deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *   telefone: numero do telefone
 *   nome: string com o nome
 */
void adicionar(Base *base, int ra, int telefone, char *nome) {
    int posicao;
	posicao = buscar (base, ra);
  	if (posicao != -1) {
  		strcpy(base->alunos[posicao].nome, nome);
  		base->alunos[posicao].telefone = telefone;
  		printf ("Alterado: %d - %d - %s\n", ra, base->alunos[posicao].telefone, base->alunos[posicao].nome);
  	}
  	else {
        if (base->capacidade == base->armazenado) {
            printf("Erro: base cheia.\n");
            return;
        }
        ++(base->armazenado);
        base->alunos[base->armazenado-1].telefone = telefone;
        base->alunos[base->armazenado-1].ra = ra;
        strcpy (base->alunos[base->armazenado-1].nome, nome);
        printf ("Adicionado: %d - %d - %s\n", ra, base->alunos[base->armazenado-1].telefone, base->alunos[base->armazenado-1].nome);
  	}
}

/* Funcoes: remover
 *
 * Remove um registro se o ra estiver presente.
 * O quantidade de registro deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void remover(Base *base, int ra) {
    int posicao;
    posicao = buscar(base, ra);
    if (posicao == -1) {
    printf("Aluno %d nao encontrado.\n", ra);
    return;
    }
    else {
        base->alunos[posicao] = base->alunos[base->armazenado-1];
        --(base->armazenado);
        printf("Aluno %d removido.\n", ra);
    }
}

/* Funcao: liberar_base
 *
 * Libera a memoria de todos alunos da base.
 * Deve deixar a base com capacidade e quantidade armazenada igual a zero
 * e o ponteiro para alunos igual a NULL.
 *
 * Parametros:
 *   base: ponteiro para a base
 */
void liberar_base(Base *base) {
	base->armazenado = 0;
	base->capacidade = 0;
	free(base->alunos);
    base->alunos = NULL;
}