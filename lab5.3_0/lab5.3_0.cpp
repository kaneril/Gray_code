// lab5.3_0.cpp: определяет точку входа для консольного приложения.
//
/*11. По номеру слова в коде  Грея  выдать  соответствующее
слово. По слову кода Грея определить его порядковый номер.*/

#include "stdafx.h"
void number_to_word();
void word_to_number();

int main()
{
	//Подключаем русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char i = ' ';
	while (i != '3')
	{
		printf_s("\n**************************");
		printf("\nВыберите действие:\n1 По номеру слова в коде  Грея  выдать  соответствующее слово\n2 По слову кода Грея определить его порядковый номер\n3 Завершить сеанс\n");
		printf_s("Укажите код выбранного действия: ");
		i = _getche();
		switch (i)
		{
		case '1':
			number_to_word();
			break;
		case '2':
			word_to_number();
			break;
		case '3':
			exit(0);
		default:
			printf_s("\nВведен неверный код действия\n");
			break;
		}
	}
    return 0;
}

void number_to_word()
{
	int m = 0;
	printf_s("\nВведите размерность кода Грея: ");
	scanf_s("%d", &m);
	int number = 0;
	printf_s("Введите номер слова в коде Грея: ");
	scanf_s("%d", &number);
	if ((number < 0) || (number > pow(2,m) - 1))
	{
		printf_s("Введен неверный номер слова\n");
	}
	else
	{
		int word = 0;
		word = number ^ (number >> 1);
		int i= pow(2, m-1);
		while ( i != 0)
		{
			if (word & i)
			{
				printf_s("1");
			}
			else
			{
				printf_s("0");
			}
			i = i >> 1;
		}
	}

}

void word_to_number()
{
	printf_s("\nВведите слово кода Грея: ");
	int word = 0;
	int c = ' ';
	int m = 0;
	while ((c = _getche())!=13)
	{
		m++;
		word = word << 1;
		if (c == '1')
		{
			word = word | 1;
		}		
	}
	int number = word;
	for (int i = 1; i < m; i = i << 1)
	{
		number = number ^ (number >> i);
	}
	printf_s("\n%d", number);
}