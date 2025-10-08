List1 = ["apple", "banana", "cherry"]
target = "banana"
found = False
for s in List1:
    if s == target:
        print("Found!")
        found = True
        break
if not found:
    print("Not found.")