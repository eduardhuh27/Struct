#include <stdio.h>
#include <string.h>

typedef struct historico
{
    int cDisciplina,semestre,ano;
    float media;

}historico;

typedef struct disci
{
    char nome[30];
    int codigo,credito;
}disci;

void exibir (historico aluno[],disci curso[]);
void preencherCurso (disci curso[]);
void preencher (historico aluno[]);
int procurar (historico aluno[],disci curso[],int j);
float media(historico aluno[], disci curso[]);

void main()
{   
    historico aluno[2];
    disci curso[3];
    preencherCurso(curso);
    preencher(aluno);
    exibir (aluno,curso);

}
void preencher (historico aluno[])
{
    int i;
    
    for (i=0;i<2;i++)
    {   
        printf("Informaçoes do aluno.\n");
        printf("Codigo da disciplina:");
        scanf("%d",&aluno[i].cDisciplina);
        printf("Semestre:");
        scanf(" %d",&aluno[i].semestre);
        printf("Ano:");
        scanf("%d", &aluno[i].ano);
        printf("Media:");
        scanf("%f", &aluno[i].media);
        printf("\n");
    }
    
}
void preencherCurso (disci curso[])
{
    int i;
        for (i = 0; i < 3; i++)
        {
            printf("Nome da disciplina:");
            scanf(" %s",curso[i].nome);
            printf("Codigo da disciplina:");
            scanf("%d",&curso[i].codigo);
            printf("Credito da disciplinha:");
            scanf("%d",&curso[i].credito);
            printf("\n");
        }
}
void exibir (historico aluno[],disci curso[])
{
    int i,j,k;
    
    for (i=0,j=0;i<2;i++,j++)
    {  
        k=procurar(aluno,curso,j);
        //printf("%d\n",j);
        printf("Nome: %s",curso[k].nome);
        printf(" Codigo da diciplina: %d",aluno[i].cDisciplina);
        printf("  Media: %.2f\n",aluno[i].media);
    }
    printf("Cr:%.1f",media(aluno,curso));
    printf("\n");
    
}

int procurar (historico aluno[],disci curso[],int j)
{
   // printf("%d\n",j);
    int i;
    for(i=0;i<3;i++)
    {
        //printf("%d\n",aluno[j].cDisciplina);
       // printf("%d\n",curso[i].codigo);
        if(aluno[j].cDisciplina==curso[i].codigo)
        {
            //printf("%d",i);
            return i;
        }
    }
}

float media(historico aluno[], disci curso[])
{
    int i,k,cred,somaCreditos=0;
    float media=0,cr;
        for( i=0;i<2;i++)
        {
            cred=curso[k=procurar(aluno,curso,i)].credito;
            media+=aluno[i].media*cred;
            somaCreditos+=cred;    
        }
        
        cr=(float)media/(somaCreditos);
      //  printf("%d",somaCreditos);
        
    return cr;
    
}