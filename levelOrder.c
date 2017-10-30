#include <stdio.h>

typedef struct node {
    int left;
    int right;
} Node;

int createTree(Node tree[]){
    int n = 0;
    int i = 0;
    char left;
    char right;
    int flag[10] = {0};

    scanf ("%d", &n);
    getchar();
    for (i=0; i<n; i++){
        scanf ("%c %c", &left, &right);
        getchar();

        if (left != '-'){
            tree[i].left = left-'0';
            flag[left-'0'] = 1;
        }else{
            tree[i].left = -1;
        }

        if (right != '-'){
            tree[i].right = right-'0';
            flag[right-'0'] = 1;
        }else {
            tree[i].right = -1;
        }
    }

    for (i=0; i<n; i++){
        if (flag[i] == 0){
            break;
        }
    }

    return i;
}



void print(Node tree[], int root){
    int queue[10] = {-1};
    int front = -1;
    int rear = -1;
    int current = -1;
    int flag = 0;

    if (root != -1){
        queue[++rear] = root;
        
        while (rear != front){
            current = queue[++front];
    
            if (tree[current].left==-1 && tree[current].right == -1){
                if (flag == 0){
                    printf ("%d", current);
                }else {
                    printf (" %d", current);
                }
                flag = 1;
            }else{
                if (tree[current].left != -1){
                    queue[++rear] = tree[current].left;
                }
                if (tree[current].right != -1){
                    queue[++rear] = tree[current].right;
                }
            }   
        }
    }
    
}

int main(){
    Node tree[10];
    int root = -1;

    root = createTree(tree);
    print (tree, root);

    return 0;
}