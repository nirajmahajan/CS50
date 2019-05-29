import cs50

def main():
    i = get_positive_int()
    print("{} is a positive int". format(i))
    
def get_positive_int():
    while True:
        n = cs50.get_int()
        if n >= 1:
            break
    return n
    
if __name__ == "__main__":
    main()