#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

int main (int argc, char * const argv[]) {
	char line[100]; // keeps one line of the file
	char icao_code[5];
	char station_name[100];
	FILE * fp;
	hashtable * ht;
	
	// try to open the file; in case of an error exit the program
	fp = fopen("stations.csv", "r");
	if (!fp) {
		printf("Cannot open file stations.csv!\n");
		return 1;
	}
	
	// create a hash table
	ht = ht_init(100);
	
	// read all weather stations from file and add them to the 
	// hash table
	while (!feof(fp)) {
		// read one line and skip empty and comment lines
		fgets(line, 100, fp);
		if (line[0] == '#') continue;
		if (isspace(line[0])) continue;
		
		// take the first 4 characters as key value
		strncpy(icao_code, line, 4);
		icao_code[4] = '\0';
		
		// take the rest as value
		strcpy(station_name, strchr(line, ';')+1);

		// add the data to the hash table
		ht_put(ht, icao_code, station_name);
		//printf("added key/value pair: %s / %s\n", icao_code, station_name);
	}
	
	// close the file 
	fclose(fp);

	// now retrieve data from the hash table make a cast to the correct type
	// since we are storing characters, cast to char *
	printf("value for key FVBU is %s\n", (char *)ht_get(ht, "FVBU"));

	ht_print_bucket_sizes(ht);
	
	return 0;
}
