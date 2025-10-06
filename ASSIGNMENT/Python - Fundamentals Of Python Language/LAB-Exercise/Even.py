def even_numbers():
    for i in range(10):
        yield 2 * i

for num in even_numbers():
    print(num)