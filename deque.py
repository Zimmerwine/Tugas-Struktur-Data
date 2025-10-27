# Implementasi Deque tanpa library bawaan Python
# Author: (nama kamu)
# Untuk presentasi: menunjukkan operasi dasar Deque

class Deque:
    def __init__(self):
        # Inisialisasi deque sebagai list kosong
        self.items = []
    
    # Menambahkan elemen di belakang (kanan)
    def add_rear(self, item):
        self.items.append(item)
        print(f"Elemen '{item}' ditambahkan di belakang.")
    
    # Menambahkan elemen di depan (kiri)
    def add_front(self, item):
        self.items.insert(0, item)
        print(f"Elemen '{item}' ditambahkan di depan.")
    
    # Menghapus elemen dari depan
    def remove_front(self):
        if not self.is_empty():
            removed = self.items.pop(0)
            print(f"Elemen '{removed}' dihapus dari depan.")
            return removed
        else:
            print("Deque kosong! Tidak bisa hapus dari depan.")
    
    # Menghapus elemen dari belakang
    def remove_rear(self):
        if not self.is_empty():
            removed = self.items.pop()
            print(f"Elemen '{removed}' dihapus dari belakang.")
            return removed
        else:
            print("Deque kosong! Tidak bisa hapus dari belakang.")
    
    # Mengecek apakah deque kosong
    def is_empty(self):
        return len(self.items) == 0
    
    # Menampilkan isi deque
    def display(self):
        if self.is_empty():
            print("Deque kosong.")
        else:
            print("Isi Deque:", self.items)
    
    # Mengembalikan ukuran deque
    def size(self):
        return len(self.items)

# ----------------------------
# Bagian utama program (demo)
# ----------------------------
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
