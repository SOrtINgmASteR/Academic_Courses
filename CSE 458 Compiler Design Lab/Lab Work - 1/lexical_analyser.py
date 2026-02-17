# importing regular expression module
import re

# Read File
with open("C_Code.txt", "r") as f:
    c_code = f.read()
    print(c_code)

final_tokens = {
    'Keyword': [],
    'Identifier': [],
    'Constant': [],
    'Arithmetic Operator': [],
    'Logical Operator': [],
    'Punctuation': [],
    'Parenthesis': []
}



# Remove comments
c_code = re.sub(r'//.*', '', c_code) 
c_code = re.sub(r'/\*.*?\*/', '', c_code, flags=re.DOTALL)
# print(c_code)

# Finding keywords
all_c_keywords = [
    'auto', 'break', 'case', 'char', 'const', 'continue', 'default', 'do', 'double', 'else', 'enum', 'extern', 'float', 'for', 'goto', 'if', 
    'int', 'long', 'register', 'return', 'short', 'signed', 'sizeof', 'static', 'struct', 'switch', 'typedef', 'union', 'unsigned', 'void', 'volatile', 'while']
for keyword in all_c_keywords:
    if re.search(r'\b' + keyword + r'\b', c_code):
        final_tokens['Keyword'].append(keyword)
        c_code = re.sub(r'\b' + keyword + r'\b', '', c_code)
print(final_tokens['Keyword'])
# print(c_code)

# Finding identifiers
identifiers = re.findall(r'[a-zA-Z_][a-zA-Z0-9_]*', c_code)
final_tokens['Identifier'].extend(set(identifiers))
print(final_tokens['Identifier'])

# Finding constants
constants = re.findall(r'\d+\.\d+|\d+', c_code)
final_tokens['Constant'].extend(constants)
print(final_tokens['Constant'])

# Finding arithmetic operators
arithmetic_operators = re.findall(r'\+\+|--|\+=|-=|\*=|/=|\+|-|\*|/', c_code)
final_tokens['Arithmetic Operator'].extend(arithmetic_operators)
print(final_tokens['Arithmetic Operator'])

# Finding logical operators
logical_operators = re.findall(r'&&|\|\||!|<=|>=|==|!=', c_code)
final_tokens['Logical Operator'].extend(logical_operators)
print(final_tokens['Logical Operator'])

# Finding punctuation
punctuation = re.findall(r';,', c_code)
final_tokens['Punctuation'].extend(punctuation)
print(final_tokens['Punctuation'])

# Finding parenthesis
parenthesis = re.findall(r'\(\)\{\}\[\]', c_code)
final_tokens['Parenthesis'].extend(parenthesis)
print(final_tokens['Parenthesis'])