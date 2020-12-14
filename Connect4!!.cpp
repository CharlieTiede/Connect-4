/* Connect4!!.cpp
* Charlie Tiede
* 12/2/2020-12/13/2020
* create the pattern of the board section for the connect 4 game
* created players and their character/piece placement
* add check column capacity
* check for derectional 4 in a rows
* Check for draw or win by player(s)
*/



#include <iomanip>
#include<iostream>
#include <string>


using namespace std;
void display();
bool check(int a, int b);
int drop(int b, char player);
char place[6][7];// array available for whole program


int main()
{
	rerun:
	for (int a = 0; a <= 5; a++) {	
		for (int b = 0; b <= 6; b++)	//fill place with whitespace
			place[a][b] = ' ';
	}
	display();//Displays for first time so players can see the board

	int hold;//Will house user row choice
	int hold2 = 0;//will hold drop value
	int charsPlaced = 0;//Number of peices dropped so can end game if a draw
	bool gamewon = false;//Will be changed to true when game is won and will exit while loop
	string input; // for asking to play again
	char player = 2;//start as player 2 will change back too player 1

		while (!gamewon) {//will stop when game is won
			if (hold2 != -1) {//check if there was a error in the last drop
				if (player == 2) {//if player 2 last dropped a piece, so its player 1's turn
					cout << "player 1 drop where?";
					player = 254;//char of player 1's piece
				}
				else {
					cout << "player 2 drop where?";
					player = 2;//char of player 2's piece
				}
			}
			while (true) {//will run untill 'break;'
				if (charsPlaced == 42) break;//if draw
				cin >> hold;//get user input
				hold--;//take off 1 to account for arrays starting at 0 not 1
				if (hold <= 6 && hold >= 0) break;//if within valid range stop loop
				else cout << "\nplease enter a value between 1 and 7 :";//ask for input and loop again
				if (cin.fail())	//catch a non number
				{						//
					cin.clear();		//Stops cin trying to put its value in to hold
					char c;			//Try entering a non number without this, too see what this does
					cin >> c;			//
				}						//Catch a non number

			}
			if (charsPlaced == 42) break;//if draw
			hold2 = drop(hold, player);//drop the player store the row in hold2
			if (hold2 == -1)	cout << "Colomn is full\nPlease enter another number between 1 and 7:";//if error -1 row is full
			else {
				gamewon = check(hold2, hold);//check if game is run
				charsPlaced++;//another character has been succesfully placed
				system("cls");//This clears the screen works with windows, not nesscery to run game
				display();//displayed updated board
			}
		}
		system("cls");// clears the screen
		display();
		if (charsPlaced == 42) {//if draw
			cout << "No winner, Game was draw\n";
			cout << "Would you like to play again? (Y/N): " << endl;
			cin >> input;
			if (input == "Y" || input == "y")
				goto rerun;
			else
				return 0;
		}
		if (player == 2)//if won by player 2
			cout << "gamewon by : player 2\n";
		else cout << "gamewon by : player 1\n";//Else won by player 1
		cout << "Would you like to play again? (Y/N): " << endl;
		cin >> input;
		if (input == "Y" || input == "y")
			goto rerun;
		else
			return 0;//Exit application
}

void display() {
	cout << " 1   2   3   4   5   6   7\n";
	for (int a = 0; a <= 5; a++)
	{
		for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(179) << place[a][b] << char(179) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";
		cout << '\n';
	}
}
bool check(int a, int b) {
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = place[a][b];
	int i;//vertical
	int ii;//horizontal
	//check for vertical(|)
	for (i = a + 1; place[i][b] == player && i <= 5; i++, vertical++);//Check down
	for (i = a - 1; place[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	//check for horizontal(-)
	for (ii = b - 1; place[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left
	for (ii = b + 1; place[a][ii] == player && ii <= 6; ii++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for (i = a - 1, ii = b - 1; place[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left
	for (i = a + 1, ii = b + 1; place[i][ii] == player && i <= 5 && ii <= 6; diagonal1++, i++, ii++);//down and right
	if (diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for (i = a - 1, ii = b + 1; place[i][ii] == player && i >= 0 && ii <= 6; diagonal2++, i--, ii++);//up and right
	for (i = a + 1, ii = b - 1; place[i][ii] == player && i <= 5 && ii >= 0; diagonal2++, i++, ii--);//up and left
	if (diagonal2 >= 4) return true;
	return false;
}
int drop(int b, char player) {
	if (b >= 0 && b <= 6)
	{
		if (place[0][b] == ' ') {
			int i;
			for (i = 0; place[i][b] == ' '; i++)
				if (i == 5) {
					place[i][b] = player;
					return i;
				}
			i--;
			place[i][b] = player;
			return i;

		}
		else {
			return -1;
		}

	}
	else {
		return -1;
	}

}