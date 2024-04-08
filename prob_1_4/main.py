"""
1.4. We now consider the relation between passwords and key size. For this purpose
we consider a cryptosystem where the user enters a key in the form of a password.
1. Assume a password consisting of 8 letters, where each letter is encoded by the
ASCII scheme (7 bits per character, i.e., 128 possible characters). What is the
size of the key space which can be constructed by such passwords?
2. What is the corresponding key length in bits?
3. Assume that most users use only the 26 lowercase letters from the alphabet in-
stead of the full 7 bits of the ASCII-encoding. What is the corresponding key
length in bits in this case?
4. At least how many characters are required for a password in order to generate a
key length of 128 bits in case of letters consisting of
a. 7-bit characters?
b. 26 lowercase letters from the alphabet?
"""


def question_1():
    num_characters = 8
    bits_per_character = 7
    key_space = (2**bits_per_character)**8
    print(f" Total keyspace size per the 8 letters :{key_space}")

def question_2():
    num_characters = 8
    bits_per_character = 7
    key_space = (2**bits_per_character)**8
    print(f" Total keyspace size per the 8 letters :{key_space}")

def main():
  question_1()

if __name__ == "__main__":
    main()
