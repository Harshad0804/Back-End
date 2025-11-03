# Single Inheritance
class A:
    def showA(self):
        print("Show From A")

class B(A):
    def showB(self):
        print("Show From B")

b = B()
b.showA()
b.showB()

# Multiple Inheritance
class X:
    def showX(self):
        print("Class X")

class Y:
    def showY(self):
        print("Class Y")

class Z(X, Y):
    def showZ(self):
        print("Class Z")

z = Z()
z.showX()
z.showY()
z.showZ()

# Multilevel Inheritance
class P:
    def showP(self):
        print("Class P")

class Q(P):
    def showQ(self):
        print("Class Q")

class R(Q):
    def showR(self):
        print("Class R")

r = R()
r.showP()
r.showQ()
r.showR()