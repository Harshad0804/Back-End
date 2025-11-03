try:
    a = int(input("Enter number: "))
    b = int(input("Enter divisor: "))
    print(a / b)
except ZeroDivisionError:
    print("Division by zero not allowed.")
except ValueError:
    print("Please enter valid numbers.")
except:
    print("Some other error occurred.")