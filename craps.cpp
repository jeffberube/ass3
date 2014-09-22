/* 
 * Author: Jeff Berube
 *
 * Title: Craps (Assigment 3)
 *
 * Description: Craps simulation program
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Terminal color codes to spice up the output a little */
#define RESET 	"\033[m"
#define RED	"\033[31m"
#define GREEN	"\033[32m"

/*
 * die(): Returns random value of a die between 1 and 6
 *
 */

int die() { 
	
	/* Return random number between 1 and 6 */
	return rand() % 6 + 1;

}

/*
 * roll(): Puts value of the dices in the array referenced by dice
 *
 */

void roll(int *dice) {

	dice[0] = die();
	dice[1] = die();

}

/* 
 * play_game(): Plays a full game of craps
 *
 */

void play_game() {

	/* Define variables. dice contains the value of the two dices, results contains
	 * there sum 
	 */
	int dice[2] = {0, 0}, result = 0, point = 0;
	bool playing = true, first = true, won = false;

	while(playing) {
	
		roll(dice);

		result = dice[0] + dice[1];				

		cout << "Player rolled " << dice[0] << " + "
				<< dice[1] << " = " << result << endl;
		
		/* On first run */
		if (first) {
		
			first = false;

			switch (result) {
			
				/* Player rolls 7 or 11, player wins */
				case 7:
				case 11:
					playing = false;
					won = true;
					break;

				/* Player rolls 2, 3 or 12, player loses */
				case 2:
				case 3:
				case 12:
					playing = false;
					won = false;
					break;
				
				/* Player rolls any other values, set the point */
				default:
					cout << "Point is " << result << endl;
					playing = true;
					point = result;

			}

		/* On subsequent runs */
		} else {

			switch (result) {
			
				/* Player rolls 7, loses */
				case 7:
					playing = false;
					won = false;	
					break;

				/* Player rolls any other value, test against point */
				default:
					if (result == point) {
						playing = false;
						won = true;
					} else {
						playing = true;
						won = false;
					}
			}
		
		}
	}

	/* Once loop exits, test to see if player won and display message */
	cout << "Player " << (won ? GREEN : RED) << (won ? "wins." : "loses.") 
		<< endl << endl;


}

int main() {

	/* Declare variables */
	char ans;
	bool done = false;

	/* Initiate seed for random number generator using current time */
	srand(time(NULL));

	/* Loop while user wants to keep playing */
	while(!done) {
	
		cout << endl;

		play_game();

		cout << RESET << "Play again (Y/n)? ";
		ans = cin.get();	

		done = (ans == 'y' || ans == 'Y' || ans == '\n' ) ? false : true;

	}

	return 0;
}
