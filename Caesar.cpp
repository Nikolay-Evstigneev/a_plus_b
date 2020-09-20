#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string line, otvet, command;
	char symbol;
	int sh;
	cout << "Введите шаг сдвига: ";
	cin >> sh;
	do
	{
		cout << "Введите encode для кодирования или decode для расшифровки: ";
		cin >> command;
		if (command == "decode")sh *= -1;

	} while ((command != "encode")and(command != "decode"));
	cout << "Введите строку: ";
	cin >> line;
	otvet.resize(line.length());
	for (int i = 0; i < line.length(); i++)
	{
		if ((line[i] > 96) and (line[i] < 123))
		{
			symbol = line[i] += sh;
			symbol = char(97 + (26 * (1 - (symbol / 97))) + ((symbol - 97) % 26));
			otvet[i] = symbol;
		}
		else if ((line[i] > 64) and (line[i] < 91)) {
			symbol = line[i] += sh;
			symbol = char(64 + (26 * (1 - (symbol / 64))) + ((symbol - 64) % 26));
			otvet[i] = symbol;
		}

		else 
		{
			otvet[i] = line[i];
		}
	}
	cout << "Oтвет: " << otvet;

}
