#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void CleanMirror();
void PlayGame(int lifes);
void Draw(int lifes);
string words[] = {"programador","videojuego","manzana","gachapon","libro","jugador","codigo","lampara","pelota","lobo"};
string number[] = {"0","1","2","3","4","5","6","7","8","9"};
string wordP , fallidas; 
char select;
int random;

bool correct, complete;
int main()
{
	int lifes = 6;
	while (true){
		
		
		wordP = "";
		fallidas = "";
		CleanMirror();
		cout << "Menu" << endl;
		cout << "Welcome, Welcome, what would you like to do? \n1)Play a game \n2)Exit" << endl;
		cin >> select;
		switch (select) {
		case '1':
			PlayGame(lifes);
			break;
		case '2':
			cout << "combe back soon" << endl;
			return 0;
			break;
		}
	}
}

void PlayGame(int lifes)
{
	CleanMirror();
	srand((int)time(NULL));
	random = rand() % 10;
	for (int i = 0; i < (int)words[random].size(); i++) {
		wordP += "-";
	}
	while (lifes != 0) {
		CleanMirror();
		do {
			CleanMirror();
			cout << "AHORCADO" << endl;
			Draw(lifes);
			cout << "failed: " << fallidas;
			cout << "  Progress " << wordP << endl;
			cout << words[random] << endl;
			cout << "enter a letter(las palabra estan en español y en minusculas): ";
			cin >> select;
		} while (number->find(select));
		correct = false;
		for (int i = 0; i < (int)words[random].size(); i++) {
			if (words[random][i]==select) {
				wordP[i] = select;
				correct = true;
			}
		}
		if (!correct) {
			lifes--;
			fallidas += select;
		}

		complete = true;
		for (int i = 0; i < (int)wordP.size(); i++) {
			if (wordP[i] == '-') {
				complete = false;
			}
		}
		if (complete) {
			CleanMirror();
			cout << "AHORCADO" << endl;
			Draw(lifes);
			cout << "Word: " << words[random] << endl;
			cout << "YOU WIN... enter a letter for continue: ";
			cin >> select;
			lifes = 6;
			return;
		}
		
	} 
	CleanMirror();
	cout << "AHORCADO" << endl;
	Draw(lifes);
	cout << "Word: " << words[random] << endl;
	cout << "YOU LOSE... enter a letter for continue: ";
	cin >> select;
	lifes = 6;
	return;
}

void Draw(int lifes)
{
	switch (lifes) {
	case 6:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	case 5:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	case 4:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	case 3:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |    /|" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break; 
	case 2:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |    /|\\" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	case 1:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |    /|\\" << endl;
		cout << "  |    /  " << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	case 0:
		cout << "  -------" << endl;
		cout << "  |     |" << endl;
		cout << "  |     O" << endl;
		cout << "  |    /|\\" << endl;
		cout << "  |    / \\" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << " ---" << endl;
		break;
	}
}

void CleanMirror()
{
	if (system("cls") == -1) {
		cout << "sorry, this is not option" << endl;
	}
}