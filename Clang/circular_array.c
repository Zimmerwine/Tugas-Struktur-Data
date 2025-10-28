#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(CircularQueue *q) {
    return q->count == MAX;
}

bool isEmpty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue penuh! Tidak bisa menambah data.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->count++;
    printf("Data %d berhasil ditambahkan.\n", value);
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Data %d berhasil dihapus.\n", value);
}

void getFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data di depan.\n");
        return;
    }
    printf("Data paling depan: %d\n", q->data[q->front]);
}

void getRear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada data di belakang.\n");
        return;
    }
    printf("Data paling belakang: %d\n", q->data[q->rear]);
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }
    printf("Isi Queue: ");
    int i = q->front;
    for (int j = 0; j < q->count; j++) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int pilihan, nilai;

    printf("=== CIRCULAR QUEUE ARRAY (C) ===\n");
    printf("Kapasitas maksimal: %d\n\n", MAX);

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
                enqueue(&q, nilai);
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