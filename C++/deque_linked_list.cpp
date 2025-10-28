#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *front = nullptr;
Node *rear = nullptr;
int count = 0;

bool isEmpty() {
    return front == nullptr;
}

void enqueueFront(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    
    if (isEmpty()) {
        newNode->next = nullptr;
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    count++;
    cout << "Data " << value << " berhasil ditambahkan di depan." << endl;
}

void enqueueRear(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (isEmpty()) {
        newNode->prev = nullptr;
        front = newNode;
        rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    count++;
    cout << "Data " << value << " berhasil ditambahkan di belakang." << endl;
}

void dequeueFront() {
    if (isEmpty()) {
        cout << "Deque kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    
    Node *temp = front;
    int value = temp->data;
    
    if (front == rear) {
        front = nullptr;
        rear = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    
    delete temp;
    count--;
    cout << "Data " << value << " berhasil dihapus dari depan." << endl;
}

void dequeueRear() {
    if (isEmpty()) {
        cout << "Deque kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    
    Node *temp = rear;
    int value = temp->data;
    
    if (front == rear) {
        front = nullptr;
        rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = nullptr;
    }
    
    delete temp;
    count--;
    cout << "Data " << value << " berhasil dihapus dari belakang." << endl;
}

void getFront() {
    if (isEmpty()) {
        cout << "Deque kosong! Tidak ada data di depan." << endl;
        return;
    }
    cout << "Data paling depan: " << front->data << endl;
}

void getRear() {
    if (isEmpty()) {
        cout << "Deque kosong! Tidak ada data di belakang." << endl;
        return;
    }
    cout << "Data paling belakang: " << rear->data << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Deque kosong!" << endl;
        return;
    }
    
    cout << "Isi Deque: ";
    Node *current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void clearDeque() {
    while (!isEmpty()) {
        dequeueFront();
    }
}

int main() {
    int pilihan, nilai;

    cout << "=== DOUBLE ENDED QUEUE LINKED LIST (C++) ===" << endl << endl;

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
                enqueueFront(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueueRear(nilai);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                display();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                clearDeque();
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 0);

    return 0;
}