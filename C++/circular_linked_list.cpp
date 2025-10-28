#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int count = 0;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
    count++;
    cout << "Data " << value << " berhasil ditambahkan." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    
    Node* temp = front;
    int value = temp->data;
    
    if (front == rear) {
        front = nullptr;
        rear = nullptr;
    } else {
        front = front->next;
        rear->next = front;
    }
    
    delete temp;
    count--;
    cout << "Data " << value << " berhasil dihapus." << endl;
}

void getFront() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada data di depan." << endl;
        return;
    }
    cout << "Data paling depan: " << front->data << endl;
}

void getRear() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada data di belakang." << endl;
        return;
    }
    cout << "Data paling belakang: " << rear->data << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
        return;
    }
    
    cout << "Isi Queue: ";
    Node* current = front;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != front);
    cout << endl;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {
    int pilihan, nilai;

    cout << "=== CIRCULAR QUEUE LINKED LIST (C++) ===" << endl << endl;

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
                enqueue(nilai);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                getFront();
                break;
            case 4:
                getRear();
                break;
            case 5:
                display();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                clearQueue();
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 0);

    return 0;
}