#include "animals.h"
int main() {	
	int bSize, c1c,  c1r,  c2c,  c2r,n;
	string name, *commands,*how;
	cout << "Enter borad size (Between 9 and 12 inclusively)\n";
	cin >> bSize;
	myBoard b1(bSize);
	b1.setBoard(c1c,c1r,c2c,c2r);
	cout << "Enter number of animals\n";
	cin >> n;
	animal* p;
	p = new animal[n];
	animal A;

	string Aname;
	int Arow, Acol;
	for (int i = 0; i < n; i++) {
		cout << "Enter the data of animal " << i + 1<<"\t(Positions start from row 0 and column 0)"<<endl;		
		cout << "Animal name: ";
		cin >> Aname;
		cout << "Animal row: ";
		cin >> Arow;
		//			p[i].row--;
		cout << "Animal column: ";
		cin >> Acol;
		//			p[i].col--;
		cout << endl;
		p[i] = animal(Aname,Arow,Acol);
	}
	
	//	b1.getBoard();
	
	commands = new string[n];
	ifstream test;
	test.open("samples.txt");
	if (!test.is_open())
		cout << "Error while opening the samples file\n";
	else
		for (int i = 0; i < n&&test.good();i++) {
			getline(test, commands[i]);
		}
	A.move(p,commands, n, c1c, c1r, c2c, c2r, bSize);
	A.results(p, n);	
	return 0;
}