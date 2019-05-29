import sys
import cs50

# ensure that two arguments are provided
if len(sys.argv) == 2:
    key = int(sys.argv[1])
    
    # get plain text
    print("plaintext: ", end = "")
    ptext = cs50.get_string()
    
    print("ciphertext: ", end = "")
    
    # iterate over the plain text
    
    for c in ptext:
        if (c.isalpha() == True):
            if (c.isupper == True):
                # convert to ascii
                num1 = ord(c)
                # subtract 65 to get '0'.add key then take mod with 26.
                codnum1 = (num1 - 65 + key) % 26
                # again add 65 to conver to upper alphabet
                code1 = chr(codnum1 + 65)
                print(code1, end = "")
            
            else:
                # convert to ascii
                num2 = ord(c)
                # subtract 97 to get '0'.add key then mod with 26
                codnum2 = (num2 - 97 + key) % 26
                # again add 97 to convert to lower alphabets
                code2 = chr(codnum2 + 97)
                print(code2, end = "")
        
        else:
            # if not an alphabet, print as it is
            print(c, end = "")
    print("")

else:
    print("ERROR")
    exit(1)
            
        