#include <iostream>

using namespace std;
/*
Leia Num1, Num2
Media <- (Num1 + Num2)/2 
Escreva Media
*/

float Num1, Num2, Media;
int main () {
	setlocale (LC_ALL,"Portuguese");
	
	//Entrada
	cout << "Forne�a o primeiro n�mero: ";
	cin >> Num1;
	
	cout << "Forne�a o segundo n�mero: ";
	cin >> Num2;
	
	//Processamento
	Media = (Num1 + Num2)/2; 
	
	//Sa�da
	cout << "A m�dia �: " << Media << endl;
	
	system("pause");
	
	return 0;
}

