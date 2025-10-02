#include<stdio.h>

struct cellule{
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
	if(l==NULL){
		p->suiv=p;
		return p;
	}else{
		p->suiv=l->suiv;
		l->suiv=p;
		return l;
	}
}

Liste insqueue(Liste l,int n){
	Liste p;
	p=(Liste)malloc(sizeof(Cellule));
	if(p==NULL)
		return l;
	p->val=n;
	if(l==NULL){
		p->suiv=p;
		return p;
	}
	p->suiv=l->suiv;
	l->suiv=p;
	return p;
}

void afficher(Liste l){
	Liste p=l->suiv;
	do{
		printf("%d ",p->val);
		p=p->suiv;
	}while(p!=l->suiv);
}

int main(){
	Liste L1;
	int num,ch;
	L1=NULL;
	do{
		system("cls");
		printf("Choisiser une option\n");
		printf("1. Ajouter une entete\n");
		printf("2. Ajoute un element en queue\n");
		printf("3. Afficher la liste\n");
		printf("0. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Entrer l'element a ajouter en tete:");
				scanf("%d",&num);
				L1=instete(L1,num);
			break;
			case 2:
				printf("Entrer l'element a ajouter en queue:");
				scanf("%d",&num);
				L1=insqueue(L1,num);
			break;
			case 3:
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
