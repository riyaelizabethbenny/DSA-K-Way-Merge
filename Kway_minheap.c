#include <stdio.h>

#define K 3
#define SIZE 4

typedef struct {
    int value;
    int list;
    int index;
} Node;

Node heap[K];
int heapSize = 0;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown()
{
    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize &&
            heap[left].value < heap[smallest].value)
            smallest = left;

        if (right < heapSize &&
            heap[right].value < heap[smallest].value)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void insert(Node x)
{
    int i = heapSize;
    heap[heapSize++] = x;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[i].value < heap[parent].value)
        {
            swap(&heap[i], &heap[parent]);
            i = parent;
        }
        else
            break;

        i = parent;
    }
}

Node deleteMin()
{
    Node min = heap[0];

    heap[0] = heap[heapSize - 1];
    heapSize--;

    if (heapSize > 0)
        heapifyDown();

    return min;
}

int main()
{
    int L[K][SIZE] = {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    for (int i = 0; i < K; i++)
    {
        Node x = {L[i][0], i, 0};
        insert(x);
    }

    printf("Merged list: ");

    while (heapSize > 0)
    {
        Node x = deleteMin();

        printf("%d ", x.value);

        if (x.index + 1 < SIZE)
        {
            Node next;

            next.value = L[x.list][x.index + 1];
            next.list = x.list;
            next.index = x.index + 1;

            insert(next);
        }
    }

    printf("\n");

    return 0;
}
