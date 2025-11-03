try:
    f = open("nofile.txt", "r")
    a = 10 / 0
except FileNotFoundError:
    print("File not found.")
except ZeroDivisionError:
    print("Cannot divide by zero.")