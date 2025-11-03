import re

text = "Python is fun to learn"
if re.search("fun", text):
    print("Word found")
else:
    print("Word not found")