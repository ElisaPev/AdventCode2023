
file = "D:\\Coding\\C++\\adventofcodeprog\\adventofcode\\adventofcode\\day2.txt"

def main(line):

    colourNum = 0
    gameDoable = True
    x = line.split(":")
    x.pop(0)
    newx = x
    newx = x[0].split(";")
    for section in newx:
        whitespacesplit = section.split()
        correctColours = {"blue": 14, "green": 13, "red": 12}

        for individualValue in whitespacesplit:

            if "," in individualValue:
                individualValue = individualValue.replace(',', '')

            if individualValue in correctColours:

                correctColours[individualValue] = correctColours[individualValue] - colourNum
                if correctColours[individualValue] < 0:
                    gameDoable = False
            else:
                if individualValue.isnumeric():
                    colourNum = int(individualValue)
                else:
                    print(individualValue)
        #print(correctColours)
    return gameDoable


if __name__ == '__main__':
    print("reading file")
    totalTrueGames = 0
    txtFile = open(file, "r")
    lineNum = 1
    for lines in txtFile:
        if main(lines):
            totalTrueGames += lineNum
        lineNum += 1

    print(totalTrueGames)
