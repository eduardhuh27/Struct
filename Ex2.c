#include <stdio.h>

typedef struct TData{
    int dia, mes;
}TData;
typedef struct TPessoas{
    char nome[30];
    struct TData aniversario;
}TPessoas;

int mescomum (TPessoas grupo[],int mes);
void intervalo (TPessoas grupo[],int d1,int d2);
void preencher (TPessoas grupo[]);

void main ()
{
    TPessoas grupo[3];
    int mes,d1,d2,quant;
    
    preencher (grupo);
    
    printf("Escolha um mes:");
    scanf("%d",&mes);
    printf("Entre com o intervalo de dias:");
    scanf("%d %d",&d1,&d2);

    quant=mescomum (grupo, mes);
    intervalo(grupo,d1,d2);
    printf("Quantidade de pessoas que fazem aniversario no mes %d: %d",mes,quant);
}
void preencher (TPessoas grupo[])
{
    int i;
    for (i=0;i<3;i++)
    {
        printf("Nome:");
        scanf("%s",&grupo[i].nome);
        
        printf("Data de aniversario:");
        scanf("%d %d",&grupo[i].aniversario.dia,&grupo[i].aniversario.mes);



    }
}

void intervalo(TPessoas grupo[],int d1,int d2)
{
    int i;
    for(i=0;i<3;i++)
    {
        if((grupo[i].aniversario.dia>d1) && (grupo[i].aniversario.dia<d2))
            {
                printf("Nome: %s\n",grupo[i].nome);
            }
    }
}

int mescomum(TPessoas grupo[],int mes)
{
    int i,cont=0;
    for(i=0;i<3;i++)
    {
       if(grupo[i].aniversario.mes==mes)
       {
        cont++;
       } 
    }

    return cont;

}