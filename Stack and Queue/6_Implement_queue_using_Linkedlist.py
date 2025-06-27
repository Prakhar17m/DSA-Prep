# Node class for Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Queue class using Linked List
class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    # Enqueue operation
    def enqueue(self, data):
        new_node = Node(data)
        if self.rear is None:  # If the queue is empty
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node

    # Dequeue operation
    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow")
            return None
        temp = self.front
        self.front = self.front.next
        if self.front is None:  # Queue became empty
            self.rear = None
        return temp.data

    # Peek front element
    def peek(self):
        if self.is_empty():
            return None
        return self.front.data

    # Check if queue is empty
    def is_empty(self):
        return self.front is None

    # Display the queue
    def display(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        current = self.front
        print("Queue elements:")
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Example usage
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)
    queue.display()
    print("Front element:", queue.peek())
    print("Dequeued:", queue.dequeue())
    queue.display()
