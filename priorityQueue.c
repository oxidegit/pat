//优先队列
#include <stdio.h>
#include <stdlib.h>

typedef struct priorQueue{
    int number;//当前已存入节点个数
    int array[1000];
};

typedef struct priorQueue* PriorQueue;
typedef PriorQueue Position;

void insert(PriorQueue p, int v){
    int i;

    i = ++p->number;
    p->array[p->number] = v;

    for (i; p->array[i/2]>v; i/=2){
        p->array[i] = p->array[i/2];
    }
    p->array[i] = v;
}
void output(PriorQueue p, int index)//输出指定下标到根节点的路径
{
    int i = index;

    while (i > 0){
        if (i!=index){
            printf(" ");
        }
        printf("%d", p->array[i]);
        i /= 2;
    }
}

int main(){
    int n, k;
    int i;
    int v;
    PriorQueue p = NULL;

    p = (Position)malloc(sizeof(struct priorQueue));
    p->number = 0;
    p->array[0] = -100001;//设置哨兵

    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++){
        scanf("%d", &v);
        insert(p, v);
    }
    for (i=0; i<k; i++){
        scanf ("%d", &v);
        output(p, v);
        if (i!=k-1){
            printf("\n");
        }
        
    }
    free(p);
    return 0;
}