#include <stdio.h>
#include <stdlib.h>
#include "ytree.h"



void init(ytree *t){

    (*t)=(ytree)malloc(sizeof(origin));
    (*t)->left=NULL;
    (*t)->middle=NULL;
    (*t)->right=NULL;
    return;
}


int nprevlevel(int l){

    if(l==1){
        return 3;
    }
    int ans=3;
    for (int i = 2; i <= l; i++)
    {
        ans=ans*2;
    }
    return ans;

}

void insert(ytree *t,int data){

    yytree tmp=(yytree)malloc(sizeof(node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->sibling=NULL;

    if(!(*t)->left){
        (*t)->left=tmp;
        return;
    }
    if(!(*t)->middle){
        (*t)->middle=tmp;
        (*t)->left->sibling=tmp;
        return;
    }
    if(!(*t)->right){
        (*t)->right=tmp;
        (*t)->middle->sibling=(*t)->right;
        (*t)->right->sibling=(*t)->left;
        return;
    }
    yytree prev = NULL;
    yytree curr=(*t)->left;
    int l=1;
    while (curr->left)
    {
        l++;
        prev=curr;
        curr=curr->left;
    }
    yytree first=curr;
    if(prev==NULL){
        curr->left = tmp;
        return;    
    }
    int x=nprevlevel(l);
    int k=0;
    yytree lprev=NULL;
    while (k<x)
    {
        if(curr){
            curr=curr->sibling;
            k++;
            if(k%2==0){
                lprev=prev;
                prev=prev->sibling;
            }
        }
        else{
            break;
        }
    }
    if(k==(x)){
        curr->left=tmp;
        return;
    }
    if(prev->left==NULL){
        prev->left=tmp;
        lprev->right->sibling=tmp;
        return;
    }
    else{
        prev->right=tmp;
        prev->left->sibling=tmp;
        if(k==(x-1)){
            prev->right->sibling=first;
        }
        return;
    }
    
}

void check(yytree t){
    if(!t) return;
    printf("%d ", t->data);
    check(t->left);
    return;   
}

yytree search(ytree t,int data,int *count){

    int lno=1;
    int nno=0;
    if(data <= (t->right->data)){

        yytree tmp=t->left;
        for (int i = 0; i < 3; i++)
        {
            (*count)++;
            if(tmp->data==data){
                return tmp;
            }
            tmp=tmp->sibling;
        }
    }
    lno =1;
    yytree find =t->right;
    while (find != NULL)
    {
        (*count)++;
        if(find->data==data){
            return find;
        }
        else if(data > find->data){
            lno++;
            if(find->right){
                find=find->right;
            }
            else{
                // lno++;
                break;
            }
        }
        else if(data < find->data){
            break;
        }
        
    }
    // printf("%d ",lno);
    int x=nprevlevel(lno);
    yytree findl=t->left;
    lno--;
    while (lno--)
    {
        findl=findl->left;
    }
    for (int i = 0; i < x; i++)
    {
        (*count)++;
        if(findl->data==data){
            return findl;
        }
        if(findl->sibling){
            findl=findl->sibling;
        }
        else{
            return NULL;
        }
    }
    return NULL;
}

void inorder(yytree t ){
    FILE* fpt = fopen("Final_File.txt","w");

    int l=1;
    while (t!=NULL)
    {
        int x=nprevlevel(l);
        for (int i = 0; i <x; i++)
        {
            printf("%d ",t->data);
            fprintf(fpt, "%d\n", t->data);
            if(t->sibling){
                t=t->sibling;
            }
            else{
                return;
            }
        }
        t=t->left;
        l++;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

