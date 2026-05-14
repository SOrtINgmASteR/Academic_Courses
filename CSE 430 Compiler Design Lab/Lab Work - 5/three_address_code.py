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

        # Ignore spaces
        if char == ' ':
            i += 1
            continue

        # Operand
        if char.isalnum():
            operand = ""

            while i < len(expression) and expression[i].isalnum():
                operand += expression[i]
                i += 1

            postfix.append(operand)
            continue

        # Left Parenthesis
        elif char == '(':
            stack.append(char)

        # Right Parenthesis
        elif char == ')':
            while stack and stack[-1] != '(':
                postfix.append(stack.pop())
            stack.pop()

        # Unary minus
        elif char == '-' and (i == 0 or expression[i - 1] in "(+-*/%^"):
            stack.append('u-')

        # Operator
        else:
            while (
                stack and
                stack[-1] != '(' and
                precedence(stack[-1]) >= precedence(char)
            ):
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

        # Unary minus
        if token == 'u-':
            operand = stack.pop()

            temp = f"T{temp_count}"
            temp_count += 1

            tac.append(f"{temp} = uminus {operand}")
            stack.append(temp)

        # Binary operator
        elif token in operators:

            right = stack.pop()
            left = stack.pop()

            temp = f"T{temp_count}"
            temp_count += 1

            tac.append(f"{temp} = {left} {token} {right}")

            stack.append(temp)

        # Operand
        else:
            stack.append(token)

    return tac


# MAIN PROGRAM

# Read expression from file
with open("input.txt", "r") as file:
    expression = file.read().strip()

print("Input Expression:")
print(expression)

# Convert to postfix
postfix = infix_to_postfix(expression)

print("\nPostfix Expression:")
print(" ".join(postfix))

# Generate TAC
tac_code = generate_TAC(postfix)

print("\nThree Address Code:")
for line in tac_code:
    print(line)