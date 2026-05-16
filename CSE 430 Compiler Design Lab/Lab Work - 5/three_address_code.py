# Three Address Code Generator
operators = {
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
    '%': 2,
    '^': 3
}
temp_count = 1


# Check operator precedence
def precedence(op):
    return operators.get(op, 0)


# Convert infix expression to postfix
def infix_to_postfix(expression):
    stack = []
    postfix = []

    i = 0
    while i < len(expression):
        char = expression[i]

        if char == ' ':
            i += 1
            continue

        elif char.isalnum():
            operand = ""
            while i < len(expression) and expression[i].isalnum():
                operand += expression[i]
                i += 1
            postfix.append(operand)
            continue

        elif char == '(':
            stack.append(char)

        elif char == ')':
            while stack and stack[-1] != '(':
                postfix.append(stack.pop())
            stack.pop()

        elif char == '-' and (i == 0 or expression[i - 1] in "(+-*/%^"):
            stack.append('u-')

        else:
            while (stack and stack[-1] != '(' and precedence(stack[-1]) >= precedence(char)):
                postfix.append(stack.pop())
            stack.append(char)

        i += 1

    while stack:
        postfix.append(stack.pop())

    return postfix


# Generate TAC from postfix
def generate_TAC(postfix):
    global temp_count
    stack = []
    tac = []

    for token in postfix:

        if token == 'u-':
            operand = stack.pop()
            temp = f"T{temp_count}"
            temp_count += 1
            tac.append(f"{temp} = uminus {operand}")
            stack.append(temp)

        elif token in operators:
            right = stack.pop()
            left = stack.pop()
            temp = f"T{temp_count}"
            temp_count += 1
            tac.append(f"{temp} = {left} {token} {right}")
            stack.append(temp)

        else:
            stack.append(token)

    return tac


# Read expressions line by line from file
with open("input.txt", "r") as file:
    for expression in file:
        expression = expression.strip()
        if not expression:
            continue
        print("================================")
        print("Input Expression:")
        print(expression)

        # Convert infix to postfix
        postfix = infix_to_postfix(expression)
        print("\nPostfix Expression:")
        print(" ".join(postfix))

        # Generate TAC
        tac_code = generate_TAC(postfix)
        print("\nThree Address Code:")
        for line in tac_code:
            print(line)

        print("================================\n")