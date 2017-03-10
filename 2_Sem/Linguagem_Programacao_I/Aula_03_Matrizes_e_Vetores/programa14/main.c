#include <stdio.h>
#include <stdlib.h>

int conta_vogal(char s[])
{
  int i, qtde=0;
  for(i=0;s[i]!='\0';i++)
  {
	  if(tolower(s[i])=="a" || tolower(s[i])=="e" || tolower(s[i])=="i" || tolower(s[i])=="o" || tolower(s[i])=="u") qtde++;
  }
  return qtde;
}

void substitui_vogal(char s[],char c)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(tolower(s[i])=="a" || tolower(s[i])=="e" || tolower(s[i])=="i" || tolower(s[i])=="o" || tolower(s[i])=="u")
		{
			s[i]=c;
		}
	}
	printf("\nApós substituição ficou: %s.\n", s);
}

int main()
{
	char s[20];
    printf("Informe uma frase: !\n");
    gets(s);
    printf("%d vogais na frase.\n", conta_vogal(s))
    printf("Entre com um caracter: !\n");
    scanf("%c", &c);
    substitui_vogal(s, c);
    system("pause");
    return 0;
}
