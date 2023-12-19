
file = "magicBinary"


def main(line):
    correctColours = {"blue": 0, "green": 0, "red": 0}
    colourNum = 0
    x = line.split(":")
    x.pop(0)
    newx = x
    newx = x[0].split(";")
    for section in newx:
        whitespacesplit = section.split()
        for individualValue in whitespacesplit:

            if "," in individualValue:
                individualValue = individualValue.replace(',', '')

            if individualValue in correctColours:
                currentNum = correctColours[individualValue]
                correctColours[individualValue] = colourNum if colourNum > correctColours[individualValue] else currentNum
            else:
                if individualValue.isnumeric():
                    colourNum = int(individualValue)
                else:
                    print(individualValue)
    powerNum = correctColours["red"] * correctColours["blue"] * correctColours["green"]
    print(correctColours)
    return powerNum


if __name__ == '__main__':
    print("reading file")
    totalPowerNum = 0
    txtFile = open(file, "r")

    for lines in txtFile:
        powerNum = main(lines)
        totalPowerNum += powerNum

    print(totalPowerNum)
