import re

text = "Python is awesome"
if re.match("Python", text):
    print("Word matched")
else:
    print("No match")