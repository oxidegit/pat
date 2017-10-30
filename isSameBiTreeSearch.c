#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* Tree;
typedef Tree ptoTree;

struct TreeNode{
    int flag;
    int v;
    Tree Left;
    Tree Right; 
};
//插入一个节点到二叉搜索树中
Tree insertTree(Tree t, int value){
    ptoTree p = NULL;

    if (!t){
        p = (ptoTree)malloc(sizeof(struct TreeNode));
        p->flag = 0;
        p->Right = p->Left = NULL;
        p->v = value;

        t = p;
    }else {
        if (t->v > value){
            t->Left = insertTree(t->Left, value);
        }else{
            t->Right = insertTree(t->Right, value);
        }
    }

    return t;
}
Tree createTree(int n){
    int i = 0;
    Tree t = NULL;
    int value = 0;

    for (i=0; i<n; i++){
        scanf("%d", &value);
        t = insertTree(t, value);
    }

    return t;
}
int judge(Tree t, int n){
    int f = 1;
    int i = 0;
    int value = 0;
    ptoTree cnt = t;

    for (i=0; i<n; i++){
        scanf("%d", &value);
        cnt = t;

        while (cnt){
            if (value > cnt->v){
                if (!cnt->flag){    
                    f = 0;
                    break;
                }
                cnt = cnt->Right;
                
            }else if (value < cnt->v){
                if (!cnt->flag){
                    f = 0;
                    break;    
                }
                cnt = cnt->Left; 
            }else{
                if (cnt->flag==0){
                    cnt->flag = 1;
                    break;
                }else{
                    f = 0;
                }
                
            }
        }
        if (!cnt){
            f = 0;
        }
    }

    if (f){
        return 1;
    }else{
        return 0;
    }

}
void flushTree(Tree t){
    if (t){
        t->flag = 0;
        flushTree(t->Left);
        flushTree(t->Right);
    }
}
void freeTree(Tree t){
    if (t){
        freeTree(t->Left);
        freeTree(t->Right);
        free(t);
    }
}


int main(){
    int n = 0;
    int l = 0;
    Tree t = NULL;
    int i = 0;

    while (scanf("%d", &n)&& n!=0){
        scanf("%d", &l);
        t = createTree(n);

        for (i=0; i<l; i++){
            if (judge(t, n)){
                printf("Yes");
            }else {
                printf("No");
            }

            flushTree(t);
        }
        freeTree(t);
        t = NULL;
    }


    return 0;
}

