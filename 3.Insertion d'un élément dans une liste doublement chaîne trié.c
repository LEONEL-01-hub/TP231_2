#include<stdio.h>

struct cellule{
	struct cellule *prec;
	int val;
	struct cellule *suiv;
};

typedef struct cellule Cellule;
typedef Cellule *Liste;

Liste instete(Liste l,int n){
	Liste p;
	p=(Liste)malloc(sizeof(Cellule));
	if(p==NULL)
		return l;
	p->val=n;
	p->prec=NULL;
	p->suiv=l;
	if(l!=NULL)
		l->prec=p;
	l=p;
	return l;
}

void afficher(Liste l){
	Liste p=l;
	while(p!=NULL){
		printf("%d ",p->val);
		p=p->suiv;
	}
}

Liste TrieLis(Liste l){
	Liste p=l;
	int n;
	while(p!=NULL){
		Liste t=p->suiv;
		while(t!=NULL){
			if(p->val>t->val){
				n=p->val;
				p->val=t->val;
				t->val=n;
			}
			t=t->suiv;
		}
		p=p->suiv;
	}
	return l;
}

int main(){
	Liste L1;
	int num,ch;
	L1=NULL;
	do{
		system("cls");
		printf("Choisiser une option\n");
		printf("1. Ajouter une un element\n");
		printf("2. Afficher la liste\n");
		printf("0. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("La liste sera automatiquement trie apres l'ajout\n");
				printf("Entrer l'element a ajouter:");
				scanf("%d",&num);
				L1=instete(L1,num);
				L1=TrieLis(L1);
			break;
			case 2:
				afficher(L1);
				getch();
			break;
			case 0:
				return 0;
			break;
			default:
				printf("Valeur entrer incorrect\n");
			break;
		}
	}while(ch!=0);
	return 0;
}
