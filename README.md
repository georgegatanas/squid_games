# squid_games
Final C Project for CS102 Section C Fall 2021


# Introduction
Our project mimics Game 5 of the hit Netflix series “Squid Games”. In Game 5, the contestants were presented with two separate paths, each containing 20 visually identical glass panels. Each contestant stepped up and chose either left or right. Upon jumping to the correct panel, the contestant moved one panel closer to the winners’ safety platform. On the other hand, if the contestant chose the wrong panel, they fell to their death. To mimic the game, we generated a set of platforms for the user to attempt to cross, similar to the show. The user will have 16 lives to try to cross 20 sets of platforms. In each set, there is one “correct” platform and one “wrong” platform. If they choose the “correct” platform, they will be able to move on to the next level. If they choose incorrectly, the user will “fall to their death” and start from the beginning. The user will have the choice to either play on “easy” mode (provides a bird’s eye view of the platforms) or “hard” mode (based on memory). The odds of making it past each level without losing a life are 1/(2^20), or 9.5367431640625 x 10−7. However, the platform layout will not change until the game is reset. Therefore, by remembering the pattern on “hard” mode, or looking back at the previous choices in “easy” mode, the player may be able to get to the other side, surviving this round of the Squid Games. Remember, no two games are the same. Once the game resets, the “correct” and “wrong” platforms are randomized to provide the user with a greater challenge. Can you beat our game with the most lives remaining?







# Code Description
First we’ll discuss our project.c file. This file defines the function “printGame”. We write “void printGame(...)” because the function does not return a value. The function itself has the parameters of the integer “levels”, the pointer “row1”, and the pointer “row2”. The function uses a series of printf statements to print the gameboard. The first and the last for loop iterate i from 0 to levels (20 in this case) to print the characters within the “row1” and “row2” arrays (initiated at all “?” until changed by the game) and surround them with “|” characters. The second for loop prints a divider between the rows.

We declare the function “project.c” in our project.h file.

Next, we’ll discuss our make_choice.c file. This file defines the function makeChoice. We begin by writing void makeChoice because this function does not return a value, its sole purpose is to alter the existing values in the code. In the parameters of this function we use pointers. These pointers are used to store the address of two different data types (int and char.). What the function does is declare the integer “response”. It then assigns the value of “response” to the response of the user when they are choosing a platform (0 or 1). It then compares the players response to the “correct” response using an if else statement: if the player's response is equal to the correct value of that platform (platform[*progress] as mentioned earlier), the function prints “You Pass”. If the player has already chosen easy mode and the game board has been initialized, the function uses another if else statement (based on whether the players response was 0 or 1) to update the game board accordingly, placing an “O” as a placeholder for the player on the platform that they chose and an “X” to show that the opposite platform was incorrect. The value of “progress” is then increased by 1, as the player has moved on to the next level. This concludes the first segment of the overarching if else statement. If the player's response was “incorrect” (it did not match the assigned value for that specific platform) the function will print “You Fall”. It will then deduct a life from the player. It also will add an “X” to the platform corresponding to the player's choice onto the game board. This represents that the platform chosen by the player was incorrect. Lastly, the player's progress is set to 0 as they have to start all over from the first platform. This concludes the makeChoice function.

The makeChoice function is declared in our make_choice.h file.


Finally our main.c file. We begin this file by including <stdio.h>, “project.h”, and “makechoice.h” (the standard library of functions as well as our two header files). In the code we declare an integer called “lives”, which we will use later in the code. It is essential to know the players lives because this determines whether or not the game is running. We then print an introductory statement. This details the context of the game as well as what the goal is for the player. We then declare the integer “levels' to define the number of levels the game will have'. As developers, declaring the integers “levels” and “lives” at the beginning of this code and referencing it throughout the code made it very easy to test changes we made, as we did not have to play 20 levels or lose 16 lives each time we wanted to test the code. The next thing we do is declare an integer array called “platforms” with a size of whatever the value of “levels” is. If the game is 20 levels, then the length of the array is 20. We write a for loop to declare an integer i, set i equal to zero, check to make sure i is less than the number of levels, and increase i by 1 once completed. We then set the ith index of the integer array platform to a random “correct” position of either 0 or 1. We do this by using the rand() function, which chooses a random number. We then divide this random number by two and use the remainder of this division as what defines a platform to be correct: if the number is even, the remainder will be zero, therefore the “correct” value of the “i”th platform will be 0. If the number is odd, the remainder will be 1, therefore the “correct” value of the ith column will be 1. We put “correct” in quotes because it's a bit arbitrary, and changes every time the code is run, but it is “correct” in the sense that it is the value the player must enter in order to move on. Later in the code, when we ask the user to guess what side the next platform is on, the user's input will be compared to this “correct” value in order to determine whether they fall or not. We then declare the integer progress and set it equal to zero. We also declare the integer difficulty, which will later be set to an input from the user. We then declare two character arrays called “row 1” and “row 2”, setting their length both equal to the amount of levels. Our next function is a for loop that declares i = 0, checks if i is less than levels, and increases i by 1 when complete. It then puts a question mark into every single entry of rows 1 and 2. This is to show that a platform has not been jumped on yet. Basically it initializes the game board. It then asks the user whether they want to play easy or hard mode through a printf statement. We then tell the user how to choose through another print f statement: “Easy mode = 0 and Hard Mode = 1”. After, we scan for the user input, and set this input to a variable “difficulty”. This is when we begin our while loop. The loop first checks to see if the game is still going on. It does so by first checking if lives are greater than zero (i. e. the player hasn’t run out of lives). It then checks to see if the player has won. If the player's progress is equal to the total number of levels, the game prints “You win” and ends the game. That's because this would mean the player has reached the last platform, thus they have won. The loop then checks to see what difficulty the user chose. If they chose easy, the game prints the game board using the function discussed earlier (printGame). If the player chooses hard, the game board is not printed. We then print the players progress, and remaining lives. We do this using the previous integers we declared, “progress” and “lives”. Finally, we call the function “makeChoice” to take the player through the series of levels.

If the first condition of the overarching if statement discussed in the previous paragraphs is not met (the player has zero lives) the code tells the user that the game is over, ends the program, and the player is eliminated from the Squid Game.






# Youtube Link
https://youtu.be/UV9IW6SJbZA 

