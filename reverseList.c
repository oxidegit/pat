#include <stdio.h>

//数组节点
typedef struct arrNode{
    int nextAdd;
    int data;
} Node;

int k = 0;
int length = 0;

void input(Node list[], int length){
    int i = 0;
    int address = 0;

    for (i=0; i<length; i++){
        scanf ("%d", &address);
        scanf ("%d %d", &list[address].data, &list[address].nextAdd);    
    }
}

int getLength(Node list[], int head){
    int cnt = head;
    int l = 0;

    while (cnt != -1){
        l++;
        cnt = list[cnt].nextAdd;
    }

    return l;
}

int reverse(Node list[], int head){
    int count = 0;
    int newa = 0;
    int old = 0;
    int tmp = 0;
    int i = 0;
    
    newa = head;
    old = list[newa].nextAdd;

    while ((length-count) >= k){
        while (i < k-1){
            tmp = list[old].nextAdd;
            list[old].nextAdd = newa;
            newa = old;
            old = tmp;
            i++;
        }
        i = 0;
        count += k;
        tmp = head;
        head = newa;
        newa = tmp;
        list[newa].nextAdd = old;
    }

    return head;
}

void output(Node list[], int head){
    int cnt = head;

    while (cnt != -1){
        if (list[cnt].nextAdd != -1){
            printf("%05d %d %05d\n", cnt, list[cnt].data, list[cnt].nextAdd);
        }else{
            printf("%05d %d -1\n", cnt, list[cnt].data);
        }
        cnt = list[cnt].nextAdd;
    }
}



int main(){

    int head = -1;
    Node list[100000];

    scanf ("%d %d %d", &head, &length, &k);
    input(list, length);
    length = getLength(list, head);
    head = reverse(list, head);
    output(list, head);

    return 0;
}


