import cs50

def main():
    
    while True:
        print("Number: ")
        z = cs50.get_int()
        if z > 0:
            break
    y = money(z) + odd(z)
    x = y % 10
    
    if x == 0:
        a = z // 10000000000000
        
        if ((35 > a and a > 33) or (38 > a and a > 36)):
            print("AMEX")
        
        b = (z // 100000000000000)
        
        if (56 > b and b > 50):
            print("MASTERCARD")
        
        c = (z // 1000000000000)
        d = (z // 1000000000000000)
        
        if ((5 > c and c > 3) or (5 > d and d > 3)):
            print("VISA")
        
    else:
        print("INVALID")
    
def money(z):
    i = z // 10
    a = 2 * (i % 10)
    if ((a) > 9):
        a = ((a % 10) + 1)         
    
    j = z // 1000
    b = 2 * (j % 10)
    if ((b) > 9):
        b = ((b % 10) + 1)         
    
    k = z // 100000
    c = 2 * (k % 10)
    if ((c) > 9):
        c = ((c % 10) + 1)         
    
    l = z // 10000000
    d = 2 * (l % 10) 
    if ((d) > 9):
        d = ((d % 10) + 1)         
    
    m = z // 1000000000
    e = 2 * (m % 10)
    if ((e) > 9):
        e = ((e % 10) + 1)         
    
    n = z // 100000000000
    f = 2 * (n % 10)
    if ((f) > 9):
        f = ((f % 10) + 1)         
    
    o = z // 10000000000000
    g = 2 * (o % 10)
    if ((g) > 9):
        g = ((g % 10) + 1)         
    
    p = z // 1000000000000000
    h = 2 * (p % 10)
    if ((h) > 9):
        h = ((h % 10) + 1)         
        
    return (a+b+c+d+e+f+g+h)

def odd(z):
    a = z
    i = a % 10
    
    b = z // 100
    j = b % 10
    
    c = z // 10000
    k = c % 10
    
    d = z // 1000000
    l = d % 10
    
    e = z // 100000000
    m = e % 10

    f = z // 10000000000
    n = f % 10
    
    g = z // 1000000000000
    o = g % 10
    
    h = z // 100000000000000
    p = h % 10

    return (i+j+k+l+m+n+o+p)
    
if __name__ == "__main__":
    main()