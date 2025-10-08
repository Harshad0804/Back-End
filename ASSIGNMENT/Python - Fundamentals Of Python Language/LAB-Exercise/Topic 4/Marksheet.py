rno=int(input("Enter Roll Number : "))
sname=input("Enter Your Name : ")
s1=int(input("enter marks of subject 1 : "))
s2=int(input("enter marks of subject 2 : "))
s3=int(input("enter marks of subject 3 : "))

total = s1+s2+s3
per=total/3

print("Roll no : ",rno)
print("Student Name : ",sname)
print("Total : ",total)
print("Percentage : ",per)

if per>70:
    print("Distinction")
elif per>60:
    print("first class")
elif per>50:
    print("second class")
elif per>40:
    print("pass")
else:
    print("fail")
    