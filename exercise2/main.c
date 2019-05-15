#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}point;

point line[100];
int lineSize = 0;

void harmonicSeries(int n);
void drawLine(point p1, point p2);

int main(int argc, const char * argv[]) {
    int n;
    /*printf("Geben Sie eine n an um die korrespondierende harmonische Serie anzuzeigen:");
    scanf("%i",&n);
    printf("H(%i) = ",n);
    harmonicSeries(n);*/


    point p1 = {2,2};
    point p2 = {2,10};

    drawLine(p1,p2);

    for(int k=1; k<10;k++) {
        for (int i = 0; i <= lineSize; i++) {
            if (line[i].x == k) {
                for (int j = 0; j < line[i].y; j++) {
                    printf(" ");
                }
                printf("*");
            }
        }
        printf("\n");
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
 * neighbours
 *
 * p[2][2] = 4
 *
 * p[1][1]
 * p[1][2]
 * p[1][3]
 * p[2][1]
 * p[2][3]
 * p[3][1]
 * p[3][2]
 * p[3][3]
 * (p1->x == p2->x-1 && p1->y == p2->y-1||
       p1->x == p2->x-1 && p1->y == p2->y||
       p1->x == p2->x-1 && p1->y == p2->y-1||
       p1->x == p2->x-1 && p1->y == p2->y-1||
       p1->x == p2->x-1 && p1->y == p2->y-1||
       p1->x == p2->x-1 && p1->y == p2->y-1||
       p1->x == p2->x-1 && p1->y == p2->y-1)
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