#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} Deque;

void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

bool isFull(Deque *dq) {
    return dq->count == MAX;
}

bool isEmpty(Deque *dq) {
    return dq->count == 0;
}

void enqueueFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque penuh! Tidak bisa menambah data.\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->data[dq->front] = value;
    dq->count++;
    printf("Data %d berhasil ditambahkan di depan.\n", value);
}

void enqueueRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque penuh! Tidak bisa menambah data.\n");
        return;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->data[dq->rear] = value;
    dq->count++;
    printf("Data %d berhasil ditambahkan di belakang.\n", value);
}

void dequeueFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    int value = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->count--;
    printf("Data %d berhasil dihapus dari depan.\n", value);
}

void dequeueRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data yang bisa dihapus.\n");
        return;
    }
    int value = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->count--;
    printf("Data %d berhasil dihapus dari belakang.\n", value);
}

void getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data di depan.\n");
        return;
    }
    printf("Data paling depan: %d\n", dq->data[dq->front]);
}

void getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong! Tidak ada data di belakang.\n");
        return;
    }
    printf("Data paling belakang: %d\n", dq->data[dq->rear]);
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque kosong!\n");
        return;
    }
    printf("Isi Deque: ");
    int i = dq->front;
    for (int j = 0; j < dq->count; j++) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    int pilihan, nilai;

    printf("=== DOUBLE ENDED QUEUE ARRAY (C) ===\n");
    printf("Kapasitas maksimal: %d\n\n", MAX);

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