# Morse-Code-Encoder-and-Decoder
Morse Code Encoder and Decoder

CS 303 Project 2

Morse code (see the table below) is a common code that is used to encode messages consisting
of letters and digits. Each letter consists of a series of dots and dashes. Store each letter of the alphabet in a node
of a binary tree of depth 4. The root node is at depth 0 and stores no letter. The left node at
depth 1 stores the letter e and the right node stores the letter t (code is -). The four
nodes at depth 2 stores the letters with codes . To build the tree (See the figure
below), read a file in which each line consists of a letter followed by its code. The letters should
be ordered by tree depth. To find the position for a letter in the tree, scan the code and branch
left for a dot and branch right for a dash. Encode a message by replacing each letter by its code
symbol. Then decode the message using Morse code tree. Make sure you use a delimiter symbol
between coded letters. See file Morse Code.txt to see coded letters.
