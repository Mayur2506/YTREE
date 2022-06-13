#include <stdio.h>
#include "ytree.h"


int main(){

    ytree t;
    init(&t);
    // FILE *fp;
    // fp=fopen("Final_File.txt","r");
    // int x;
    // int arr[50];
    // for(int i=0;i<50;i++){
    //     fscanf(fp,"%d",&x);
    //     arr[i]=x;
    // }
    // mergeSort(arr,0,999999);
    // for(int i=0;i<100;i++){
    //     printf("%d ",arr[i]);
    // }
    // 
    for(int i=0;i<1000;i++){
        insert(&t,i);
    }
    // printf("\n");
    // inorder(t->left);
    int count=0;
    // yytree tmp=search(t,1,&count);
    // if(tmp==NULL){
    //     printf("Not Found\n");
    // }
    // else{
    //     printf("%d\n",tmp->data);
    // }
    // printf("\n %d",count);
    FILE* fpt = fopen("Final_File.txt","w");
    for (int i = 0; i < 1000; i++)
    {
        int count=0;
        yytree tmp=search(t,i,&count);
        fprintf(fpt,"%d\n",count);

    }
    return 0;
}