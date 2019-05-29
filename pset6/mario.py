import cs50

# Get the height of pyramid
while True:
    print("Height: ")
    h = cs50.get_int()
    if h >= 0 and h <= 23:
        break

for r in range (0, h):
    for i in range(0, h - r -1):
        print(" ", end = "")
    
    for p in range(0, r + 1):
        print("#", end = "")
        
    print("  ", end = "")
    
    for t in range(0, r + 1):
        print("#", end = "")
        
    # leave a line
    print()