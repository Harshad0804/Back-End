n=int(input("Enter A NUmber : "))

if n%2!=0:
    for i in range(3,int(n/2)+1,2):
        if n%i==0:
            print(n,"Is Not a Prime Number")
    else:
        print(n,"Is a Prime Number")
else:
    print(n,"Is Not a Prime Number")
