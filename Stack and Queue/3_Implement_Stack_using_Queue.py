class MyStack:

    def __init__(self):
        self.q = deque() 

    def push(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        n = len(self.q)
        for i in range(n-1):
            self.push(self.q.popleft())
        return self.q.popleft()


    def top(self) -> int:
        return self.q[-1]

    def empty(self) -> bool:
        return len(self.q) == 0


