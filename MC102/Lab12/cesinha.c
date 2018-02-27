#include <stdio.h>
#include <string.h>
char txt[1100];
int apagar(char vez[]){
	char* p;
	int i, len;
	p = strcasestr(txt , vez);
	len = strlen(vez);

	if(p == NULL)
	{
		return 0;
	}

	while(p != NULL){

		if(p == NULL)
		{
			return 0;
		}

		while (p!=NULL && p != txt && p[-1]!=' ' && p[len] != ' ' && p[len] != '\0' && p[len] != '\n')
		{
			p = strcasestr(p+1, vez);
		}	

		if( p==NULL)
		if(p[len] != ' '  && (p[len]!='\n' || p[len]!='\0'))
		{
			return 0;
		}

		for (i = 0; i < 1003; ++i){
			p[i] = p[len + 1 + i];
		}

		p = strcasestr(txt , vez);
		len = strlen(vez);

		p = strcasestr(txt , vez);
		if ( p != NULL){
			for (i = 0; i < 1003; ++i){
				p[i] = p[len + 1 + i];
			}
		}

		p = strcasestr(txt , vez);
		if ( p != NULL)
		{
			for (i = 0; i < 1003; ++i)
			{
				p[i] = p[len + 1 + i];
			}
		}
	}
	printf("%s\n", txt);
	return 1;
}
int inverter (char vez[]){
	int len;
	char* p;
	char aux;
	p = strcasestr (txt , vez);
	len = strlen(vez);
	if(p==NULL)
		return 0;

	for (int i = 0; i < len; ++i)
	{
		if (i >= len - i -1)
		{
			break;
		}
		aux = p[i];
		p[i] = p[len - i -1];
		p[len - i -1] = aux;
	}
	printf("%s\n", txt);
	return 1;
}
int substituir (char velho[], char novo[]){
	char* p, aux;
	int len, i;
	char copia[1100];
	p = strcasestr (txt , velho);
	len = strlen(velho);
	if(p == NULL)
		return 0;
	strcpy (copia , p + len );
	p = strcasestr (txt , velho);
	sprintf(p, "%s", novo);
	p += strlen(novo);
	strcpy(p, copia);
	printf("%s\n", txt);
	return 1;
}
int main(){
	char id, vez[104], velho[104], novo [104];
	int len;
	fgets(txt, 1000, stdin);
	printf("%s", txt);
	len = strlen (txt);
	txt[len-1] = '\0';
	do{
		scanf("%c", &id);
		if ( id == 'D'){
			scanf("%s", vez);
			while(apagar(vez));
		}
		else if (id =='I'){
			scanf("%s", vez);
			while(inverter(vez));	
		}
		else if (id =='R'){
			scanf("%s", velho);
			scanf("%s", novo);
			while(substituir (velho, novo));		
		}
	}while(id!='Q');
	return 0;
}
