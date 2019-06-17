/* Algorithmen und Datenstrukturen Uebung 5 */

#include <stdio.h>


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

node *insertNode(node *, int , char *);
node *insert(biTree *, int, char *);
void printTreeInline (node *);
void printTreeLevelOrder (node *); 
node *lookup (node *, int);
int treeDepth (node *);


// Funktionen

// Funktion insertNode: siehe Vorlesungsfolien
node *insertNode(node *start, int key, char *data) 
{
	return NULL;
}

// Funktion insert: siehe Vorlesungsfolien
node *insert(biTree *t, int key, char *data) 
{
	return NULL;
}

// Rekursive Funktion zum Ausgeben des Baumes in Inline-Notation
void printTreeInline (node *start) 
{

}

// Funktion zum ebenenweise Ausgeben des Baumes
void printTreeLevelOrder (node *start) 
{

}

// Suchen eines Knotens anhand des Keys
node *lookup (node *start, int key) 
{
	return NULL;
}

int treeDepth (node *start) 
{
	return 0;
}


// Hauptprogramm

int main(void)
{
	// Variablen fuer den Baum anlegen
	
	
	// Einlesen mehrerer Datensaetze von der Tastur
	// und Einfügen in den Baum mittels insert()
	
	
	// Ausgabe des Baumes in Inline-Notation
	
	
	// Ausgabe der Baumtiefe
	
	
	// Ausgabe von Minimum- und Maximum-Key
	
	
	// Ausgabe des Baumes in Levelorder
	
	
	// Suchen nach Datensaetzen (laeuft in einer Schleife)
	// wie in der Aufgabenstellung beschrieben
	
	
	
	return 0;
}
