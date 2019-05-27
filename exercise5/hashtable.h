#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "list.h"


// our hash table class
struct _hashtable {
	int capacity;					// defines the size of the array
	list ** buckets;				// defines a pointer to the array
									// each element is a list for the 
									// entries belonging to the bucket
};

typedef struct _hashtable hashtable;


hashtable *	ht_init(int capacity);								// returns a pointer to a new hash table
int         ht_hash(hashtable * ht, char * key);				// a hash function that generates a hash value from a string
void        ht_put(hashtable * ht, char * key, char * value);	// adds a key/value pair to the 
char *      ht_get(hashtable * ht, char * key);					// retrieves a value from hash table
void		ht_print_bucket_sizes(hashtable * ht);				// prints the sizes of all buckets

#endif /* _HASHTABLE_H_ */
