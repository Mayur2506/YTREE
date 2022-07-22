#include <stdio.h>
#include "ytree.h"


int main(){

    ytree t;
    init(&t);
    for(int i=0;i<1000;i++){
        insert(&t,i);
    }
    int count=0;
    FILE* fpt = fopen("Final_File.txt","w");
    for (int i = 0; i < 1000; i++)
    {
        int count=0;
        yytree tmp=search(t,i,&count);
        fprintf(fpt,"%d\n",count);

    }
    return 0;
}
