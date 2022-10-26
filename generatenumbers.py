import random
maxI = int(input("max number: "))
amnt = int(input("amount of numbers: "))
outfile = input("Output file: ")

with open(outfile, "a") as f:
    for i in range(amnt):
        f.write(str(random.randint(0, maxI)) + "\n")