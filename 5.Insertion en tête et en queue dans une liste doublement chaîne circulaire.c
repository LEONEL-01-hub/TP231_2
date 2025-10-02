#include <stdio.h>
#include <stdlib.h>

// Définition du nœud
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// ?? Insertion en tête
void insertHead(Node** headRef, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*headRef == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *headRef = newNode;
        return;
    }

    Node* tail = (*headRef)->prev;

    newNode->next = *headRef;
    newNode->prev = tail;

    tail->next = newNode;
    (*headRef)->prev = newNode;

    *headRef = newNode;
}

// ?? Insertion en queue
void insertTail(Node** headRef, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*headRef == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *headRef = newNode;
        return;
    }

    Node* tail = (*headRef)->prev;

    newNode->next = *headRef;
    newNode->prev = tail;

    tail->next = newNode;
    (*headRef)->prev = newNode;
}

// ??? Affichage
void displayList(Node* head) {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Node* temp = head;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// ?? Libération mémoire
void freeList(Node** headRef) {
    if (*headRef == NULL)
        return;

    Node* current = *headRef;
    Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *headRef);

    *headRef = NULL;
}

// ?? Main
int main() {
    Node* head = NULL;
    int choix, nb, valeur;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserer des elements en tete\n");
        printf("2. Inserer des elements en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Combien de valeurs a inserer en tete ? ");
                scanf("%d", &nb);
                for (int i = 0; i < nb; i++) {
                    printf("Entrez la valeur %d : ", i + 1);
                    scanf("%d", &valeur);
                    insertHead(&head, valeur);
                }
                break;

            case 2:
                printf("Combien de valeurs a inserer en queue ? ");
                scanf("%d", &nb);
                for (int i = 0; i < nb; i++) {
                    printf("Entrez la valeur %d : ", i + 1);
                    scanf("%d", &valeur);
                    insertTail(&head, valeur);
                }
                break;

            case 3:
                displayList(head);
                break;

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    freeList(&head);
    return 0;
}

