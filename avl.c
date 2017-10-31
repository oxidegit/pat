//AVL树的相关操操作
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode* Position;
typedef Position AVLTree;

struct AVLNode {
    int data;
    AVLTree left;
    AVLTree right;
    int height;
};

int Max(int a, int b){
    return a>b ? a : b;
}

int GetHeight(AVLTree T){
    if (!T){
        return 0;
    }else{
        return Max(GetHeight(T->left), GetHeight(T->right))+1;
    }
}

AVLTree singleLeftRotation(AVLTree A){
    Position b = A->left;

    A->left = b->right;
    b->right = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right))+1;
    b->height = Max(GetHeight(b->left), GetHeight(b->right))+1;
    
    return b;
}
AVLTree singleRightRotation(AVLTree A){
    Position b = A->right;

    A->right = b->left;
    b->left = A;

    A->height = Max(GetHeight(A->left), GetHeight(A->right))+1;
    b->height = Max(GetHeight(b->left), GetHeight(b->right))+1;

    return b;
}
AVLTree doubleLeftRightRotation(AVLTree A){
    A->left = singleRightRotation(A->left);
    return singleLeftRotation(A);
}

AVLTree doubleRightLeftRotation(AVLTree A){
    A->right = singleLeftRotation(A->right);
    return singleRightRotation(A);
}
AVLTree insert(AVLTree T, int v){
    Position cnt = NULL;

    if (!T){
        cnt = (Position)malloc(sizeof(struct AVLNode));
        cnt->height = 0;
        cnt->right = cnt->left = NULL;
        cnt->data = v;

        T = cnt;
    }else {
        if (T->data < v){
            T->right = insert(T->right, v);
            
            if ((GetHeight(T->left) - GetHeight(T->right))==-2){
                if (v > T->right->data){
                    T = singleRightRotation(T);
                }else{
                    T = doubleRightLeftRotation(T);
                }
            }
        }else {
            T->left = insert(T->left, v);
            
            if ((GetHeight(T->left) - GetHeight(T->right))==2){
                if (v < T->left->data){
                    T = singleLeftRotation(T);
                }else{
                    T = doubleLeftRightRotation(T);
                }
            }
        }
    }

    T->height = Max(GetHeight(T->left), GetHeight(T->right))+1;

    return T;
}

#include <stdio.h>

int main(){
    int n;
    int i = 0;
    int v = 0;
    AVLTree T = NULL;

    scanf ("%d", &n);


    for (i=0; i<n; i++){
        scanf("%d", &v);
        T = insert(T, v);
    }

    printf("%d", T->data);

    return 0;
}