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
void preencherIntervalo(Tdata d);

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
    intervalo(grupo,TData d1,Tdata d2);
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

void intervalo(TPessoas grupo[],TData d1,Tdata d2)
{
    int i;
    preencherIntervalo(d1);
    preencherIntervalo(d2);
    for(i=0;i<3;i++)
    {
        if(grupo[i].aniversario.mes>d1.mes && grupo[i]<d2.mes)
        {
            printf("Nome: %s\n",grupo[i].nome);
        }
        if(grupo[i].aniversario.mes==d1.mes || grupo[i].aniversario.mes==d2.mes)
        {
            if((grupo[i].aniversario.dia=>d1.dia) && (grupo[i].aniversario.dia<=d2.dia))
                {
                    printf("Nome: %s\n",grupo[i].nome);
                }
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
void preencherIntervalo(Tdata d)
{
    
    printf("Escolha um mes:");
    scanf("%d",d.mes);
    printf("Entre com o dia:");
    scanf("%d ",d.dia);

}
