def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    if op == '^':
        return 3
    return 0

def infix_to_postfix(expression):
    stack = []
    output = []

    for ch in expression:
        if ch.isalnum():  # operand
            output.append(ch)
        elif ch == '(':
            stack.append(ch)
        elif ch == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()  # Remove '('
        else:  # operator
            while stack and precedence(ch) <= precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(ch)

    while stack:
        output.append(stack.pop())

    return ''.join(output)

# Example usage
expr = "A+B*C-(D/E+F)*G"
print("Infix:", expr)
print("Postfix:", infix_to_postfix(expr))
