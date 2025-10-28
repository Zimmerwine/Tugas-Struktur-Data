#include <iostream>
using namespace std;

const int MAX = 5;

struct Deque {
    int data[MAX];
    int front;
    int rear;
    int count;
};

void initDeque(Deque &dq) {
    dq.front = 0;
    dq.rear = -1;
    dq.count = 0;
}

bool isFull(Deque &dq) {
    return dq.count == MAX;
}

bool isEmpty(Deque &dq) {
    return dq.count == 0;
}

void enqueueFront(Deque &dq, int value) {
    if (isFull(dq)) {
        cout << "Deque penuh! Tidak bisa menambah data." << endl;
        return;
    }
    dq.front = (dq.front - 1 + MAX) % MAX;
    dq.data[dq.front] = value;
    dq.count++;
    cout << "Data " << value << " berhasil ditambahkan di depan." << endl;
}

void enqueueRear(Deque &dq, int value) {
    if (isFull(dq)) {
        cout << "Deque penuh! Tidak bisa menambah data." << endl;
        return;
    }
    dq.rear = (dq.rear + 1) % MAX;
    dq.data[dq.rear] = value;
    dq.count++;
    cout << "Data " << value << " berhasil ditambahkan di belakang." << endl;
}

void dequeueFront(Deque &dq) {
    if (isEmpty(dq)) {
        cout << "Deque kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    int value = dq.data[dq.front];
    dq.front = (dq.front + 1) % MAX;
    dq.count--;
    cout << "Data " << value << " berhasil dihapus dari depan." << endl;
}

void dequeueRear(Deque &dq) {
    if (isEmpty(dq)) {
        cout << "Deque kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    int value = dq.data[dq.rear];
    dq.rear = (dq.rear - 1 + MAX) % MAX;
    dq.count--;
    cout << "Data " << value << " berhasil dihapus dari belakang." << endl;
}

void getFront(Deque &dq) {
    if (isEmpty(dq)) {
        cout << "Deque kosong! Tidak ada data di depan." << endl;
        return;
    }
    cout << "Data paling depan: " << dq.data[dq.front] << endl;
}

void getRear(Deque &dq) {
    if (isEmpty(dq)) {
        cout << "Deque kosong! Tidak ada data di belakang." << endl;
        return;
    }
    cout << "Data paling belakang: " << dq.data[dq.rear] << endl;
}

void display(Deque &dq) {
    if (isEmpty(dq)) {
        cout << "Deque kosong!" << endl;
        return;
    }
    cout << "Isi Deque: ";
    int i = dq.front;
    for (int j = 0; j < dq.count; j++) {
        cout << dq.data[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    Deque dq;
    initDeque(dq);
    int pilihan, nilai;

    cout << "=== DOUBLE ENDED QUEUE ARRAY (C++) ===" << endl;
    cout << "Kapasitas maksimal: " << MAX << endl << endl;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Enqueue Front (Tambah data di depan)" << endl;
        cout << "2. Enqueue Rear (Tambah data di belakang)" << endl;
        cout << "3. Dequeue Front (Hapus data depan)" << endl;
        cout << "4. Dequeue Rear (Hapus data belakang)" << endl;
        cout << "5. Front (Lihat data depan)" << endl;
        cout << "6. Rear (Lihat data belakang)" << endl;
        cout << "7. Tampilkan semua data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueueFront(dq, nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueueRear(dq, nilai);
                break;
            case 3:
                dequeueFront(dq);
                break;
            case 4:
                dequeueRear(dq);
                break;
            case 5:
                getFront(dq);
                break;
            case 6:
                getRear(dq);
                break;
            case 7:
                display(dq);
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