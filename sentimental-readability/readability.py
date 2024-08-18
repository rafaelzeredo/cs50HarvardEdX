def countLetters(string):
    letterCount = 0
    for char in string:
        if char.isalpha():
            letterCount += 1
    return letterCount


def countWords(string):
    string = len(string.split())
    return string


def countSentence(string):
    sentences = string.count('.') + string.count('!') + string.count('?')
    return sentences


userInput = input("Text: ")

letters = countLetters(userInput)
words = countWords(userInput)
sentences = countSentence(userInput)
# print(f"letters: {letters}")
# print(f"words: {words}")
# print(f"sentences: {sentences}")
# L is the average number of lettersd per 100 words
# S average number of sentences per 100 words
L = letters / words * 100
S = sentences / words * 100

indexFloat = 0.0588 * L - 0.296 * S - 15.8
index = round(indexFloat)
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
