#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void inserir_inicio();
void inserir_fim();
void entradaDados();

int cont = 0;

typedef struct pessoa{
	char nome[50], cpf[12], rg[10];
}pessoa;

typedef struct aluno{
	char ra[10], curso[50];
}aluno;

typedef struct No{
	struct No *proximo;	
	struct pessoa p;
	struct aluno al;
}No;


void entradaDados(pessoa *p1, aluno *alu){
	
	printf("\nInforme o nome: ");
	scanf(" %[^\n]", p1->nome);
	
	printf("Informe o cpf: ");
	scanf(" %[^\n]", p1->cpf);
	
	printf("Informe o rg: ");
	scanf(" %[^\n]", p1->rg);
	
	printf("Informe o ra: ");
	scanf(" %[^\n]", alu->ra);
	
	printf("Informe o curso: ");
	scanf(" %[^\n]", alu->curso);
	
	printf("\nMemória alocada com sucesso!\n");
	system("pause");
	
}

void inserir_inicio(pessoa p, aluno al, No **inicio){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Memória insuficiente");
		exit(0);
	}
	else{
		
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

void inserir_meio(pessoa p, aluno al, No **inicio){
	No *aux, *novo = (No*)malloc(sizeof(No));
	int insercao;
	int contLocal = 1;
	
	system("cls");
	printf("Em qual posição você quer inserir o elemento:");
	scanf("%d", &insercao);
	
	while(insercao>cont || insercao<=1 ){
		printf("Posição inválida - informe uma posição entre 2 e %d:", cont);
		scanf("%d", &insercao);
	}
	
	
	if(novo == NULL){
		printf("Alocação de memória falhou...\n");
		exit(0);
	}
	
	strcpy(novo->p.nome, p.nome);
	strcpy(novo->p.cpf, p.cpf);
	strcpy(novo->p.rg, p.rg);
	strcpy(novo->al.ra, al.ra);
	strcpy(novo->al.curso, al.curso);
	
	aux = *inicio;
	
	while(contLocal < insercao-1 ){
		aux = aux->proximo;
		contLocal+=1;
	}
	
	novo->proximo = aux->proximo;
	aux->proximo = novo;
	
	cont+=1;
	
	printf("Memória inserida!\n\n");
	system("pause");
	
}

void inserir_fim(pessoa p, aluno al, No **inicio){
	No *aux, *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Alocação de memória falhou...\n");
		exit(0);
	}
	
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
	int x = 1;
	
	if(no==NULL){
		printf("A lista está vazia...:)\n");
		system("pause");
	}else{
	
	
	printf("                           Lista:\n");
	printf("---------------------------------------------------------------\n\n");
	
	while(no!=NULL){
        printf("Nome:  %s\n", no->p.nome);
        printf("CPF:   %s\n", no->p.cpf);
        printf("RG:    %s              %d - elementoº\n", no->p.rg, x);
        printf("RA:    %s\n", no->al.ra);
        printf("Curso: %s\n", no->al.curso);
        
        printf("\n");
        printf("---------------------------------------------------------------\n\n");
		no = no->proximo;
		x+=1;
		
	}
	
	printf("\n");
	system("pause");
	}

}

void remover(No **inicio){
	int remocao, contLocal;
	No *aux;
	No *temp = NULL;

	
	printf("Informe a posição que deseja remover:");
	scanf("%d", &remocao);
	
	while(remocao<1 || remocao>cont){
		printf("Posição inválida - informe uma posição de 1 a %d: ", cont);
		scanf("%d", &remocao);
	}
	
	if(remocao==1){
		aux=*inicio;
		*inicio = aux->proximo;
		free(aux);
		
		cont-=1;
		printf("Primeiro elemento removido!\n\n");
		system("pause");
		
		
	} else if(remocao == cont){
		aux = *inicio;
		
		
		while(aux->proximo != NULL){
			temp = aux;
			aux = aux->proximo;
			
		}
		
		if (temp != NULL) {
            temp->proximo = NULL;
            free(aux);
        } else { 				// se só tiver um elemento
            free(*inicio);
            *inicio = NULL;
        }
        cont-=1;
		printf("%dº elemento removido!\n\n", cont+1);
		system("pause");
	}else{
		
		aux = *inicio;
		contLocal = 1;
		
		while(contLocal<remocao-1){
			aux = aux->proximo;
			contLocal+=1;
		}
		
		temp = aux->proximo;
		aux->proximo = temp->proximo;
		free(temp);
		
		cont-=1;
		printf("%dº elemento removido!\n\n", contLocal+1);
		system("pause");
		
	}
	
}

void inserir_ordenado(pessoa p, aluno al, No **inicio){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		strcpy(novo->p.nome, p.nome);
		strcpy(novo->p.cpf, p.cpf);
		strcpy(novo->p.rg, p.rg);
		strcpy(novo->al.ra, al.ra);
		strcpy(novo->al.curso, al.curso);
		
		//a lista está vazia?
		
		if(*inicio == NULL){
			novo->proximo = NULL;
			*inicio = novo;
			cont++;
		}	//é o menor?
		else if(strcmp(novo->p.nome, (*inicio)->p.nome) < 0){
			novo->proximo = *inicio;
			*inicio = novo;
			cont++;
		}
		else{
			aux = *inicio;
			
			while(aux->proximo && strcmp(novo->p.nome, aux->proximo->p.nome) > 0)
				aux = aux->proximo;
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;
			cont++;
			
		}
	}
	else{
		printf("Não foi possível alocar...\n\n");
		system("pause");
	}
}

main(){
	setlocale(LC_ALL, "Portuguese");
	No *no, *inicio = NULL ;
	int escolha;
	pessoa p;
	aluno al;
	
	do{
		system("cls");
		printf("1  -  Inserir no inicio\n2  -  Inserir no fim\n3  -  Inserir no meio\n4  -  Imprimir\n5  -  Remover elemento\n6  -  Inserir ordenado (nome)\n7  -  Sair\n");
		printf("\nEscolha:");
		scanf("%d", &escolha);
		
		
		switch(escolha){
			case 1:
				entradaDados(&p, &al);
				inserir_inicio(p, al, &inicio);
				break;
				
			case 2:
				entradaDados(&p, &al);
				inserir_fim(p, al, &inicio);
				break;
				
			case 3:
				if(cont>1){
				
				entradaDados(&p, &al);
				inserir_meio(p, al, &inicio);
				}else{
					printf("A lista tem menos de 2 elementos...\n\n");
					system("pause");
				}
				break;
			
				
			case 4:
				imprimir(inicio);
				break;
			
			
			case 5:
				if(cont>0){
					remover(&inicio);
					break;
				
				}else{
					printf("A lista está vazia.:)\n\n");
					system("pause");
					break;
				}
				
			case 6:
				entradaDados(&p, &al);
				inserir_ordenado(p, al, &inicio);
				break;
			}

	}while(escolha!=7);	
	
	No *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
	
	system("pause");
}

