#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Deque;

void initDeque(Deque *dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->count = 0;
}

bool isEmpty(Deque *dq) {
    return dq->front == NULL;
}

void enqueueFront(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation gagal!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    
    if (isEmpty(dq)) {
        newNode->next = NULL;
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->count++;
    printf("Data %d berhasil ditambahkan di depan.\n", value);
}

void enqueueRear(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation gagal!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (isEmpty(dq)) {
        newNode->prev = NULL;
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->count++;
    printf("Data %d berhasil ditambahkan di belakang.\n", value);
}

void dequeueFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    
    Node *temp = dq->front;
    int value = temp->data;
    
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    
    free(temp);
    dq->count--;
    printf("Data %d berhasil dihapus dari depan.\n", value);
}

void dequeueRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    
    Node *temp = dq->rear;
    int value = temp->data;
    
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    
    free(temp);
    dq->count--;
    printf("Data %d berhasil dihapus dari belakang.\n", value);
}

void getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data di depan.\n");
        return;
    }
    printf("Data paling depan: %d\n", dq->front->data);
}

void getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data di belakang.\n");
        return;
    }
    printf("Data paling belakang: %d\n", dq->rear->data);
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong!\n");
        return;
    }
    
    printf("Isi Deque: ");
    Node *current = dq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    int pilihan, nilai;

    printf("=== DOUBLE ENDED QUEUE LINKED LIST (C) ===\n\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue Front (Tambah data di depan)\n");
        printf("2. Enqueue Rear (Tambah data di belakang)\n");
        printf("3. Dequeue Front (Hapus data depan)\n");
        printf("4. Dequeue Rear (Hapus data belakang)\n");
        printf("5. Front (Lihat data depan)\n");
        printf("6. Rear (Lihat data belakang)\n");
        printf("7. Tampilkan semua data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                enqueueFront(&dq, nilai);
                break;
            case 2:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                enqueueRear(&dq, nilai);
                break;
            case 3:
                dequeueFront(&dq);
                break;
            case 4:
                dequeueRear(&dq);
                break;
            case 5:
                getFront(&dq);
                break;
            case 6:
                getRear(&dq);
                break;
            case 7:
                displayDeque(&dq);
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