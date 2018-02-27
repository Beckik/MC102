#include <stdio.h>
#include <string.h>
/* Vicenzo Cano Cesconetto RA: 206456 */
// Esse é o protótipo por que, por alguma razão, a Susy, o testador e o Sublime reclamam do uso do strcasecmp.
// Eles reclamam dizendo que houve declaração implícita de função, mas a funçao está na biblioteca string.
// O objetivo do código é ler uma entrada com até mil caracteres e identificar palavras específicas e printar
// comandos secretos que elas representam.
/* Como o código funciona? Ele le char por char e identifica os espaços e o newline por que é o fim da entrada.
Ele vai incrementando uma contadora para não haver sobreposição de letras. Isso tudo ocorre dentro do do-while 
que dentro dele tem um outro do while que le os char até quebrar o loop por fim da palavra ou da entrada.
Quando sair do loop interno, ele testará para ver de o que foi lido é alguma das palavras chave.
*/
int strcasecmp(char *c, char *v);

int main() {
	char txt[1000];
	char loop = 1;
	int i;
	// Loop é a flag de controle do loop.
	// Aqui temos um do-while ao invés de for por causa de estilo, e ele lerá as entradas.
	do
	{
		/* Toda vez será zerado o i.
		*/
		i = 0;
		// Temos outro do while para ler cada caracter da entrada enquanto for diferente de newline e espaço vazio.
		// Além disso, o i é incrementado para não sobreescevermos as letras.
		do {
			scanf("%c", &txt[i++]);
		}
		while (txt[i-1] != '\n' && txt[i-1]!=' ');
		// Se a posição que acabou de ser lida for new line quer dizer que lemos o fim da entrada.
		if(txt[i-1] == '\n') {
			loop = 0;
		}
		/* Para dar fim a string colocamos o caracter especial \0.*/
		txt[i-1] = '\0';
		// Para ser case insensitive usamos a funçao de comparação que ignora se é upper ou lower case.
		/* Se o vetor for algo que procuramos, ele printa o que deve ser printado */
		if(strcasecmp(txt, "mercurio") == 0) {
			printf("N");
		}
		if(strcasecmp(txt, "venus") == 0) {
			printf("NE");
		}
		if(strcasecmp(txt, "terra") == 0) {
			printf("L");
		}
		if(strcasecmp(txt, "marte") == 0) {
			printf("SE");
		}
		if(strcasecmp(txt, "jupiter") == 0) {
			printf("S");
		}
		if(strcasecmp(txt, "saturno") == 0) {
			printf("SO");
		}
		if(strcasecmp(txt, "urano") == 0) {
			printf("O");
		}
		if(strcasecmp(txt, "netuno") == 0) {
			printf("NO");
		}
		if(strcasecmp(txt, "verde") == 0) {
			printf(" - 30\n");
		}
		if(strcasecmp(txt, "amarelo") == 0) {
			printf(" - 45\n");
		}
		if(strcasecmp(txt, "vermelho") == 0) {
			printf(" - 60\n");
		}
	} 
	/* Se a flag for zero ele sai do loop, ou seja, o if foi satisfeito*/
	while (loop);
}
