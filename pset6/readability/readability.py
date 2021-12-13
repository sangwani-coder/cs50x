from cs50 import get_string

text = get_string("Enter Text: ")

letters = []
words = []
sentence = []

#count letters
for letter in text:
    if letter.isalpha():
        letters.append(letter)
    total_let = len(letters)

#count words
for word in text:
    if word == " ":
        words.append(letters)
    total_words =len(words)+1

#count sentences
for s in text:
    if s == '.' or s=='!' or s =='?':
        sentence.append(s)
    total_sent = len(sentence)

#calculate cole-man liau index
L = (total_let/total_words) * 100
S = (total_sent/total_words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8);

if index < 1:
    print("Before Grade 1")

elif index >= 1 and index < 16:
    print("Grade", index)

else:
    print("Grade 16+")