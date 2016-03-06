def lower(x):
    if(x == 0):
        return 0
    if(x == 1):
        return 1
    print("This is x before calc:", x)
    if(x%2 == 1):
        x - 1
    print("This is x after calc:", x)
    return lower(int(x/2))

i = int(input("Enter a val:\n"))
i = lower(i)
print(i)
