#include <stdio.h>
#include <string.h>
#define SIZE 4
#define STRINGSIZE 100

typedef struct {
    char streetname[STRINGSIZE];
    char city[STRINGSIZE];
    int zipcode;
} address;

typedef struct  {
    char name[STRINGSIZE];
    int age;
    address homeaddress;
} person;

person *search(char* name, person* contacts, int size);
int printPerson(person * p);
int firstPosOfChar(char* text, char c);
void isPalindrom(char* string);

int main() {

    person person1 = {"Megan", 36, {"Main Street 1", "Hollywood", 90069}};
    person person2 = {"Silvester", 64, {"Main Street 1", "Hollywood", 90069}};
    person person3 = {"Arnold", 70, {"Main Street 1", "Hollywood", 90069}};
    person person4 = {"Jennifer", 50, {"Main Street 1", "Hollywood", 90069}};

    person people[SIZE] = {person1,person2,person3,person4};

    person *result = search("Megan", people, SIZE);

    if(result != NULL){
        printPerson(result);
    }

    char string[100];
    strcpy(string,"donaudampfschifffahrtselektrizitaetenhauptbetriebswerkbauunterbeamtengesellschaft");
    char* pName = string;
    int position = firstPosOfChar(pName,'w');
    printf("Char found on position %d.\n",position);


    char anotherString[STRINGSIZE];
    char* p_anotherString = anotherString;
    printf("Please enter a string to check (max 100 chars):\n");
    fgets (anotherString, 100, stdin);
    isPalindrom(p_anotherString);

    return 0;
}

person *search(char* name, person* contacts, int size){
    for(int i = 0; i < size; i++){
        if(strcmp(name,contacts[i].name)==0){
            return &contacts[i];
        }
    }
};

int printPerson(person * p){
    printf("Name: %s | ",p->name);
    printf("Age: %d | ",p->age);
    printf("Street: %s | ",p->homeaddress.streetname);
    printf("Zipcode: %d | ",p->homeaddress.zipcode);
    printf("City: %s\n",p->homeaddress.city);
    return 0;
}

int firstPosOfChar(char* text, char c){
    for(int i = 0; i < STRINGSIZE; i++){
        if(text[i]==c){
            return i;
        }
    }
}

void isPalindrom(char* string) {
    int i = 0;
    int j = 0;
    while(string[i] != '\0'){
        if (string[i] > 64 && string[i] < 91) {
            string[i] = string[i] + 32;
        }
        if(string[i] > 96 && string[i] < 123){
            //rewrite string just lowercase without any other characters
            string[j] = string[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';

    printf("String is ");
    int k = strlen(string)-1;
    int l=0;
    for (;string[l]==string[k]&&l<k;l++,k--);
    if( l==k || strlen(string) == 0 || k+1==l){
        printf("a palindrom.");
    }else{
        printf("not a palindrom.");
    }
}