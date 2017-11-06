#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct connList{
    int data[11];//保存联通集
    int length;
};

typedef struct connList* ConnList;

struct graph{
    int Edge[11][11];
    int nVertex;
};
typedef struct graph* Position;
typedef Position Graph;


//队列
struct queue{
    int data[12];
    int front;
    int rior;
};
typedef struct queue* Queue;

void init(Queue q){
    memset(q->data, 0, sizeof(q->data));
    q->front = q->rior = -1;
}
//判断队列是否为空
int isEmpty(Queue q){
    return q->front==q->rior ? 1 : 0;
}
//入队
void InQueue(Queue q, int v){
    q->data[++q->rior] = v;
}
//出队
int OutQueue(Queue q){
    if (!isEmpty(q)){
        return q->data[++q->front];
    }
}


void destroy(Queue q){
    free(q);
}


void output(ConnList l){
    int i=0;
    if (l->length>0){
        printf("{ ");
        for (i=0; i<l->length; i++){
            printf("%d ", l->data[i]);
        }
        printf("}");
        printf("\n");
    }
}

Graph createGraph(){
    int n, m;
    int i;
    int a, b;
    Position p = NULL;

    scanf("%d", &n);
    scanf("%d", &m);
    p = (Position)malloc(sizeof(struct graph));
    p->nVertex = n;
    memset(p->Edge,0,sizeof(p->Edge));//将边全部初始化为零

    for (i=0; i<m; i++){
        scanf("%d %d", &a, &b);

        p->Edge[a][b] = 1;
        p->Edge[b][a] = 1;
    }

    return p;
}

int visited[10] = {0};
void DFS(Graph g, int vertex, ConnList l){
    int i;
    int n = 0;

    n = g->nVertex;

    if (visited[vertex]==0){
        visited[vertex] = 1;
        l->data[l->length++] = vertex;
    }

    for (i=vertex; i<n; i++){
        if (visited[i]==0 && g->Edge[vertex][i]==1){
            DFS(g, i, l);
        }  
    }
}
void BFS(Graph g, int vertex, ConnList l){
    int i = 0;
    int n = g->nVertex;
    int v = 0;
    Queue q = (Queue)malloc (sizeof(struct queue));
    init(q);

    InQueue(q, vertex);
    while (!isEmpty(q)){
        v = OutQueue(q);
        if (visited[v]==0){
           l->data[l->length++] = v;
            visited[v] = 1; 
        }

        for (i=v+1; i<g->nVertex; i++){
            if (visited[i]==0 && g->Edge[v][i]==1){
                InQueue(q, i);
            }
        }
    }
    destroy(q);
}

void printListConnectedDFS(Graph g){
    int n = g->nVertex;
    int i = 0;

    ConnList l = (ConnList)malloc(sizeof(struct connList));
    memset(l->data, 0, sizeof(l->data));
    l->length = 0;

    for (i=0; i<n; i++){
        DFS(g, i, l);
        output(l);
        memset(l->data, 0, sizeof(l->data));
        l->length = 0;
    }
    free(l);
}

void printListConnectedBFS(Graph g){
    int n = g->nVertex;
    int i = 0;

    memset(visited, 0, sizeof(visited));

    ConnList l = (ConnList)malloc(sizeof(struct connList));
    memset(l->data, 0, sizeof(l->data));
    l->length = 0;

    for (i=0; i<n; i++){
        BFS(g, i, l);
        output(l);
        memset(l->data, 0, sizeof(l->data));
        l->length = 0;
    }
    free(l);
}

int main(){
    Graph g = createGraph();
    printListConnectedDFS(g);
    printListConnectedBFS(g);
    free(g);

    return 0;
}