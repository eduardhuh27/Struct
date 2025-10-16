


#include <stdio.h> 
#include<string.h>

typedef struct Ano
{ int anoF, anoM; 

} ano;

typedef struct Carros
 { float km,valor; 
    char placa[7]; 
    char modelo[30]; 
    char marca[30]; 
    char cor[15]; 
    char tipo[10]; 
    struct Ano fabrica;
 } Carros;

void preencher(Carros catalogo[],int tamanho);
void exibirFiltro (Carros catalogo[],int tamanho,int filtro,int a1, int a2, char modelo[]);
void exibir (Carros catalogo[],int tamanho);
void reajuste (Carros catalogo[],float porcentagem,int tamanho);
void retirar (Carros catalogo[], char vendido[7],int tamanho);
int menu (Carros catalogo[],int tamanho);

void main ()
{
    Carros catalogo[2];

    preencher (catalogo,1);
    menu(catalogo,2);
}
int menu (Carros catalogo[],int tamanho)
{
    int filtro,menu,a1,a2;
    char modelo[20];
    float porcentagem;
    char placa[7];
    do
    {    
        printf("1. Exibir o catalogo.\n");
        printf("2. Filtrar o catalogo.\n");
        printf("3. Reajustar o valor.\n");
        printf("4. Retirar carro.\n");   
        printf("5. Finalizar.\n");
        printf("Escolha a operação:\n");
        fflush(stdin);
        scanf("%d",&menu);
        //Ao tentar finalizar dá erro de Buffer, na primeira tentativa
        //fflush(stdin);
        //printf("\n");
        // if(menu==5)
        // {
        //     return 0;
        // }
        switch (menu)
        {
        case 1:
            exibir(catalogo,tamanho);
            
            break;
    
        case 2:
            printf("Qual o modelo");
            scanf(" %s",&modelo);
            printf("Qual intervalo de anos:");
            scanf("%d %d", &a1,&a2);
            printf("Entre com o filtro de valor:");
            scanf("%d",&filtro);
            
             exibirFiltro(catalogo,tamanho,filtro,a1,a2,modelo);
            
             break;
        
        case 3:
            printf("Porcetagem do reajuste:");
            scanf("%f",&porcentagem);
            reajuste(catalogo,porcentagem/100,tamanho);
          
            break;
        
        case 4:
        
            printf("Entre com a placa:");
            scanf(" %s",placa);
            retirar(catalogo ,placa,tamanho);
          
            break;
        case 5:
            printf("Operação finalizada.");
            break;
        }  
    }while (menu!= 5) ;   
}

   void preencher (Carros catalogo[],int tamanho)
      {
        int i,meno;

        for (i=0;i<tamanho;i++)
        {
            printf("Marca:");
            scanf("%s",&catalogo[i].marca);
            printf("Modelo:");
            scanf(" %s",&catalogo[i].modelo);
            printf("Ano do modelo:");
            scanf("%d",&catalogo[i].fabrica.anoM);
            printf("Ano de fabricação:");
            scanf("%d",&catalogo[i].fabrica.anoF);
            printf("Cor:");
            scanf(" %s",&catalogo[i].cor);
            printf("Placa:");
            scanf(" %s",&catalogo[i].placa);
            printf("Tipo:");
            scanf(" %s",&catalogo[i].tipo);
            if(strcmp(catalogo[i].tipo,"0km")!=0)
            {
                printf("Kilometragem:");
                scanf("%f",&catalogo[i].km);
            }
            else
            {
                catalogo[i].km=0;
            }
            printf("Valor:");
            scanf("%f",&catalogo[i].valor);
        }
        printf("Ir para o menu(1):");
        scanf("%d",&meno);
        if(meno==1) {menu(catalogo,tamanho);}
}

void exibir (Carros catalogo[],int tamanho)
{
    int i,meno;
    for (i=0; i<tamanho; i++)
    {
           
        
            printf("Marca: %s\n",catalogo[i].marca);
            printf("Modelo: %s\n",catalogo[i].modelo);
            printf("Ano do modelo: %d\n",catalogo[i].fabrica.anoM);
            printf("Ano de fabricação: %d\n",catalogo[i].fabrica.anoF);
            printf("Cor: %s\n",catalogo[i].cor);
            printf("Placa: %s\n",catalogo[i].placa);
            printf("Tipo: %s\n",catalogo[i].tipo);
            printf("Kilometragem: %.1f\n",catalogo[i].km);
            printf("Valor: %.1f\n",catalogo[i].valor);
        
            
    }
    printf("Voltar para o menu(1):");
        scanf("%d",&meno);
        if(meno==1) {menu(catalogo,tamanho);}
}
void exibirFiltro (Carros catalogo[],int tamanho,int filtro, int a1,int a2, char modelo[])
{
    int i,meno;
    for(i=0; i<tamanho ;i++)
    {
        if(strcmp(catalogo[i].modelo,modelo)==0)
        {
            if( (catalogo[i].fabrica.af>a1) && (catalgo[i].fabrica.af<a2))
            {
                if(filtro>=catalogo[i].valor)
                    {
                        exibir(catalogo[i],1);       
                    }
            }   
        }    
    }
        
    
}


void reajuste (Carros catalogo[],float porcentagem,int tamanho)
{
    int i,meno;
    for(i=0;i<tamanho;i++)
    {
        if(catalogo[i].km==0)
        {catalogo[i].valor=catalogo[i].valor+(porcentagem*catalogo[i].valor);
        printf("Novo valor: %.1f\n",catalogo[i].valor);}
    }
    printf("Voltar para o menu(1):");
        scanf("%d",&meno);
        if(meno==1) {menu(catalogo, tamanho);}
}

void retirar (Carros catalogo[], char vendido[7],int tamanho)
{
    int i,meno;

    for (i=0;i<tamanho;i++)
    {
        if (strcmp(catalogo[i].placa,vendido)==0)
        {
            catalogo[i]=catalogo[i+1];
            tamanho--;
        }

    }
    
        exibir(catalogo,tamanho);
    printf("Voltar para o menu(1):");
        scanf("%d",&meno);
        if(meno==1) {menu(catalogo,tamanho);}
        
}
