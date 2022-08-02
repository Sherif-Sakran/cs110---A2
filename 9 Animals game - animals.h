#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class animal {
private:
	int row;
	int col;
	string name;
	string state;
public:
	animal();

	animal(string n, int r, int c);
	void move(animal* p, string buttons[], int n, int c1c, int  c1r, int  c2c, int c2r, int bSize);
	bool setState(animal* p, int th, int c1c, int  c1r, int  c2c, int c2r, int bSize);
	void results(animal* p, int n);
};
class myBoard {
private:
	int boardSize;
	char** board;
public:
	myBoard(int& i);
	void setBoard(int& c1c, int& c1r, int& c2c, int& c2r);
	void getBoard();
	void setCat(int& c1c, int& c1r, int& c2c, int& c2r);
};