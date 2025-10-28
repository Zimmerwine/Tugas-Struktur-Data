class Node:
    """Represents a node in a doubly-linked list used by the Deque.

    Attributes:
        data: stored value
        next: reference to the next node (toward rear)
        prev: reference to the previous node (toward front)
    """

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class Deque:
    """Deque implemented as a doubly-linked list.

    This version is manual (node-based) so it clearly shows how pointers
    (next/prev) change on each operation. It is appropriate for teaching
    pointer-based implementations and for explaining concepts like:
    - adding/removing nodes at both ends
    - handling empty and single-element cases
    """

    def __init__(self):
        # front: reference to the node at the front (left)
        # rear: reference to the node at the rear (right)
        self.front = None
        self.rear = None

    def is_empty(self):
        """Return True if the deque has no nodes."""
        return self.front is None

    def add_front(self, item):
        """Insert item at the front of the deque.

        Steps:
        - create a new node
        - if deque empty: front and rear both point to new node
        - else: link new_node.next to old front and update old front.prev
        - set front to new node
        """
        new_node = Node(item)

        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node
        print(f"Elemen '{item}' ditambahkan di depan.")

    def add_rear(self, item):
        """Insert item at the rear of the deque.

        Steps:
        - create a new node
        - if deque empty: front and rear both point to new node
        - else: link new_node.prev to old rear and update old rear.next
        - set rear to new node
        """
        new_node = Node(item)

        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.prev = self.rear
            self.rear.next = new_node
            self.rear = new_node
        print(f"Elemen '{item}' ditambahkan di belakang.")

    def remove_front(self):
        """Remove and return the front item.

        Handles three cases:
        - empty deque: return None and print message
        - single-node deque: set front and rear to None
        - multi-node deque: move front forward and clear prev pointer
        """
        if self.is_empty():
            print("Deque kosong! Tidak bisa hapus dari depan.")
            return None

        removed = self.front.data

        if self.front == self.rear:  # only one node
            self.front = self.rear = None
        else:
            # advance front and remove backward link from new front
            self.front = self.front.next
            self.front.prev = None

        print(f"Elemen '{removed}' dihapus dari depan.")
        return removed

    def remove_rear(self):
        """Remove and return the rear item.

        Similar to remove_front but operates at the rear end.
        """
        if self.is_empty():
            print("Deque kosong! Tidak bisa hapus dari belakang.")
            return None

        removed = self.rear.data

        if self.front == self.rear:  # only one node
            self.front = self.rear = None
        else:
            # move rear backward and clear forward link from new rear
            self.rear = self.rear.prev
            self.rear.next = None

        print(f"Elemen '{removed}' dihapus dari belakang.")
        return removed

    def display(self):
        """Print deque contents from front to rear using arrows for clarity."""
        if self.is_empty():
            print("Deque kosong.")
            return

        print("Isi Deque:", end=" ")
        current = self.front
        while current:
            # show arrow between nodes, but not after the last element
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