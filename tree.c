#include <stdio.h>

struct node {
    char v;
    int left;
    int right;
} Tree1[10], Tree2[10];

int isSame(int root1, int root2){
    int a=0;
    int b = 0;
    if (root1==-1 && root2==-1)
        return 1;
    if ((root1==-1&&root2!=-1) || (root2==-1&&root1!=-1))
        return 0;
    if (Tree1[root1].v != Tree2[root2].v){
        return 0;
    }else{
        a = isSame(Tree1[root1].left, Tree2[root2].right);
        b = isSame(Tree1[root1].left, Tree2[root2].left);

        if ((a==1) || (b==1)){
            if (a){
                return isSame(Tree1[root1].right, Tree2[root2].left);
            }else {
                return isSame(Tree1[root1].right, Tree2[root2].right);
            }
        }else {
            return 0;
        }
    }
}

int creatTree(struct node tree[]){
    int n = 0;
    int i = 0;
    char a, b, c;
    int check[10] = {0};
    int root = -1;

    scanf ("%d", &n);
    getchar();

    for (i=0; i<n; i++){
        scanf ("%c %c %c", &a, &b, &c);
        getchar();
        tree[i].v = a;
        if (b != '-'){
            tree[i].left = b-'0';
            check[b-'0'] = 1;
        }else tree[i].left = -1;

        if (c != '-'){
            tree[i].right = c - '0';
            check[c-'0'] = 1;
        }else tree[i].right = -1;
    }

    for (i=0; i<n; i++){
        if (check[i] == 0){
            root = i;
            break;
        }
    }

    return root;
} 

int main(){
    int root1 = -1;
    int root2 = -1;

    root1 = creatTree(Tree1);
    root2 = creatTree(Tree2);

    if (isSame(root1, root2)){
        printf ("Yes");
    }else {
        printf ("No");
    }

    return 0;
}