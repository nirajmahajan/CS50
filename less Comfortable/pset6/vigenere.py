import sys
import cs50

# check for proper usage
if len(sys.argv) != 2:
    print("Please give a key!!")
    exit(1)

key = sys.argv[1]
keylen = len(key)

# iterate over the key
for c in key:
    if c.isalpha == False:
        print("ERROR!")
        exit(1)

# get plain text
print("plaintext: ", end = "")
ptext = cs50.get_string()

print("ciphertext: ", end = "")
k = 0
# iterate over the plaintext
for char in ptext:
    if char.isalpha() == True:
        # we are gonna determine the key for the pth letter of ptext
        if k == keylen - 1:
            k = 0
        # convert the specific key for this char of ptext to upper and 
        # subtract 65 to get its alphabetic position
        temp0 = key[k]
        temp1 = temp0.upper
        ascii = ord(temp1)
        key1 = ascii - 65
        
        if char.isupper() == True:
            num1 = ord(char)
            
            # subtract 65 to get '0'.add key then take mod with 26.
            codnum1 = (num1 - 65 + key1) % 26
            # again add 65 to conver to upper alphabet
            code1 = chr(codnum1 + 65)
            print("{}".format(code1), end = "")
            k = k + 1
        
        if char.islower() == True:
            num2 = ord(char);
            
            # subtract 97 to get '0'.add key then mod with 26
            codnum2 = (num2 - 97 + key1) % 26
            # again add 97 to convert to lower alphabets
            code2 = chr(codnum2 + 97)
            print("{}".format(code2), end = "")
            k = k + 1
        
    else:
        # if not alphabet, print as it is, 
        # while dont increase the position of key, ie 'k'
        print("{}".format(char), end = "")
        
print()
exit(0)