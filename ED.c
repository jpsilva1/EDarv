#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pessoa{
    char  *nome; // lembrar de colocar outro nome+ para ser a esposa ou usar conjugue como aux
    char  *sexo;// m ou f
    struct pessoa *pai; //aponta pra cima
    struct pessoa *mae; // aponta pra cima
    struct pessoa *filho2; // aponta pra baixo
    struct pessoa *filho1; // aponta pra baixo
    struct pessoa *conjuge; // 'aponta pro lado
}pessoa;

typedef struct pessoa no;

// id para o tipo de inclusao 0, 1, 2
int inserir (no *raiz, char *Nome, char *Sexo,int id){
		if(id == 1){
			if(raiz == NULL){
				no* aux =(no*)malloc(sizeof(no));
				aux->nome = (char*) malloc(20*sizeof(char));
				aux->sexo = (char*) malloc(10*sizeof(char));
				strcpy(aux->nome , Nome);
				strcpy(aux->sexo, Sexo);
				aux->pai = NULL;
				aux->mae = NULL;
				aux->conjuge = NULL;
				raiz = aux;
				return 1;
			}else{
				inserir(raiz->filho1,Nome,Sexo,id);}
		}

		if(id == 2){
			if(raiz == NULL){
				no* aux =(no*)malloc(sizeof(no));
				aux->nome = (char*) malloc(20*sizeof(char));
				aux->sexo = (char*) malloc(10*sizeof(char));
				strcpy(aux->nome , Nome);
				strcpy(aux->sexo, Sexo);
				aux->pai = NULL;
				aux->mae = NULL;
				aux->conjuge = NULL;
				raiz = aux;
				return 1;
			}else{
				inserir(raiz->filho2,Nome,Sexo,id);
			}
		}

    return 0;
}

no* buscano (no *raiz,char* nome){
	if (strcmp(raiz->nome,nome) == 0) {
		printf("Encontrou: %s\n\n",nome);
		return raiz;
	}

	while (raiz != NULL){
		buscano(raiz->filho1,nome);
	}

	return NULL;
	printf("Não encontrou");
}

int subMenu (no* raiz){
	int opcao2 = -1;

	printf("Selecione uma das seguintes opções: \n");
	printf("		1 - Associa mãe\n");
	printf("		2 - Associa pai\n");
	printf("		3 - Associa conjuge\n");
	printf("		4 - Associa filho 1\n");
	printf("		5 - Associa filho 2\n");
	scanf("%d",&opcao2);

	switch(opcao2) {
        case 1:{
            //AssociaMae(raiz);
        }break;
        case 2:{
            //AssociaPai(raiz);
        }break;
        case 3:{
           //AssociaConjuge(raiz);
        }break;
        case 4:{
           //AssociaFilho1(raiz);
        }break;
        case 5:{
            //AssociaFilho2(raiz);
        }break;
    }

    return 0;
}

int main(int argc, char *argv[]){

    no *raiz = NULL;

    char  *Nome, *Sexo, *Pai, *Mae,	*Conjuge, *Filho1, *Filho2;
    Nome = (char*) malloc(20*sizeof(char));
    Sexo = (char*) malloc(10*sizeof(char));
    Pai = (char*) malloc(20*sizeof(char));
    Mae = (char*) malloc(20*sizeof(char));
    Conjuge = (char*) malloc(20*sizeof(char));
    Filho1 = (char*) malloc(20*sizeof(char));
    Filho2 = (char*) malloc(20*sizeof(char));
    int id, opcao = -1; // id = numero de no
    id = -1;

    while(opcao != 0) {
	printf("==================== Árvore ====================\n");
	printf("1 - Inserir\n");
	printf("2 - Procura pessoa\n");
	printf("3 - Associar Parentescos \n");
	printf("0 - Sair\n");
	scanf("%d",&opcao);
		switch(opcao) {
			case 1:{
				printf("Digite o Nome \n");
				scanf("%s",Nome);
				printf("Digite Sexo (M/F) \n");
				scanf("%s",Sexo);
				printf("informe id: 1=san ou 2=chan\n");
				scanf("%d",&id);
				Pai = NULL;
				Mae = NULL;
				Conjuge = NULL;
				Filho1 = NULL;
				Filho2 = NULL;
				inserir(raiz,Nome,Sexo,id);
				printf("\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",Nome,Sexo,Mae,Pai,Conjuge,Filho1,Filho2);
			}break;

			case 2:{
				printf("Digite o Nome \n");
				scanf("%s",Nome);
				buscano(raiz,Nome);
			}

			case 3:{
				subMenu(raiz);
			}
		}
    }

    return 0;
}
