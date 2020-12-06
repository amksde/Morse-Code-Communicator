# Morse-Code-Communicator
An Arduino device with it's code for morse-code &lt;-> English translation

There are 2 options:
1. Morse Code to Text
2. Text to Morse Code
The user will have to press the option number through serial input to choose any particular option.

## Option 1
The device contains 3 buttons: dots, dashes, and break. Each of these buttons have corresponding LEDs.
The user enters the morse code for each character. After each character, the break button should be pressed to differentiate it from the next character's morse code. The translated morse code will be displayed on the seven segment display in the following manner:

![A](Images/Alphabets/A.svg)
![B](Images/Alphabets/B.svg)
![C](Images/Alphabets/C.svg)
![D](Images/Alphabets/D.svg)
![E](Images/Alphabets/E.svg)
![F](Images/Alphabets/F.svg)
![G](Images/Alphabets/G.svg)
![H](Images/Alphabets/H.svg)
![I](Images/Alphabets/I.svg)
![J](Images/Alphabets/J.svg)
![K](Images/Alphabets/K.svg)
![L](Images/Alphabets/L.svg)
![M](Images/Alphabets/M.svg)
![N](Images/Alphabets/N.svg)
![O](Images/Alphabets/O.svg)
![P](Images/Alphabets/P.svg)
![Q](Images/Alphabets/Q.svg)
![R](Images/Alphabets/R.svg)
![S](Images/Alphabets/S.svg)
![T](Images/Alphabets/T.svg)
![U](Images/Alphabets/U.svg)
![V](Images/Alphabets/V.svg)
![W](Images/Alphabets/W.svg)
![X](Images/Alphabets/X.svg)
![Y](Images/Alphabets/Y.svg)
![Z](Images/Alphabets/Z.svg)

This can be done indefinitely until the break button is pressed twice. This will take the user back to the menu screen.

## Option 2
The user will enter a text string (without spaces) through serial input. The LEDs which corresponded to the INPUT buttons will now act as the output source for the morse code (dot LED, dash LED, and a break LED).
