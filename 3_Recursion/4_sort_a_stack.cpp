// Helper function to insert an element in sorted order
void sortedInsert(stack<int> &s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

// Recursive function to sort the stack
void sortStack(stack<int> &s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

// Definition of the sort() method of SortedStack
void SortedStack::sort() {
    sortStack(s);
}
