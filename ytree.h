typedef struct node{

    int data;
    struct node* left;
    struct node* right;
    struct node* sibling;

}node;

typedef struct origin{

    node* left;
    node* middle;
    node* right;

}origin;

typedef node* yytree;
typedef origin* ytree;

void init(ytree *t);
int nprevlevel(int l);
void insert(ytree *t,int data);
void check(yytree t);
yytree search(ytree t,int data,int *count);
void inorder(yytree t );
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
