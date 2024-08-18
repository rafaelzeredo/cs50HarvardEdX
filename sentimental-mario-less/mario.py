number = 0
while number < 1:
    height = input("Height: ")
    if not height.isdigit():
        number = 0
    elif not (int(height) <= 8):
        number = 0
    elif not (int(height) >= 1):
        number = 0
    else:
        number = 1

height = int(height)
# rows
height = int(height)
s = height - 1
for i in range(height):

    # columns
    for x in range(s):

        print(" ", end='')
    s = s - 1
    for y in range(i + 1):
        print("#", end='')
    print("")
