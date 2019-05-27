#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

hashtable *	ht_init(int capacity) {
	int i;
	
	hashtable * ht = (hashtable *)malloc(sizeof(hashtable));
	ht->capacity = capacity;
	ht->buckets = (list **)malloc(capacity * sizeof(list *));
	for (i = 0; i < capacity; i++) {
		ht->buckets[i] = l_init();
	}
	return ht;
}

int ht_hash(hashtable * ht, char * key) {
	/* TODO: implement hash function */
	int hash = 0;
	while(*key){
	    hash += *key;
	    hash *= 7;
	    key++;
	}
	return hash*7 % ht->capacity;
}

void ht_put(hashtable * ht, char * key, char * value) {
	/* TODO: implement insertion into hash table */
	int hash = ht_hash(ht,key);
	list* l = ht->buckets[hash];
    element* allreadyThere = l_find(l,key);
	if(allreadyThere!=NULL){
        if (value != NULL) {
            strcpy(allreadyThere->station_name, value);
        }else {
            l_delete(l, key);
        }
	} else {
        l_insert(l,key,value);
	}
}

char * ht_get(hashtable * ht, char * key) {
	/* TODO: implement retrieval of data */
	int bucket = ht_hash(ht,key);
    return l_find(ht->buckets[bucket],key)->station_name;
}

void ht_print_bucket_sizes(hashtable * ht) {
	/* TODO: implement printing of bucket sizes */
	int buckets = ht->capacity;
	for(int i = 0;i < buckets; i++){
	    printf("Bucketsize is %i\n",ht->buckets[i]->count);
	}
}
