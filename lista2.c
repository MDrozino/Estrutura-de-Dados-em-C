#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void inserir_inicio();
void inserir_fim();
void entradaDados();

int cont;

typedef struct pessoa{
	char nome[50], cpf[12], rg[10];
}pessoa;

typedef struct aluno{
	char ra[10], curso[50];
}aluno;

typedef struct No{
	int dado;
	struct No *proximo;	
	struct pessoa p;
	struct aluno al;
}No;


void entradaDados(int *valor, pessoa *p1, aluno *alu){
	
	printf("Informe o valor:");
	scanf("%d", valor);
	
	printf("Informe o nome:");
	scanf("%s", p1->nome);
	
	printf("Informe o cpf:");
	scanf("%s", p1->cpf);
	
	printf("Informe o rg:");
	scanf("%s", p1->rg);
	
	printf("Informe o ra:");
	scanf("%s", alu->ra);
	
	printf("Informe o curso:");
	scanf("%s", alu->curso);
	
	printf("\nMemória alocada com sucesso!\n");
	system("pause");
	
}

void inserir_inicio(int dado, pessoa p, aluno al, No **inicio){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Memória insuficiente");
		exit(0);
	}
	else{
		novo->dado = dado;
		
		strcpy(novo->p.nome, p.nome);
        strcpy(novo->p.cpf, p.cpf);
        strcpy(novo->p.rg, p.rg);
        strcpy(novo->al.ra, al.ra);
        strcpy(novo->al.curso, al.curso);
        
        novo->proximo = *inicio;
		*inicio = novo;
		cont+=1;
	}
}
/*
void inserir_meio(int dado, pessoa p, aluno al, No **inicio){
	No *aux, *novo = (No*)malloc(sizeof(No));
	int insercao = cont + 1;
	int contLocal;
	
	if(novo == NULL){
		printf("Alocação de memória falhou...\n");
		exit(0);
	}
	
	printf("Em qual posição você quer inserir o elemento:");
	do{
	scanf("%d", insercao);
	}while(insercao>cont);
	
	novo->dado = dado;
	
	strcpy(novo->p.nome, p.nome);
	strcpy(novo->p.cpf, p.cpf);
	strcpy(novo->p.rg, p.rg);
	strcpy(novo->al.ra, al.ra);
	strcpy(novo->al.curso, al.curso);
	
	novo->proximo = NULL;
	
	
	
}
*/
void inserir_fim(int dado, pessoa p, aluno al, No **inicio){
	No *aux, *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Alocação de memória falhou...\n");
		exit(0);
	}
	
	novo->dado = dado;
	
	strcpy(novo->p.nome, p.nome);
	strcpy(novo->p.cpf, p.cpf);
	strcpy(novo->p.rg, p.rg);
	strcpy(novo->al.ra, al.ra);
	strcpy(novo->al.curso, al.curso);
	
	novo->proximo = NULL;
	
	
	if(*inicio==NULL){
		*inicio = novo;
	}else{
		aux = *inicio;
		
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		
		aux->proximo = novo;
		cont+=1;
	}
}

void imprimir(No *no){
	
	if(no==NULL){
		printf("A lista está vazia...:)\n");
		system("pause");
	}else{
	
	
	printf("Lista:\n");
	
	while(no!=NULL){
		printf("Dado: %d\n", no->dado);
        printf("Nome: %s\n", no->p.nome);
        printf("CPF: %s\n", no->p.cpf);
        printf("RG: %s\n", no->p.rg);
        printf("RA: %s\n", no->al.ra);
        printf("Curso: %s\n", no->al.curso);
        
        printf("\n");
		no = no->proximo;
		
	}
	printf("%d", cont);
	printf("\n");
	system("pause");
	}

}

main(){
	setlocale(LC_ALL, "Portuguese");
	No *no, *inicio = NULL ;
	int escolha, cont = 0;
	int dado;
	pessoa p;
	aluno al;
	
	do{
		system("cls");
		printf("1  -  Inserir no inicio\n2  -  Inserir no fim\n3  -  Inserir no meio\n4  -  Imprimir\n5  -  Sair\n");
		printf("Escolha:");
		scanf("%d", &escolha);
		
		
		switch(escolha){
			case 1:
				entradaDados(&dado, &p, &al);
				inserir_inicio(dado, p, al, &inicio);
				break;
				
			case 2:
				entradaDados(&dado, &p, &al);
				inserir_fim(dado, p, al, &inicio);
				break;
			/*	
			case 3:
				entradaDados(&dado, &p, &al);
				inserir_meio(dado, p, al, &inicio);
				break;
			*/
				
			case 4:
				imprimir(inicio);
				break;
			
			}
		
	}while(escolha!=5);	
	
	No *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
	
	system("pause");
}
