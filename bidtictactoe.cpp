#include <iostream>

using namespace std;

void board(int player1, int player2);
char piece(int x);
int win();
void move(int *player1, int *player2, int player1bid, int player2bid);

int boardLoc[10] ={5,6,7,8,9,10,11,12,13,14};

int main(int argc, char const *argv[])
{
	int z = 0;
	int player1 = 100, player2 = 100;
	int player1bid,player2bid;
	board(player1,player2);
	
	//The Game 
	while(z == 0){
		cout << "Player 1's bid: ";
		cin >> player1bid;
		cout << "Player 2's bid: ";
		cin >> player2bid;
		move(&player1,&player2,player1bid,player2bid);
		
		board(player1,player2);
		z = win();
		if (player2 < 0){
			z = 1;
		}
		else if (player1 < 0) {
			z = 2;
		}
	}

	//Prints out result to screen
	if (z==-1){
		cout << "Sorry it was a tie" << endl;
	}
	else{
		if(z == 2){
			cout << "Player 2 Won" << endl;
		}
		else{
			cout << "Player 1 won" << endl;
		}
	}
	string response;
	cout << "Do you want to play again?";
	cin >> response;
	if (response == "Yes"|| response == "yes"){
		system("tictactoe");
	}
	return 0;
}
void move(int *player1, int *player2, int player1bid, int player2bid){
	//Determines whos move it is
	//if players move has already be taken prompts for another move
	// also transfer winning players bid to loser
	int choice;
	if(player2bid > player1bid){
			cout << "It's O's turn. What position do you want (1-9)?: ";
			cin >> choice;
		}
		else{
			cout << "It's X's turn. What position do you want (1-9)?: ";
			cin >> choice;
		}
	if ( choice < 0||choice > 9|| boardLoc[choice] == 2 || boardLoc[choice] == 1 ){
		cout << "You can't make that move\n";
		move(player1,player2,player1bid,player2bid);
	}
	else{
		boardLoc[choice] = player1bid > player2bid ? 1:2;
		if (player1bid>player2bid){
			*player1 -= player1bid;
			*player2 += player1bid;
		}
		else{
			*player2 -= player2bid;
			*player1 += player2bid;
		}
	}
	
}
void board(int player1, int player2){
	//clears last board
	//creates board with current pieces

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << "    	  "<<player1<< " -  "<<player2<<endl;
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
	// if it returns 1 player one won if 2 player two won
	// 0 means game is still in progress
	// -1 means tie game
	if (boardLoc[1] == boardLoc[2] && boardLoc[2] == boardLoc[3]){
		return boardLoc[2];
	}
	else if (boardLoc[4] == boardLoc[5] && boardLoc[5] == boardLoc[6]){
		return boardLoc[5];
	}
	else if (boardLoc[7] == boardLoc[8] && boardLoc[8] == boardLoc[9]){
		return boardLoc[8];
	}
	else if (boardLoc[1] == boardLoc[4] && boardLoc[4] == boardLoc[7]){
		return boardLoc[4];
	}
	else if (boardLoc[2] == boardLoc[5] && boardLoc[5] == boardLoc[8]){
		return boardLoc[5];
	}
	else if (boardLoc[3] == boardLoc[6] && boardLoc[6] == boardLoc[9]){
		return boardLoc[6];
	}
	else if (boardLoc[1] == boardLoc[5] && boardLoc[5] == boardLoc[9]){
		return boardLoc[5];
	}
	else if (boardLoc[3] == boardLoc[5] && boardLoc[5] == boardLoc[7]){
		return boardLoc[5];
	}
	else if (boardLoc[1] != 6 && boardLoc[2] != 7 && boardLoc[3] != 8 && boardLoc[4] != 9 && boardLoc[5] != 10 && boardLoc[6] != 11 && boardLoc[7] != 12 && boardLoc[8] != 13 && boardLoc[9] != 14 ){
		return -1;
	}
	else{
		return 0;
	}
}
