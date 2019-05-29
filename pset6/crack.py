import cs50
import crypt
import sys

# ensure proper usage
if len(sys.argv) != 2:
    print("Usage: ./crack hash")
    exit(1)

# read the hash
hash1 = sys.argv[1]

# iterate for the password to be one digit
for k in range(65, 123):
    
    # define array of 2 having char and terminator
    one_dig = chr(k)
    
    # convert to crypt
    code1 = crypt.crypt(one_dig, "50")
    
    if code1 == hash1:
        print("{}".format(one_dig))
        exit(0)

# iterate for the password to be two digit
for m1 in range(65, 123):
    for m2 in range(65, 123):
        
        # define array of 3 having chars and terminator
        two_dig = chr(m1) + chr(m2)
        
        # convert to crypt
        code2 = crypt.crypt(two_dig, "50")
        
        # compare this guesssed code with given hash
        if code2 == hash1:
            print("{}".format(two_dig))
            exit(0)

# iterate for the password to be three digit
for n1 in range(65, 123):
    for n2 in range(65, 123):
        for n3 in range(65, 123):
            
            # define array of 4 having chars and terminator
            three_dig = chr(n1) + chr(n2) + chr(n3)
            
            # convert it to crypt
            code3 = crypt.crypt(three_dig, "50")
            
            # compare this guesssed code with given hash
            if code3 == hash1:
                print("{}".format(three_dig))
                exit(0)

# iterate for the password to be four digit
for j1 in range(65, 123):
    for j2 in range(65, 123):
        for j3 in range(65, 123):
            for j4 in range(65, 123):
                
                # define array of 5 having chars and terminator
                four_dig = chr(j1) + chr(j2) + chr(j3) + chr(j4)
                
                # convert to crypt
                code4 = crypt.crypt(four_dig, "50")
                
                # compare this guesssed code with given hash
                if code4 == hash1:
                    print("{}".format(four_dig))
                    exit(0)

# note: code will reach this phase only if the hash does not match
# so now singnify the wrong password and return 0
print("Wrong password entered!!")
exit(0)