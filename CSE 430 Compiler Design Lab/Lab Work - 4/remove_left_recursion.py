# Removing Left Recursion

# Reading File
def read_grammar(filename):
    grammar = {}
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            left, right = line.split("->")
            # print(f"Left: {left}, Right: {right}")
            left = left.strip()
            for p in right.split("|"):
                p = p.strip()
                # print(p)
                if left not in grammar:
                    grammar[left] = []
                grammar[left].append(p)
            # print(f"Productions for {left}: {grammar[left]}")
    return grammar

# Remove Direct Left Recursion
def eliminate_direct_left_recursion(grammar):
    new_grammar = {}
    for each_non_terminal in grammar:
        alpha = []  
        beta = [] 

        for production in grammar[each_non_terminal]:
            if production.startswith(each_non_terminal):
                alpha.append(production[len(each_non_terminal):])
            else:
                beta.append(production)
        # print(f"Non-terminal: {each_non_terminal}, Alpha: {alpha}, Beta: {beta}")

        if alpha:
            non_terminal_dash = each_non_terminal + "'"
            new_grammar[each_non_terminal] = []
            new_grammar[non_terminal_dash] = []
            # A → βA'
            for b in beta:
                new_grammar[each_non_terminal].append(b + non_terminal_dash)
            # A' → αA' | ε
            for a in alpha:
                new_grammar[non_terminal_dash].append(a + non_terminal_dash)
            new_grammar[non_terminal_dash].append("ε")
        else:
            new_grammar[each_non_terminal] = grammar[each_non_terminal]
    
    return new_grammar

# Removing Indirect Left Recursion
def eliminate_indirect_left_recursion(grammar):
    non_terminals = list(grammar.keys())

    for i in range(len(non_terminals)):
        ith_non_terminal = non_terminals[i]

        for j in range(i):
            jth_non_terminal = non_terminals[j]
            
            new_productions = []
            for production in grammar[ith_non_terminal]:
                if production.startswith(jth_non_terminal):
                    # Replace jth_non_terminal with its productions
                    for beta in grammar[jth_non_terminal]:
                        new_productions.append(beta + production[len(jth_non_terminal):])
                else:
                    new_productions.append(production)
            grammar[ith_non_terminal] = new_productions

        grammar = eliminate_direct_left_recursion(grammar)

    return grammar

# Print Grammar
def print_grammar(grammar):
    for left in grammar:
        right = " | ".join(grammar[left])
        print(f"{left} -> {right}")


grammar = read_grammar("grammar.txt")
print("Original Grammar:")
print_grammar(grammar)
# print(grammar)

new_grammar = eliminate_direct_left_recursion(grammar)
print("\nGrammar after removing Left Recursion:")
print_grammar(new_grammar)