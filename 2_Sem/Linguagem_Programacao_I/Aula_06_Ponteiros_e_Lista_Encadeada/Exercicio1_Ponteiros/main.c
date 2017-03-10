//inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//vari�veis globais
char dic [][20]={"cat","gato","gato", "cat",
                "dog","cachorro", "perro", "hund",
                "is", "é", "es", "det ar",
                "bad","ruim","malo", "illa",
                 "region", "regiao", "region", "region",
                 "shepherds","pastores", "pastores","herdar",
                 "field", "campo", "campo", "falt",
                 "flock", "rebanho", "rebano", "flock",
                 "night", "noite", "noche", "natt",
                 "angel", "anjo", "angel", "angel",
                 "Lord", "Senhor", "senor", "Lord",
                 "glory", "gloria", "gloria","gloria",
                 "great", "grande", "estupendo", "stor",
                 "fear", "medo", "miedo", "radsla",
                 "God", "Deus", "Dios",  "gud",
                 "good", "bom", "bueno", "bra",
                 "day", "dia", "dia", "dag",
                 "city", "cidade", "ciudad", "stad",
                 "baby", "bebe", "bebe", "bebe" ,
                 "earth", "terra", "Tierra", "jord",
                 "peace", "paz", "paz", "fred",
                 "highest", "mais alto", "lo mas alto", "hogsta",
                 "in", "em", "en", "i",
                 "to", "para", "a", "till",
                 "talk", "falar", "hablar", "talk",
                 "tell", "contar", "contar", "rakna",
                 "dove", "pomba", "paloma", "duva",
                 "girl", "garota", "nina", "flicka",
                 "hear", "ouvir", "oir", "hora",
                 "now", "agora", "ahora", "nu",
                 "wake up", "acordar", "despertarse", "vaknar",
                 "champions", "campeoes", "campeones", "mastare",
                 "dangerous", "perigoso", "peligroso", "farling",
                 "stop", "pare", "detener", "stanna",
                 "","","", ""  };
char frase [50];
char palavra [20];
char *p;

// fun��o que n�o retorna valor
void pega_palavra()
 {
  char *q;
  q=palavra;
  while (*p && *p!=' ')
  {
      *q=*p;
      p++;
      q++;
  }
  if (*p==' ')p++;
  *q='\0';
 }

//fun��o retorna o n�mero da linha da palavra
 int traducao (int c)
 {
     int i;
     for(i=0;*dic[i];i=i+4)
     {
        if(strcmp(dic[i],palavra)==0) break;
     }
    if(*dic[i]) return (i+c);
    else return (-1);
 }



// fun��o principal, n�o pode faltar.
int main()
{
    setlocale(LC_ALL, "Portuguese");
    char opcao='s';
    int linha, op;

    while(opcao=='s')
    {
        printf("\nDigite a frase desejada(Em ingles):");
        fflush(stdin);
        gets(frase);
        p=frase;
        pega_palavra();
        printf("\n");

        printf("Escolha o idioma:\n");
        printf("1- Portugues\n");
        printf("2-Espanhol\n");
        printf("3-Sueco\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
            {
                do
                {
                    linha=traducao(1);
                    if(linha!=-1)
                        printf("%s ",dic[linha]);
                    else
                        printf("%s ",palavra);
                    pega_palavra();
                }while(*palavra);
                break;
            }
            case 2:
            {
                do
                {
                    linha=traducao(2);
                    if(linha!=-1)
                        printf("%s ",dic[linha]);
                    else
                        printf("%s ",palavra);
                    pega_palavra();
                }while(*palavra);
                break;
            }
            case 3:
            {
                do
                {
                    linha=traducao(3);
                    if(linha!=-1)
                        printf("%s ",dic[linha]);
                    else
                        printf("%s ",palavra);
                    pega_palavra();
                }while(*palavra);
                break;
            }
            default:
            {
                break;
            }
        }

     printf("\nQuer traduzir outra frase?s/n\n");
     opcao=getche();

    }
    system("pause");
    return 0;
}
