#include <stdio.h>
#include <string.h>

typedef struct info
{
    char nome[30];
    int idade;
    char genero;
}info;

int organizado (info sala[]);
void exibir (info sala[]);
void preencher (info sala[]);

void main() {
    info sala[3];
    int resposta;
    preencher (sala);
    resposta=organizado(sala);
    //exibir (sala);
     if (resposta==1){
     printf("Esta organizado.");
    }
    else
    {
        printf("Não esta organizado.");
    }
}

int organizado (info sala[])
{
 int i;
 info temp;
    for(i=3;i>0;i--)
    {
        if(sala[i].idade<sala[i-1].idade)
        {
           /* temp=sala[i];
            sala[i]=sala[i-1];
            sala[i-1]=temp;
            */
            return 0;
        }
        if(sala[i].idade==sala[i-1].idade)
        {
            if(strcmp(sala[i].nome,sala[i-1].nome)<0)
            {
                /*    temp=sala[i];
                sala[i]=sala[i-1];
                sala[i-1]=temp;*/
                return 0;
            }
        }
    }
    return 1;
}
void preencher (info sala[])
{
    int i;
    
    for (i=0;i<3;i++)
    {   
        printf("Nome:");
        scanf("%s",&sala[i].nome);
        printf("Genero (M ou F):");
        scanf(" %c",&sala[i].genero);
        printf("Idade:");
        scanf("%d", &sala[i].idade);
        printf("\n");
    }
    exibir (sala);
}
void exibir (info sala[])
{
    int i;
    for (i=0;i<3;i++)
    {
        printf("Nome:%s\n",sala[i].nome);
        printf("Genero:%c\n",sala[i].genero);
        printf("Idade:%d\n",sala[i].idade);
        printf("\n");
    }
}
