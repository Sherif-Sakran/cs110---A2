#include "animals.h"

animal::animal() {
	name = "No name";
	row = 0;
	col = 0;
}

	animal::animal(string n, int r, int c) {
		this->row = r;
		this->col = c;
		this->name = n;
	}
	void animal::move(animal* p, string buttons[], int n, int c1c, int  c1r, int  c2c, int c2r, int bSize) // n is number of animals and also the number of strings
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
			{
				if (buttons[i][j] == 'U' || buttons[i][j] == 'u')
					--p[i].row;
				else if (buttons[i][j] == 'D' || buttons[i][j] == 'd')
					++p[i].row;
				else if (buttons[i][j] == 'R' || buttons[i][j] == 'r')
					++p[i].col;
				else if (buttons[i][j] == 'L' || buttons[i][j] == 'l')
					--p[i].col;
				else
					cout << "Wrong input\n";

				if (setState(p, i, c1c, c1r, c2c, c2r, bSize) == true)
					break;
			}
	}
	bool animal::setState(animal* p, int th, int c1c, int  c1r, int  c2c, int c2r, int bSize) {
		if ((p[th].row == c1r && p[th].col == c1c) || (p[th].row == c2r && p[th].col == c2c))
		{
			p[th].state = "Eaten by the cat.";
			return true;
		}
		else if (((bSize % 2) && (p[th].row == bSize / 2) && (p[th].col == bSize - 1)) || ((bSize % 2 == 0) && (p[th].row == bSize / 2 - 1) && (p[th].col == bSize - 1)))
		{
			p[th].state = "Escaped through the bridge.";
			return true;
		}
		else if (p[th].row > bSize - 1 || p[th].col > bSize - 1 || p[th].row < 0 || p[th].col < 0)
		{
			p[th].state = "Drowned outside the island.";
			return true;
		}
		else
		{
			p[th].state = "Starved... Stuck inside the board.";
			return false;
		}

	}
	void animal::results(animal* p, int n)
	{
		cout << "Results:\n";
		for (int i = 0; i < n; i++)
			cout << p[i].name << ": " << p[i].state << endl;
	}

	myBoard::myBoard(int& i) {
		if (i >= 9 && i <= 12)
			boardSize = i;
		else
		{
			do {
				cout << "Invalid input. Please enter a size between 9 and 12\n";
				cin >> i;
			} while (i < 9 || i>12);
			boardSize = i;
		}
		board = new char* [boardSize];
		for (int i = 0; i < boardSize; i++)
			board[i] = new char[boardSize];
		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				board[i][j] = '-';
	}
	void myBoard::setBoard(int& c1c, int& c1r, int& c2c, int& c2r) {
		setCat(c1c, c1r, c2c, c2r);
		while ((c1c > boardSize || c1r > boardSize || c2c > boardSize || c2r > boardSize) || (c1c == c2c && c1r == c2r))
		{
			cout << "Invalid positions. Note that two cats cannot have the same position, and positions cannot be outside the board\n";
			setCat(c1c, c1r, c2c, c2r);
		}
		board[c1r][c1c] = 'c';
		board[c2r][c2c] = 'c';
		if (boardSize % 2)
			board[boardSize / 2][boardSize - 1] = 'B';
		else
			board[boardSize / 2 - 1][boardSize - 1] = 'B';
	}
	void myBoard::getBoard() {
		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
				cout << board[i][j] << " ";
			cout << endl;
		}
	}
	void myBoard::setCat(int& c1c, int& c1r, int& c2c, int& c2r) {
		cout << "Positions start from row 0 and column 0\n";
		cout << "Enter Cat 1 row\n";
		cin >> c1r;
		cout << "Enter Cat 1 column\n";
		cin >> c1c;
		cout << "Enter Cat 2 row\n";
		cin >> c2r;
		cout << "Enter Cat 2 column\n";
		cin >> c2c;
	}