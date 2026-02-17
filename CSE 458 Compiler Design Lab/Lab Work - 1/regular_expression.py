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
