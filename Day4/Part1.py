import math
file = "magic"

totalTrueGames = 0

# The less brackets the greater the bit wizard

def main(line):
    winningNumbersDict = {}
    x = line.split(":")
    x.pop(0)
    totWinningNumbers = 0
    winningNumbersAssigned = False
    newx = x
    newx = x[0].split("|")
    for section in newx:
        whitespacesplit = section.split()
        if not winningNumbersAssigned:
            winningNumbersAssigned = True
            for individualValue in whitespacesplit:
                winningNumbersDict[individualValue] = 0
        else:
            for individualValue in whitespacesplit:
                if individualValue in winningNumbersDict:
                    totWinningNumbers += 1

    return totWinningNumbers

if __name__ == '__main__':
    print("Reading File")
    txtFile = open(file, "r")
    totalPoints = 0

    for lines in txtFile:
        totalTrueGames = main(lines)

        if totalTrueGames != 0:
            powerOf = totalTrueGames - 1
            totalPoints = totalPoints + math.pow(2,powerOf)
            print(totalPoints)

        # 2^n-1
