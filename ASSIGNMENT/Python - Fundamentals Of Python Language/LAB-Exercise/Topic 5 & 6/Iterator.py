class MyIterator:
    def __init__(self, numbers):
        self.numbers = numbers
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index < len(self.numbers):
            num = self.numbers[self.index]
            self.index += 1
            return num
        else:
            raise StopIteration

nums = [1, 2, 3, 4, 5]

it = MyIterator(nums)

for n in it:
    print(n)