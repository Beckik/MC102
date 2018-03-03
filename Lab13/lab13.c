/* Laboratorio 15 - Conjuntos
   Nome: Vicenzo Cano Cesconetto
   RA: 206456
 */
// Esse é o universo, ele será usado para o complemento.
char U[] = "abcdefghijklmnopqrstuvwxyz";
#include <stdio.h>
// A função pertence olha todo o conj com um for e se achar retorna 1, caso contrário, 0.
int pertence(char conj[], int tam, char letra){
  for (int i = 0; i < tam; ++i){
    if (conj[i] == letra){
      return 1;
    }
  }
  return 0;
}
// A função contido olha todo o vetor 2 procurando o 1 nele, 
// e a contadora é incrementada toda vez que umas das letras de 1 é encontrada em 2
// e retornando 1 se estiver contido, caso contrário, 0
int contido(char conj1[], char conj2[], int tam1, int tam2){
  int c = 0;
  for (int i = 0; i < tam1 ; ++i){
    for (int j = 0; j < tam2; ++j){
      if (conj1[i] == conj2[j]){
        ++c;
      }
    }
  }
  if ( c == tam1){
    return 1;
  }
  return 0;
}
// A função adição coloca letra no final do vetor se ela já não estiver no conjunto
// e aumenta o tamanho do vetor retornando o o tamanho atual.
int adicao(char conj[], int tam, char letra){
  for (int i = 0; i < tam; ++i){
    if (letra == conj[i]){
      return tam;
    }
  }
  conj[tam] = letra;
  ++tam;
  return tam;
}
// Subtração pega posição em que estiver letra a ser subtraída se ela existir no conjunto
// e coloca a ultima letra no lugar dela, e diminui o tamanho do vetor e retorna o tamanho atual.
int subtracao(char conj[], int tam, char letra) {
  for (int i = 0; i < tam; ++i){
    if (conj[i] == letra){
      conj[i] = conj[tam-1];
      --tam;
      break;
    }
  }
  return tam;
}
// A união coloca em destRes todo conjunto um e vai colocando em destRes o que estiver
// no conjunto 2 por meio da função adição, que checa se o que vai ser acrescentado já está
// incluso no conjunto.
int uniao(char destRes[], char conj1[], char conj2[], int tam1, int tam2) {
  int f = tam1;
  for (int i = 0; i < tam1; ++i){
    destRes[i] = conj1[i];
  }
  for (int i = 0; i < tam2; ++i){
  f = adicao(destRes, f, conj2[i]);
  }
  return f;
}
// Interseção vai percorrendo o conj 1 comparando com o 2 e incrementado v de acordo com a quantidade
// de letras na interseção. Ao final, ele retorna v que é o tamanho da string que contém as letras 
// da interseçao.
int intersecao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
  int v = 0;
  for (int i = 0; i < tam1 ; ++i){
    for (int j = 0; j < tam2; ++j){
      if (conj2[j] == conj1[i]){
        destRes[v] = conj2[j];
        ++v;
      }
    }
  }
  return v;
}
// A diferença coloca conj1 em destRes e tira de destRes, o que tem em 2 se estiver em destRes.
// C é retornado sendo o tamanho de destRes.
int diferenca(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
  int c = tam1;
  for (int i = 0; i < tam1; ++i){
    destRes[i] = conj1[i];
  }
  for (int i = 0; i < tam2; ++i){
    c = subtracao (destRes, c, conj2[i]);
  }
  return c;
}
// Complemento usa diferença entre o conj e o universo, retornando c,
// que é o tamanho do complemento.
// c começa como tam mas na iteração de diferença com o universo, tirando conj,
// ele recebe o tamanho final.
int complemento(char conjRes[], char conj[], int tam){
  int c = tam;
  c = diferenca(conjRes, U, conj, 26, tam);
  return c;
}