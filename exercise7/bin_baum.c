/* Algorithmen und Datenstrukturen Uebung 5 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Globale Variablen und Typdefinitionen

typedef struct node_ {
    int key;
    char *data;
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct biTree_ {
    int size;
    node *root;
} biTree;


// Funktionsprototypen

node *insertNode(node *, int, char *);

node *insert(biTree *, int, char *);

void printTreeInline(node *);

void printTreeLevelOrder(node *);

node *lookup(node *, int);

int treeDepth(node *);


// Funktionen

// Funktion insertNode: siehe Vorlesungsfolien
node *insertNode(node *start, int key, char *data) {
    node *newNode;
    if (start == NULL) {
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode;
    }
    if (key < start->key) {
        newNode = insertNode(start->left, key, data);
        if (start->left == NULL)
            start->left = newNode;
    } else {
        newNode = insertNode(start->right, key, data);
        if (start->right == NULL)
            start->right = newNode;
    }
    return newNode;
}

// Funktion insert: siehe Vorlesungsfolien
node *insert(biTree *t, int key, char *data) {
    node *newNode;
    newNode = insertNode(t->root, key, data);
    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;
    return newNode;
}

// Rekursive Funktion zum Ausgeben des Baumes in Inline-Notation
void printTreeInline(node *start) {
    if (start->left != NULL) {
        printTreeInline(start->left);
    }
    printf("%d", start->key);
    printf(": ");
    printf("%s", start->data);
    printf(", ");
    if (start->right != NULL) {
        printTreeInline(start->right);
    }
}

// Funktion zum ebenenweise Ausgeben des Baumes
void printGivenLevel(node *root, int level) {
    if (root == NULL)
        return;
    if (level == 1) {
        printf("%d", root->key);
        printf(": ");
        printf("%s", root->data);
        printf(", ");
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printTreeLevelOrder(node *root) {
    int h = treeDepth(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */

// Suchen eines Knotens anhand des Keys
node *lookup(node *start, int key) {
    if (start == NULL) {
        return NULL; // Knoten nicht gefunden
    }
    if (key == start->key) {
        return start; // Knoten wurde gefunden
    }
    if (key < start->key) {
        return lookup(start->left, key);
    } else {
        return lookup(start->right, key);
    }
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int treeDepth(node *start) {
    if (start == NULL) {
        return 0;
    } else {
        return 1 + max(treeDepth(start->left), treeDepth(start->right));
    }
}


// Hauptprogramm

int main(void) {

    // Variablen fuer den Baum anlegen
    biTree binaryTree = {0, NULL};
    char *name;
    int personalnumber;

    printf("============================================================================================================\n");
    printf("                                         Personen im B-Tree\n");
    printf("============================================================================================================\n");
    printf("Datenerfassung\n");
    printf("------------------------------------------------------------------------------------------------------------\n");

    // Einlesen mehrerer Datensaetze von der Tastur
    // und Einfügen in den Baum mittels insert()
    int count;
    printf("Wie viele Personen willst Du eingeben? \n");
    scanf("%i", &count);
    while (count != 0) {
        name = malloc(sizeof(char)*200);
        printf("Name:");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        printf("Personalnummer:");
        scanf("%i", &personalnumber);
        if (lookup(binaryTree.root, personalnumber) != NULL) {
            printf("Personalnummer ist bereits vorhanden\n");
            continue;
        }
        insert(&binaryTree, personalnumber, name);
        count--;
    }

    // Ausgabe des Baumes in Inline-Notation
    printf("Ausgabe des Baumes in Inorder Notation\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printTreeInline(binaryTree.root);
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------\n");

    // Ausgabe der Baumtiefe
    printf("Ausgabe der Baumtiefe\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%d\n", treeDepth(binaryTree.root));
    printf("------------------------------------------------------------------------------------------------------------\n");
    // Ausgabe von Minimum- und Maximum-Key


    // Ausgabe des Baumes in Levelorder
    printf("Ausgabe des Baumes in Level Order Notation\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printTreeLevelOrder(binaryTree.root);
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------\n");

    // Suchen nach Datensaetzen (laeuft in einer Schleife)
    // wie in der Aufgabenstellung beschrieben

    while(1){
        int id;
        printf("ID zum Suchen eingeben:\n");
        scanf("%i",&id);
        node *found = lookup(binaryTree.root,id);
        if(found != NULL){
            printf("%s\n",found->data);
        } else {
            printf("Nothing found\n");
        }
    }
    return 0;
}
