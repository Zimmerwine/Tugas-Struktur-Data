#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int data[MAX];
    int front;
    int rear;
    int count;
};

void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isFull(Queue &q) {
    return q.count == MAX;
}

bool isEmpty(Queue &q) {
    return q.count == 0;
}

void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa menambah data." << endl;
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = value;
    q.count++;
    cout << "Data " << value << " berhasil ditambahkan." << endl;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    int value = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    cout << "Data " << value << " berhasil dihapus." << endl;
}

void getFront(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak ada data di depan." << endl;
        return;
    }
    cout << "Front: " << q.data[q.front] << endl;
}

void getRear(Queue &q) {
    if (isEmpty(q)) {
        cout << "Rear: " << q.rear << endl;
        return;
    }
    cout << "Data paling belakang: " << q.data[q.rear] << endl;
}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    cout << "Isi Queue: ";
    int i = q.front;
    for (int j = 0; j < q.count; j++) {
        cout << q.data[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    Queue q;
    initQueue(q);
    int pilihan, nilai;

    cout << "=== CIRCULAR QUEUE ARRAY (C++) ===" << endl;
    cout << "Kapasitas maksimal: " << MAX << endl << endl;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Enqueue (Tambah data)" << endl;
        cout << "2. Dequeue (Hapus data depan)" << endl;
        cout << "3. Front (Lihat data depan)" << endl;
        cout << "4. Rear (Lihat data belakang)" << endl;
        cout << "5. Tampilkan semua data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(q, nilai);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                getFront(q);
                break;
            case 4:
                getRear(q);
                break;
            case 5:
                display(q);
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 0);

    return 0;
}