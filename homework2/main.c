#include <stdio.h>

#define LOOKANDSAYSEQUENCESIZE 100

int lookAndSaySequence(int n[], int size);

int main(int argc) {
    int seq[LOOKANDSAYSEQUENCESIZE] = {1};
    int end = 5;

    lookAndSaySequence(seq, 1);
    return 0;
}

int lookAndSaySequence(int a[], int size) {
    int value;
    int count = 0;
    int b[LOOKANDSAYSEQUENCESIZE]={1};
    int bCursor=0;
    for(int j=0; j < size; j++){
        int i = 0;
        value = a[count];
        for (; value == a[count] && a[count]!=0; count++, i++);
        b[bCursor]=i;
        bCursor++;
        b[bCursor]=value;
        bCursor++;
    }
    for(int i = 0; i < bCursor; i++){
        printf("%d",b[i]);
    }
    printf("\n");
    lookAndSaySequence(b, bCursor);
}

