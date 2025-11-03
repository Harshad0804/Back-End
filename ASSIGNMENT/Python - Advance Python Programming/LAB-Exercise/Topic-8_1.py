# Method Overloading
class Math:
    def add(self, a=None, b=None, c=None):
        if a is not None and b is not None and c is not None:
            print(a + b + c)
        elif a is not None and b is not None:
            print(a + b)
        else:
            print(a)

m = Math()
m.add(5)
m.add(5, 10)
m.add(5, 10, 15)

# Method Overriding
class Parent:
    def show(self):
        print("This is parent class")

class Child(Parent):
    def show(self):
        print("This is child class")

c = Child()
c.show()