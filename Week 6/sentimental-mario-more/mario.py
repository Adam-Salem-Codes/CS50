from cs50 import get_int

height = 0
while height <= 0 or height > 8:
    height = get_int("Enter the height of the pyramid.")

# Algorithm to print pyramid.
for i in range(1, height + 1):
    for j in range(1, height + 1):

        if j > height - i:
            print("#", end='')
        else:
            print(end=' ')

        if j == height:
            print(" ", "#" * i, end='')
    # Newline. (You could technically write it print() or print(end = '\n')
    # but I perfer the second one because, it's more obvious that you are printing a newline).
    print(end='\n')

