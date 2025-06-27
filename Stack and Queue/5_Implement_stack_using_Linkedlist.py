# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Stack class using linked list
class Stack:
    def __init__(self):
        self.top = None

    # Push an element onto the stack
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    # Pop the top element from the stack
    def pop(self):
        if self.is_empty():
            print("Stack Underflow")
            return None
        popped = self.top.data
        self.top = self.top.next
        return popped

    # Peek at the top element without removing it
    def peek(self):
        if self.is_empty():
            return None
        return self.top.data

    # Check if the stack is empty
    def is_empty(self):
        return self.top is None

    # Display the stack elements
    def display(self):
        current = self.top
        if not current:
            print("Stack is empty.")
            return
        print("Stack elements:")
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Example usage
if __name__ == "__main__":
    stack = Stack()
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.display()
    print("Top element:", stack.peek())
    print("Popped:", stack.pop())
    stack.display()
