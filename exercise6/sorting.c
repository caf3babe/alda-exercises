#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct _element {
	char icao_code[5];
	char station_name[100];
};

typedef struct _element element;


void insertion_sort(element* stations, int size) {
	// implement either insertion_sort or selection_sort
}

void selection_sort(element* stations, int size) {
	// implement either insertion_sort or selection_sort
    int currentElement;
    for(int i=0;i<size;i++){
        currentElement = i;
        for(int j=i;j<size;j++){
            if(strcmp(stations[currentElement].icao_code,stations[j].icao_code)>0) {
                currentElement = j;
            }
        }
        if(i!=currentElement){
            element holdElement = stations[i];
            stations[i] = stations[currentElement];
            stations[currentElement] = holdElement;
        }
    }
}

int comp(char *a,char *b){
    return strcmp(a,b);
}

void selection_sort_comp(void* data, int nitems, int size, int(*comp)(void *, void*)){
    // implement either insertion_sort or selection_sort
    element *stations = (element*)data;
    int currentElement;
    for(int i=0;i<nitems;i++){
        currentElement = i;
        for(int j=i;j<nitems;j++){
            if((int)comp(&stations[currentElement],&stations[j])>0)
                currentElement = j;
        }
        if(i!=currentElement){
            element holdElement = stations[i];
            stations[i] = stations[currentElement];
            stations[currentElement] = holdElement;
        }
    }
}

void quick_sort(element* stations, int left, int right) {
	// implement either quick_sort or merge_sort
}

void merge_sort(element* stations, element* tmpStations, int left, int right) {
	// implement either quick_sort or merge_sort
	// tmpStations corresponds to the array B in the lecture slides
	if(left < right){
	    int middle = left+(right-left)/2;
	    merge_sort(stations,tmpStations,left,middle);
	    merge_sort(stations,tmpStations,middle+1,right);

        int i,j,k;
        i = left;
        j = middle+1;
        k = 0;
        while(i<=middle && j<= right) {
            if(strcmp(stations[i].icao_code,stations[j].icao_code)<0)
                tmpStations[k++]=stations[i++];
            else
                tmpStations[k++]=stations[j++];
        }
        while(i<=middle) {
            tmpStations[k++]=stations[i++];
        }
        while(j<=right) {
            tmpStations[k++]=stations[j++];
        }
        for(i=left,j=0;i<=right;i++,j++) {
            stations[i] = tmpStations[j];
        }
	}
}

void print_stations(element* stations, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s : %s", stations[i].icao_code, stations[i].station_name);
	}
}

int readfile(element* stations, int* size) {
	FILE * fp;
	char line[100]; // keeps one line of the file

	// try to open the file; in case of an error exit the program
	*size = 0;
	fp = fopen("C:\\Users\\nichil\\repo\\AldaExercises\\exercise6\\stations.csv", "r");
	if (!fp) {
		printf("Cannot open file stations.csv!\n");
		return 1;
	}
	
	// read all weather stations from file and add them to the 
	// hash table
	while (!feof(fp)) {
		// read one line and skip empty and comment lines
		fgets(line, 100, fp);
		if (line[0] == '#') continue;
		if (isspace(line[0])) continue;
		
		// take the first 4 characters as key value
		strncpy(stations[*size].icao_code, line, 4);
		stations[*size].icao_code[4] = '\0';
		
		// take the rest as value
		strcpy(stations[*size].station_name, strchr(line, ';')+1);
		*size += 1;
	}
	
	// close the file 
	fclose(fp);
	
	return 0;
}

int main(int argc, char** argv) {
	element* stations; // holds the station codes and names
	element* tmpStations; // holds temporary station codes and names for merge sort
	int size; // holds the number of valid entries in the array
		
	stations = (element*)malloc(sizeof(element)*6000);
	tmpStations = (element*)malloc(sizeof(element)*6000);
	
	/*// now lets try insertion sort
	printf("Sorting with insertion sort:\n\n");
	// read the station data from file
	readfile(stations, &size);
	// sort the station names
	insertion_sort(stations, size);
	// print the result
	print_stations(stations, size);*/


	// now lets try selection sort
	printf("Sorting with selection sort:\n\n");
	// read the station data from file
	readfile(stations, &size);
	//declare function pointer
	// sort the station names
	selection_sort(stations, size);
	// print the result
	print_stations(stations, size);

	/*

	// now lets try merge sort
	printf("Sorting with merge sort:\n\n");
	// read the station data from file
	readfile(stations, &size);
	// sort the station names
	merge_sort(stations, tmpStations, 0, size-1);
	// print the result
	print_stations(stations, size);
	*/
	
	/*// now lets try quick sort
	printf("Sorting with quick sort:\n\n");
	// read the station data from file
	readfile(stations, &size);
	// sort the station names
	quick_sort(stations, 0, size-1);
	// print the result
	print_stations(stations, size);*/
	
	free(stations);
	free(tmpStations);
	
	return 0;
}