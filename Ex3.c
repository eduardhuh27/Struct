#include <stdio.h>
#include <string.h>

typedef struct funcio {
    char nome[30];
    char genero;
    int matricula;
    float salario;
}funcio;

void organizar (funcio dados[], char genero);
void preencher (funcio dados[]);
void exibir (funcio dados[]);

void main ()
{
    char gen;
    funcio dados[3];
    printf("Entre com o genero para organizar:");
    scanf(" %c",&gen);
    preencher (dados);
    organizar(dados,gen);
    
}

void preencher (funcio dados[])
{
    int i;
    
    for (i=0;i<3;i++)
    {   
        printf("Nome:");
        scanf("%s",&dados[i].nome);
        printf("Genero (M ou F):");
        scanf(" %c",&dados[i].genero);
        printf("Matricula:");
        scanf("%d", &dados[i].matricula);
        printf("Salario:");
        scanf("%f",&dados[i].salario);
    }
    exibir (dados);
}

void organizar (funcio dados[], char genero)
{
    int i,j;
    funcio temp;
    for(i=0,j=2;i<j;i++,j--)
    { 
        while (i < j && dados[i].genero == genero) {
            i++;
        }

        
        while (i < j && dados[j].genero != genero) {
            j--;
        }

        
        if (i < j)
        {
                   temp=dados[i]; 
                   
                   printf("\n");
                   dados[i]=dados[j];
                   exibir (dados);
                   printf("\n");
                   dados[j]=temp; 
                    exibir (dados);
                    printf("\n");
                }
    }
        
    exibir (dados);
}
void exibir (funcio dados[])
{
    int i;
    for (i=0;i<3;i++)
    {
        printf("Nome:%s\n",dados[i].nome);
        printf("Genero:%c\n",dados[i].genero);
        printf("Matricula:%d\n",dados[i].matricula);
        printf("Salario:%.1f\n",dados[i].salario);
        printf("\n");
    }
}
