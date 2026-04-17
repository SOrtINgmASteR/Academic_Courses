# Regular Expression in Python
import re

# Find all digits in a string
text = "int a = 10;"
output = re.findall(r'\d', text)
print(output)
output = re.findall(r'\d+', text)
print(output)

# Find words/characters in a string
text = "int a = 10;"
output = re.findall(r'\w', text)
print(output)
output = re.findall(r'\w+', text)
print(output)

# Find all non-digit word/characters
text = "int a = 10;{}[]..@#$%^&*()"
output = re.findall(r'\D', text)
print(output)
output = re.findall(r'\D+', text)
print(output)

# Find all non-word characters
text = "int a = 10;{}[]..@#$%^&*()"
output = re.findall(r'\W', text)
print(output)
output = re.findall(r'\W+', text)
print(output)

# Find all words that start with 'a'
text = "int a = 10; auto apple"
output = re.findall(r'\ba\w*', text)
print(output)

# Find all the parenthesis in a string
text = "int main() { return 0; }"
output = re.findall(r'[\(\)\{\}\[\]]', text)
print(output)

# Find all the logical operators in a string
text = "if (a > 10 && b < 20) { return a != b; } else { return b < 20; }"
output = re.findall(r'&&|\|\||!=|<=|>=|==|!|<|>', text)
print(output)

# Find all the arithmetic operators in a string
text = "a+=10; b-=5; c*=2; d /= 4; e++; f--; a = b + c"
output = re.findall(r'\+\+|--|\+=|-=|\*=|/=|\+|-|\*|/|=', text)
print(output)