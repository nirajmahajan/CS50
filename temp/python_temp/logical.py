import cs50

print("Are you a boy? ", end = " ")
c = cs50.get_char()

if c == "Y" or c == "y":
    print("Congratulations!! You are a boy!")
elif c == "N" or c == "n":
    print("Congratulations!! You are not a boy!!")
else :
    print("Are u gay, u dumbass??? Answer the previous question with y or n!!")
