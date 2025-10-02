#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insererFin(Node** head, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;

    if (*head == NULL) {
        *head = nouveau;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nouveau;
    }
}

void afficherListe(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void supprimerOccurrences(Node** head, int valeur) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == valeur) {
            if (temp == *head) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    Node* liste = NULL;
    int i, valeur, cible;

    printf("Entrez 5 entiers :\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &valeur);
        insererFin(&liste, valeur);
    }

    printf("\nListe initiale :\n");
    afficherListe(liste);

    printf("\nEntrez la valeur à supprimer : ");
    scanf("%d", &cible);

    supprimerOccurrences(&liste, cible);

    printf("\nListe apres suppression :\n");
    afficherListe(liste);

    return 0;
}

