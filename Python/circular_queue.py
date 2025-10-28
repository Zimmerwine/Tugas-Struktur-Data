# Python program for insertion and deletion
# in Circular Queue

class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None

class Queue:
    def __init__(self):
        self.front = self.rear = None

# Function to insert element in a Circular queue
def enQueue(q, value):
    newNode = Node(value)

    if q.front is None:
        q.front = newNode
    else:
        q.rear.next = newNode

    q.rear = newNode
    q.rear.next = q.front

# Function to delete element from 
# Circular Queue
def deQueue(q):
    if q.front is None:
        return -1

    value = None

    if q.front == q.rear:
        value = q.front.data
        q.front = q.rear = None
    else:
        temp = q.front
        value = temp.data
        q.front = q.front.next
        q.rear.next = q.front

    return value
    
# Function to return the front value
def front(q):
	front = q.front

	if front is None:
		return -1
	
	return front.data

# Function to return the rear value
def rear(q):
	rear = q.rear

	if rear is None:
		return -1

	return rear.data

def printQueue(q):
    if q.front is None:
        return

    curr = q.front
    while True:
        print(curr.data, end="->")
        curr = curr.next
        if curr == q.front:
            break
    
    print("[kembali ke ", front(q),"]")
    print()

if __name__ == "__main__":
    q = Queue()
    
    while True:
        print("\nMenu Circular Queue:")
        print("1. Enqueue")
        print("2. Show Front and Rear values")
        print("3. Dequeue")
        print("4. Print Queue")
        print("5. Exit")
        
        choice = input("Pilih menu (1-5): ")
        
        if choice == '1':
            n = int(input("Masukkan berapa kali ingin melakukan enqueue: "))
            for i in range(n):
                value = int(input(f"Masukkan nilai ke-{i+1}: "))
                enQueue(q, value)
            print("Enqueue selesai!")
            
        elif choice == '2':
            print("Front value =", front(q))
            print("Rear value =", rear(q))
            
        elif choice == '3':
            deleted = deQueue(q)
            if deleted != -1:
                print("Deleted value =", deleted)
            else:
                print("Queue kosong!")
                
        elif choice == '4':
            if q.front is None:
                print("Queue kosong!")
            else:
                print("Isi Queue:", end=" ")
                printQueue(q)
                
                
        elif choice == '5':
            print("keluar...bye bye!")
            break
            
        else:
            print("Pilihan tidak valid! Silakan pilih 1-5.")