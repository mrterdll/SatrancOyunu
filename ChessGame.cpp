#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include<iomanip>
using namespace std;

class CheesGame {
private:
	const double p = 1;
	const double a = 3;
	const double f = 3;
	const double k = 5;
	const double v = 9;
	const double s = 100;
	
public:
	void printBoard(string arr[8][8]);
	void printBoard(bool arr[8][8]);
	double* getScore(string arr[8][8]);
	bool isValid(int x, int y);
};

bool CheesGame::isValid(int x,int y){
	//Gönderilen konumun oyun tahtası üzerinde olup olmadığı kontrol edilir.
	if(x>=0 && x<8 && y>=0 && y<8){
		return true;
	}
	return false;
}

double * CheesGame::getScore(string arr[8][8]) {
	//Oyun tahtasının genel skoru hesaplanır.
	double* score = new double[2];
	score[0] = 0;
	score[1] = 0;
	bool pointField[8][8] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Mevcut elemanın ismi kontrol edilir.
			string temp = arr[i][j];
			char first = temp[0];
			char second = temp[1];
			//Piyon için skor hesaplanır.
			if (first == 'p') {
				if(second == 's') {					
					score[0] += p;
					//Siyah piyon tarafından tehdit edilen taşlar belirlenir.
					if(arr[i + 1][j + 1] != "--" && isValid(i + 1, j + 1)) {
						string temp = arr[i + 1][j + 1];
						char second = temp[1];
						if(second == 'b' && pointField[i + 1][j + 1] == false) {
							pointField[i + 1][j + 1] = true;
						}
					}
					if (arr[i + 1][j - 1] != "--" && isValid(i + 1, j - 1)) {
						string temp = arr[i + 1][j - 1];
						char second = temp[1];
						if (second == 'b' && pointField[i + 1][j - 1] == false) {
							pointField[i + 1][j - 1] = true;
						}
					}
				}
				else if (second == 'b') {
					score[1] += p;
					//Beyaz piyon tarafından tehdit edilen taşlar belirlenir.
					if (arr[i - 1][j - 1] != "--" && isValid(i - 1, j - 1)) {
						string temp = arr[i - 1][j - 1];
						char second = temp[1];
						if (second == 's' && pointField[i - 1][j - 1] == false) {
							pointField[i - 1][j - 1] = true;
						}
					}
					else if (arr[i - 1][j + 1] != "--" && isValid(i - 1,j + 1)) {
						string temp = arr[i - 1][j + 1];
						char second = temp[1];
						if (second == 's' && pointField[i - 1][j + 1] == false) {
							pointField[i - 1][j + 1] = true;
						}
					}
				}
			}
			//At için skor hesaplanır.
			else if (first == 'a') {
				if (second == 's') {
					score[0] += a;
					//Siyah at tarafından tehdit edilen taşlar belirlenir.
					if (arr[i - 2][j - 1] != "--" && isValid(i - 2, j - 1)) {
						string temp = arr[i - 2][j - 1];
						char second = temp[1];
						if (second == 'b' && pointField[i - 2][j - 1] == false) {
							pointField[i - 2][j - 1] = true;
						}
					}
					if (arr[i - 2][j + 1] != "--" && isValid(i - 2, j + 1)) {
						string temp = arr[i - 2][j + 1];
						char second = temp[1];
						if (second == 'b' && pointField[i - 2][j + 1] == false) {
							pointField[i - 2][j + 1] = true;
						}
					}
					if (arr[i - 1][j - 2] != "--" && isValid(i - 1, j - 2)) {
						string temp = arr[i - 1][j - 2];
						char second = temp[1];
						if (second == 'b' && pointField[i - 1][j - 2] == false) {
							pointField[i - 1][j - 2] = true;
						}
					}
					if (arr[i - 1][j + 2] != "--" && isValid(i - 1, j + 2)) {
						string temp = arr[i - 1][j + 2];
						char second = temp[1];
						if (second == 'b' && pointField[i - 1][j + 2] == false) {
							pointField[i - 1][j + 2] = true;
						}
					}
					if (arr[i + 2][j - 1] != "--" && isValid(i + 2, j - 1)) {
						string temp = arr[i + 2][j - 1];
						char second = temp[1];
						if (second == 'b' && pointField[i + 2][j - 1] == false) {
							pointField[i + 2][j - 1] = true;
						}
					}
					if (arr[i + 2][j + 1] != "--" && isValid(i + 2, j + 1)) {
						string temp = arr[i + 2][j + 1];
						char second = temp[1];
						if (second == 'b' && pointField[i + 2][j + 1] == false) {
							pointField[i + 2][j + 1] = true;
						}
					}
					if (arr[i + 1][j - 2] != "--" && isValid(i + 1, j - 2)) {
						string temp = arr[i + 1][j - 2];
						char second = temp[1];
						if (second == 'b' && pointField[i + 1][j - 2] == false) {
							pointField[i + 1][j - 2] = true;
						}
					}
					if (arr[i + 1][j + 2] != "--" && isValid(i + 1, j + 2)) {
						string temp = arr[i + 1][j + 2];
						char second = temp[1];
						if (second == 'b' && pointField[i + 1][j + 2] == false) {
							pointField[i + 1][j + 2] = true;
						}
					}
				}
				else if (second == 'b') {
					score[1] += a;
					//Beyaz at tarafından tehdit edilen taşlar belirlenir.
					if (arr[i - 2][j - 1] != "--" && isValid(i - 2, j - 1)) {
						string temp = arr[i - 2][j - 1];
						char second = temp[1];
						if (second == 's' && pointField[i - 2][j - 1] == false) {
							pointField[i - 2][j - 1] = true;
						}
					}
					if (arr[i - 2][j + 1] != "--" && isValid(i - 2, j + 1)) {
						string temp = arr[i - 2][j + 1];
						char second = temp[1];
						if (second == 's' && pointField[i - 2][j + 1] == false) {
							pointField[i - 2][j + 1] = true;
						}
					}
					if (arr[i - 1][j - 2] != "--" && isValid(i - 1, j - 2)) {
						string temp = arr[i - 1][j - 2];
						char second = temp[1];
						if (second == 's' && pointField[i - 1][j - 2] == false) {
							pointField[i - 1][j - 2] = true;
						}
					}
					if (arr[i - 1][j + 2] != "--" && isValid(i - 1, j + 2)) {
						string temp = arr[i - 1][j + 2];
						char second = temp[1];
						if (second == 's' && pointField[i - 1][j + 2] == false) {
							pointField[i - 1][j + 2] = true;
						}
					}
					if (arr[i + 2][j - 1] != "--" && isValid(i + 2, j - 1)) {
						string temp = arr[i + 2][j - 1];
						char second = temp[1];
						if (second == 's' && pointField[i + 2][j - 1] == false) {
							pointField[i + 2][j - 1] = true;
						}
					}
					if (arr[i + 2][j + 1] != "--" && isValid(i + 2, j + 1)) {
						string temp = arr[i + 2][j + 1];
						char second = temp[1];
						if (second == 's' && pointField[i + 2][j + 1] == false) {
							pointField[i + 2][j + 1] = true;
						}
					}
					if (arr[i + 1][j - 2] != "--" && isValid(i + 1, j - 2)) {
						string temp = arr[i + 1][j - 2];
						char second = temp[1];
						if (second == 's' && pointField[i + 1][j - 2] == false) {
							pointField[i + 1][j - 2] = true;
						}
					}
					if (arr[i + 1][j + 2] != "--" && isValid(i + 1, j + 2)) {
						string temp = arr[i + 1][j + 2];
						char second = temp[1];
						if (second == 's' && pointField[i + 1][j + 2] == false) {
							pointField[i + 1][j + 2] = true;
						}
					}
				}
			}
			//Fil için skor hesaplanır.
			else if (first == 'f') {
				if (second == 's') {
					score[0] += f;
				}
				else if (second == 'b') {
					score[1] += f;
				}
			}
			//Kale  için skor hesaplanır.
			else if (first == 'k') {
				if (second == 's') {
					score[0] += k;
				}
				else if (second == 'b') {
					score[1] += k;
				}
			}
			//Vezir için skor hesaplanır.
			else if (first == 'v') {
				if (second == 's') {
					score[0] += v;
					//Siyah vezir tarafından tehdit edilen taşlar belirlenir.
					for (int k = i+1; k < 8; k++) {
						if (arr[k][j] != "--") {
							string temp = arr[k][j];
							char second = temp[1];
							if (second == 'b' && pointField[k][j] == false) {
								pointField[k][j] = true;
							}
							break;
						}
					}
					for (int k = i-1; k >=  0; k--) {
						if (arr[k][j] != "--") {
							string temp = arr[k][j];
							char second = temp[1];
							if (second == 'b' && pointField[k][j] == false) {
								pointField[k][j] = true;
							}
							break;
						}
					}
					for (int k = j+1; k < 8; k++) {
						if (arr[i][k] != "--") {
							string temp = arr[i][k];
							char second = temp[1];
							if (second == 'b' && pointField[i][k] == false) {
								pointField[i][k] = true;
							}
							break;
						}
					}
					for (int k = j-1; k >= 0; k--) {
						if (arr[i][k] != "--") {
							string temp = arr[i][k];
							char second = temp[1];
							if (second == 'b' && pointField[i][k] == false) {
								pointField[i][k] = true;
							}
							break;
						}
					}
					for (int k = i+1, l = j+1; k < 8 && l < 8; k++, l++) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 'b' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 'b' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i+1, l = j-1; k < 8 && l >= 0; k++, l--) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 'b' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i-1, l = j+1; k >= 0 && l < 8; k--, l++) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 'b' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
				}
				else if (second == 'b') {
					score[1] += v;					
					//Beyaz vezir tarafından tehdit edilen taşlar belirlenir.
					for (int k = i+1; k < 8; k++) {
						if (arr[k][j] != "--") {
							string temp = arr[k][j];
							char second = temp[1];
							if (second == 's' && pointField[k][j] == false) {
								pointField[k][j] = true;
							}
							break;
						}
					}
					for (int k = i-1; k >= 0; k--) {
						if (arr[k][j] != "--") {
							string temp = arr[k][j];
							char second = temp[1];
							if (second == 's' && pointField[k][j] == false) {
								pointField[k][j] = true;
							}
							break;
						}
					}
					for (int k = j+1; k < 8; k++) {
						if (arr[i][k] != "--") {
							string temp = arr[i][k];
							char second = temp[1];
							if (second == 's' && pointField[i][k] == false) {
								pointField[i][k] = true;
							}
							break;
						}
					}
					for (int k = j-1; k >= 0; k--) {
						if (arr[i][k] != "--") {
							string temp = arr[i][k];
							char second = temp[1];
							if (second == 's' && pointField[i][k] == false) {
								pointField[i][k] = true;
							}
							break;
						}
					}
					for (int k = i+1, l = j+1; k < 8 && l < 8; k++, l++) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 's' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 's' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i+1, l = j-1; k < 8 && l >= 0; k++, l--) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 's' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}
					for (int k = i-1, l = j+1; k >= 0 && l < 8; k--, l++) {
						if (arr[k][l] != "--") {
							string temp = arr[k][l];
							char second = temp[1];
							if (second == 's' && pointField[k][l] == false) {
								pointField[k][l] = true;
							}
							break;
						}
					}					
				}
			}
			//Şah için skor hesaplanır.
			else if (first == 's') {
				if (second == 's') {
					score[0] += s;
				}
				else if (second == 'b') {
					score[1] += s;
				}
			}
		}
	}	
	
	//Tehdit altında olan taşların puanları tekrar hesaplanır.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(pointField[i][j] == true)
			{
				string temp = arr[i][j];
				char first = temp[0];
				char second = temp[1];
				if (first == 'p') {
					if (second == 's') {
						score[0] -= p * 0.5;
					}
					else if (second == 'b') {
						score[1] -= p * 0.5;
					}
				}
				else if (first == 'a') {
					if (second == 's') {
						score[0] -= a * 0.5;
					}
					else if (second == 'b') {
						score[1] -= a * 0.5;
					}
				}
				else if (first == 'f') {
					if (second == 's') {
						score[0] -= f * 0.5;
					}
					else if (second == 'b') {
						score[1] -= f * 0.5;
					}
				}
				else if (first == 'k') {
					if (second == 's') {
						score[0] -= k * 0.5;
					}
					else if (second == 'b') {
						score[1] -= k * 0.5;
					}
				}
				else if (first == 'v') {
					if (second == 's') {
						score[0] -= v * 0.5;
					}
					else if (second == 'b') {
						score[1] -= v * 0.5;
					}
				}
				else if (first == 's') {
					if (second == 's') {
						score[0] -= s * 0.5;
					}
					else if (second == 'b') {
						score[1] -= s * 0.5;
					}
				}
			}
		}
	}
	//Tehdit altında olan taşların konumları ekrana bastırılır.
	printBoard(pointField);
		
	return score;
}

void CheesGame::printBoard(bool arr[8][8]) {
	cout << "---- Threatened Stones -----" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}	
}

void CheesGame::printBoard(string arr[8][8]) {
	cout << "---- Game Board -----" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	string board[8][8];	
	//Dosya okuma işlemleri yapılır.
	fstream boardFile;
	boardFile.open("board1.txt", ios::in);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			boardFile >> board[i][j];
		}
	}
	boardFile.close();
	
	CheesGame cg;
	cg.printBoard(board);
	double* score = cg.getScore(board);
	cout << fixed << "Black: " << setprecision(1) << score[0] << endl;
	cout << fixed << "White: " << setprecision(1) << score[1] << endl;
	delete[] score; //allocated memory must be deleted
				
	return 0;
}
