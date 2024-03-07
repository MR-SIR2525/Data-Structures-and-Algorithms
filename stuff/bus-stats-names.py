def separate_names():    
    outputFile = "fixed.txt"

    names = [str]

    with open("names.txt") as f:
        line = f.readline()
        names = line.split(",")

        names = [x.lstrip(" ") for x in names]

    with open(outputFile, "w") as f:
        for name in names:
            f.write(name + "\n")

    print("Done!")

def do_names_match(listAlpha, listBravo):
    they_match = True

    for name in listAlpha:
        if name not in listBravo:
            they_match = False
            print(f'{name} not in listBravo')

    return they_match



rosterFile = "roster.txt"

rosterNames = [str]
messagedNames = [str]

with open(rosterFile) as f:
    for line in f:
        rosterNames.append(line)

with open("fixed.txt") as f:
    for line in f:
        messagedNames.append(line)

if not do_names_match(rosterNames, messagedNames):
    print("Names don't match!")
    