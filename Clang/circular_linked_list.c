#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front; 
    Node *rear;
    int count;
} CircularQueue;


void initQueue(CircularQueue *q) {
    q->front = NULL; 
    q->rear = NULL;
    q->count = 0;
}

bool isEmpty(CircularQueue *q) {
    return q->front == NULL;
}

void enqueue(CircularQueue *q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation gagal!\n");
        return;
    }
    newNode->data = value;
    
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; 
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("Data %d berhasil ditambahkan.\n", value);
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    
    Node *temp = q->front;
    int value = temp->data;
    
    if (q->front == q->rear) { 
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    
    free(temp);
    q->count--;
    printf("Data %d berhasil dihapus.\n", value);
}

void getFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data di depan.\n");
        return;
    }
    printf("Data paling depan: %d\n", q->front->data);
}

void getRear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data di belakang.\n");
        return;
    }
    printf("Data paling belakang: %d\n", q->rear->data);
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }
    
    printf("Isi Queue: ");
    Node *current = q->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != q->front);
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q); 
    int pilihan, nilai;
    printf("=== CIRCULAR QUEUE LINKED LIST (C) ===\n");
    do {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue (Tambah data)\n");
        printf("2. Dequeue (Hapus data depan)\n");
        printf("3. Front (Lihat data depan)\n");
        printf("4. Rear (Lihat data belakang)\n");
        printf("5. Tampilkan semua data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                enqueue(&q, nilai); // Cukup kirim '&q'
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                getFront(&q);
                break;
            case 4:
                getRear(&q);
                break;
            case 5:
                displayQueue(&q);
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilihan != 0);

    return 0;
}