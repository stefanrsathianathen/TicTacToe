#include <iostream>

using namespace std;

void board();
char piece(int x);
int win();
void move(int c);

int boardLoc[10] ={5,6,7,8,9,10,11,12,13,14};

int main(int argc, char const *argv[])
{
	int z = 0;
	int turn = 1;
	board();
	
	//The Game 
	while(z == 0){
		move(turn%2);
		turn++;
		board();
		z = win();
	}

	//Prints out result to screen
	if (z==-1){
		cout << "Sorry it was a tie";
	}
	else{
		if((turn-1)%2 == 0){
			cout << "Player 2 Won";
		}
		else{
			cout << "Player 1 won";
		}
	}
	return 0;
}
void move(int c){
	//Determines whos move it is
	//if players move has already be taken prompts for another move
	int choice;
	if(c==0){
			cout << "It's O's turn. What position do you want (1-9)?: ";
			cin >> choice;
		}
		else{
			cout << "It's X's turn. What position do you want (1-9)?: ";
			cin >> choice;
		}
	if (choice < 0||choice > 9||boardLoc[choice] == 2 || boardLoc[choice] == 1 ){
		cout << "You can't make that move\n";
		move(c);
	}
	else{
		boardLoc[choice] = c==0 ? 2:1;
	}
	
}
void board(){
	//clears last board
	//creates board with current pieces

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	
	cout << "     |     |     " << endl;
	cout << "  " << piece(boardLoc[1])<< "  |  " << piece(boardLoc[2])<< "  |  " << piece(boardLoc[3]) << endl;
	cout << "_____|_____|_____" << endl;
	
	cout << "     |     |     " << endl;
	cout << "  " << piece(boardLoc[4])<< "  |  " << piece(boardLoc[5])<< "  |  " << piece(boardLoc[6]) << endl;
	cout << "_____|_____|_____" << endl;
	
	cout << "     |     |     " << endl;
	cout << "  " << piece(boardLoc[7])<< "  |  " << piece(boardLoc[8])<< "  |  " << piece(boardLoc[9]) << endl;
	cout << "     |     |     " << endl;
	
}

char piece(int x){
	//Converts pieces into the respective piece for the board
	if (x==1){
		return 'X';
	}
	else if (x == 2){
		return 'O';
	}
	else{
		return '-';
	}
}

int win(){
	//Logic to check if game is over
	// 1 means a player has won
	// 0 means game is still in progress
	// -1 means tie game
	if (boardLoc[1] == boardLoc[2] && boardLoc[2] == boardLoc[3]){
		return 1;
	}
	else if (boardLoc[4] == boardLoc[5] && boardLoc[5] == boardLoc[6]){
		return 1;
	}
	else if (boardLoc[7] == boardLoc[8] && boardLoc[8] == boardLoc[9]){
		return 1;
	}
	else if (boardLoc[1] == boardLoc[4] && boardLoc[4] == boardLoc[7]){
		return 1;
	}
	else if (boardLoc[2] == boardLoc[5] && boardLoc[5] == boardLoc[8]){
		return 1;
	}
	else if (boardLoc[3] == boardLoc[6] && boardLoc[6] == boardLoc[9]){
		return 1;
	}
	else if (boardLoc[1] == boardLoc[5] && boardLoc[5] == boardLoc[9]){
		return 1;
	}
	else if (boardLoc[3] == boardLoc[5] && boardLoc[5] == boardLoc[7]){
		return 1;
	}
	else if (boardLoc[1] != 6 && boardLoc[2] != 7 && boardLoc[3] != 8 && boardLoc[4] != 9 && boardLoc[5] != 10 && boardLoc[6] != 11 && boardLoc[7] != 12 && boardLoc[8] != 13 && boardLoc[9] != 14 ){
		return -1;
	}
	else{
		return 0;
	}
}
