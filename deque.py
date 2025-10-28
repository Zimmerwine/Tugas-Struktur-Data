class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.front = None
        self.rear = None
    
    def is_empty(self):
        return self.front is None
    
    def add_front(self, item):
        new_node = Node(item)
        
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node
        print(f"Elemen '{item}' ditambahkan di depan.")
    
    def add_rear(self, item):
        new_node = Node(item)
        
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.prev = self.rear
            self.rear.next = new_node
            self.rear = new_node
        print(f"Elemen '{item}' ditambahkan di belakang.")
    
    def remove_front(self):
        if self.is_empty():
            print("Deque kosong! Tidak bisa hapus dari depan.")
            return None
            
        removed = self.front.data
        
        if self.front == self.rear:  # hanya satu node
            self.front = self.rear = None
        else:
            self.front = self.front.next
            self.front.prev = None
            
        print(f"Elemen '{removed}' dihapus dari depan.")
        return removed
    
    def remove_rear(self):
        if self.is_empty():
            print("Deque kosong! Tidak bisa hapus dari belakang.")
            return None
            
        removed = self.rear.data
        
        if self.front == self.rear:  # hanya satu node
            self.front = self.rear = None
        else:
            self.rear = self.rear.prev
            self.rear.next = None
            
        print(f"Elemen '{removed}' dihapus dari belakang.")
        return removed
    
    def display(self):
        if self.is_empty():
            print("Deque kosong.")
            return
            
        print("Isi Deque:", end=" ")
        current = self.front
        while current:
            print(current.data, end=" <-> " if current.next else "")
            current = current.next
        print()

if __name__ == "__main__":
    dq = Deque()
    
    while True:
        print("\n=== MENU DEQUE ===")
        print("1. Tambah depan")
        print("2. Tambah belakang")
        print("3. Hapus depan")
        print("4. Hapus belakang")
        print("5. Tampilkan isi deque")
        print("6. Keluar")
        
        pilihan = input("Pilih menu: ")
        
        if pilihan == '1':
            data = input("Masukkan data: ")
            dq.add_front(data)
        elif pilihan == '2':
            data = input("Masukkan data: ")
            dq.add_rear(data)
        elif pilihan == '3':
            dq.remove_front()
        elif pilihan == '4':
            dq.remove_rear()
        elif pilihan == '5':
            dq.display()
        elif pilihan == '6':
            print("Program selesai.")
            break
        else:
            print("Pilihan tidak valid. Coba lagi.")