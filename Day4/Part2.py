# import pyparsing as pp
# day 4 part 2
import math
file = "magic"

totalTrueGames = 0
dictWinningCardCopies = {1: 1}
# if only my brain cells multiplied like these scratchcards


def main(line, lineNum):
    winningNumbersDict = {}
    totWinningNumbers = 0
    winningNumbersAssigned = False
    # Gets rid of Card side
    x = line.split(":")
    x.pop(0)
    newx = x
    # Splits into winning numbers side and ticket numbers side
    newx = x[0].split("|")

    for section in newx:
        # Splits in to individual numbers for each section for section further use
        whitespacesplit = section.split()
        # Assigns winning numbers to dict
        if not winningNumbersAssigned:
            winningNumbersAssigned = True
            for individualValue in whitespacesplit:
                winningNumbersDict[individualValue] = 0
        # If winning numbers already assigned then test ticket numbers against winning numbers
        else:
            for individualValue in whitespacesplit:
                if individualValue in winningNumbersDict:
                    totWinningNumbers += 1
    # Assign copy scratch cards to Card num and times by how many scratch cards this card has to reduce recursive
    for cardWonDifference in range(1, totWinningNumbers + 1):
        if (lineNum+cardWonDifference) in dictWinningCardCopies:
            dictWinningCardCopies[lineNum + cardWonDifference] = dictWinningCardCopies[lineNum + cardWonDifference] + (
                        1 * dictWinningCardCopies[lineNum])
        else:
            dictWinningCardCopies[lineNum + cardWonDifference] = 1 + (
                    1 * dictWinningCardCopies[lineNum])
    # Get how many scratch cars this game had
    scratchCardsWon = dictWinningCardCopies[lineNum]
    # Remove first dict value to save memory
    dictWinningCardCopies.pop(lineNum)

    return scratchCardsWon


if __name__ == '__main__':
    print("Reading File")
    txtFile = open(file, "r")

    totalCards = 0
    lineNum = 1
    for lines in txtFile:
        if lineNum not in dictWinningCardCopies:
            dictWinningCardCopies[lineNum] = 1
        totalCardsMade = main(lines, lineNum)
        lineNum += 1

        totalCards += totalCardsMade
    print(totalCards)
