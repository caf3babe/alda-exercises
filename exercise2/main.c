#include <stdio.h>
#include <math.h>
#define GRIDSIZE 15

typedef struct {
    int x;
    int y;
}point;

point line[GRIDSIZE];
int lineSize = 0;

void harmonicSeries(int n);
void drawLine(point p1, point p2);

int main(int argc, const char * argv[]) {
    int n;
    /*printf("Geben Sie eine n an um die korrespondierende harmonische Serie anzuzeigen:");
    scanf("%i",&n);
    printf("H(%i) = ",n);
    harmonicSeries(n);*/


    point p1 = {1, 1};
    point p2 = {12, 15};

    line[lineSize] = p1;
    lineSize++;
    line[lineSize] = p2;
    lineSize++;

    drawLine(p1, p2);


    for (int k = 1; k<GRIDSIZE; k++){
        printf(" --");
    }
    printf("\n");
    for (int x = 1; x < GRIDSIZE; x++) {
        printf("|");
        for (int y = 1; y < GRIDSIZE; y++) {
            printf(" ");
            char cell = ' ';
            for (int i = 0; i < lineSize; i++) {
                if(line[i].x==x && line[i].y==y){
                    cell = '@';
                }
            }
            printf("%c",cell);
            printf(" ");
        }
        printf("|\n");
    }

    for (int k = 1; k<GRIDSIZE; k++){
        printf(" --");
    }
}

void harmonicSeries(int n){
    if (n == 1){
        printf("1");
        return;
    }
    harmonicSeries(n-1);
    printf(" + 1/%i",n);
};

/*
 * neighbours of p[2][2]
 * p[1][1]
 * p[1][2]
 * p[1][3]
 * p[2][1]
 * p[2][3]
 * p[3][1]
 * p[3][2]
 * p[3][3]
 * */

void drawLine(point p1, point p2){
    if((abs(p1.x - p2.x) == 1 && abs(p1.y - p2.y) == 1) || (abs(p1.x - p2.x) == 1 && abs(p1.y - p2.y) == 0) || (abs(p1.x - p2.x) == 0 && abs(p1.y - p2.y) == 1)) {
        return;
    }
    int x = (p1.x+p2.x)/2;
    int y = (p1.y+p2.y)/2;

    point p3 = {x,y};
    line[lineSize] = p3;
    lineSize++;

    drawLine(p1,p3);
    drawLine(p3,p2);
};