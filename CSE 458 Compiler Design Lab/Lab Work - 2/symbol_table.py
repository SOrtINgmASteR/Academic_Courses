# Class to represent a single symbol in the symbol table
class symbol_node:
    def __init__(self, name, type, size, dimension, line, address):
        self.name = name
        self.type = type
        self.size = size
        self.dimension = dimension
        self.line = line
        self.address = address
        self.next = None

# The main symbol table
class symbol_table:
    def __init__(self, max_size):
        self.max_size = max_size
        self.table = [None] * self.max_size

    def get_hash_value(self, symbol_name):
        hash_value = 0
        for c in symbol_name:
            hash_value += ord(c)
        return hash_value % self.max_size
    
    def insert(self, name, type, size, dimension, line, address):
        index = self.get_hash_value(name)
        # duplicate check
        if self.search(name) is not None:
            print(f"{name} already exists in the symbol table")
            return
        new_symbol = symbol_node(name, type, size, dimension, line, address)
        new_symbol.next = self.table[index]
        self.table[index] = new_symbol
        print(f"{name} inserted at index {index}")

    def search(self, name):
        index = self.get_hash_value(name)
        current = self.table[index]
        while current is not None:
            if current.name == name:
                return current
            current = current.next
        return None
    
    def delete(self, name):
        index = self.get_hash_value(name)
        current = self.table[index]
        prev = None
        while current is not None:
            if current.name == name:
                if prev is None:
                    self.table[index] = current.next
                else:
                    prev.next = current.next
                print(f"{name} deleted from index {index}")
                return
            prev = current
            current = current.next
        print(f"{name} not found for deletion")

    def update(self, name, new_type = None, new_size = None, new_dimension = None, new_line = None, new_address = None):
        symbol = self.search(name)
        if symbol is not None:
            if new_type is not None:
                symbol.type = new_type
            if new_size is not None:
                symbol.size = new_size
            if new_dimension is not None:
                symbol.dimension = new_dimension
            if new_line is not None:
                symbol.line = new_line
            if new_address is not None:
                symbol.address = new_address
            print(f"{name} updated successfully")
        else:
            print(f"{name} not found for update")


    def show(self):
        for i in range(self.max_size):
            current = self.table[i]
            while current is not None:
                print(f"Name: {current.name}, Type: {current.type}, Size: {current.size}, Dimension: {current.dimension}, Line: {current.line}, Address: {current.address}")
                current = current.next

# Function to prompt user for operations
def prompt_user():
    print("\n---------------------------------")
    print("Symbol Table. Choose Operations:")
    print("0. Exit")
    print("1. Insert")
    print("2. Search")
    print("3. Delete")
    print("4. Update")
    print("5. Show")
    print("---------------------------------\n")


# Using the symbol table
st = symbol_table(10)
prompt_user()
operation = int((input("Enter operation: ")))
while operation != 0:
    if operation == 1:
        name = input("Enter name: ")
        type = input("Enter type: ")
        size = input("Enter size: ")
        dimension = input("Enter dimension: ")
        line = input("Enter line: ")
        address = input("Enter address: ")
        st.insert(name, type, size, dimension, line, address)
    elif operation == 2:
        name = input("Enter name to search: ")
        symbol = st.search(name)
        if symbol is not None:
            print(f"Found: Name: {symbol.name}, Type: {symbol.type}, Size: {symbol.size}, Dimension: {symbol.dimension}, Line: {symbol.line}, Address: {symbol.address}")
        else:
            print(f"{name} not found")
    elif operation == 3:
        name = input("Enter name to delete: ")
        st.delete(name)
    elif operation == 4:
        name = input("Enter name to update: ")
        new_type = input("Enter new type (leave blank to keep unchanged): ")
        new_size = input("Enter new size (leave blank to keep unchanged): ")
        new_dimension = input("Enter new dimension (leave blank to keep unchanged): ")
        new_line = input("Enter new line (leave blank to keep unchanged): ")
        new_address = input("Enter new address (leave blank to keep unchanged): ")
        st.update(name, new_type if new_type else None, new_size if new_size else None, new_dimension if new_dimension else None, new_line if new_line else None, new_address if new_address else None)
    elif operation == 5:
        st.show()
    else:
        print("Invalid operation")

    prompt_user()
    operation = int((input("Enter operation: ")))