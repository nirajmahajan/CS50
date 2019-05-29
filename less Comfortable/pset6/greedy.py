import cs50

# get the change owed
while True:
    print("O hai! How much change is owed?")
    m = cs50.get_float()
    if m > 0:
        break
    
# convert from dollars to cents 
i = round(100 * m)

# get remainder from 25
# that is the amount that has to be payed using
# coins of lower denominations
a = i % 25
# get the number of 25 cent coins used
w = ((i - a) / 25)

# repeat the above process for other denominations

b = a % 10
# get the number of 10 cent coins used
x = ((a - b) / 10)

c = b % 5
# get the number of 5 cent coins used
# also, c is the number of 1 cents to be paid
y = ((b - c) / 5)
    
print("{}".format(w + y + x + c))
    
    
    
    
    
    