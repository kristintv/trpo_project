#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Wait (int seconds) { //Функция ожидания
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait) {}
}

void PrintLogo() {
	system("clear");
	// Лого
}

void PrintRules() {
	PrintLogo();
	// Правила
}

void PrintDifficulty(char difficulty) {
	switch(difficulty) {
		case '1': {
			printf("Choosen difficulty - Easy (4 numbers)\n");
			break;
		}
		case '2': {
			printf("Choosen difficulty - Medium (5 numbers)\n");
			break;
		}
		case '3': {
			printf("Choosen difficulty - Hard (6 numbers)\n");
			break;
		}
	}
}

void Menu(char *flag) {
	do {
		PrintLogo();
		printf("\n\n");
		printf("\t\t\t\t1.One player\n");
		printf("\t\t\t\t2.Two players\n");
		printf("\t\t\t\t3.Game Rules\n");
		printf("\t\t\t\t4.Difficulty\n");
		printf("\t\t\t\t0.Exit\n");
		printf("\t\t\t\tChoose:");
		scanf("%c", flag);
		if (*flag == '0')
			break;
	} while ((*flag < '1') || (*flag > '4'));
}

void GameRules() {
	int tmp = 1;
	do {
		PrintRules();
		scanf("%d", &tmp);
	} while (tmp != 0);
}

void MenuDifficulty(char *difficulty) {
	do {
		PrintLogo();
		printf("\n\n");
		printf("\t\t\t\t1.Easy   (4 numbers)\n");
		printf("\t\t\t\t2.Medium (5 numbers)\n");
		printf("\t\t\t\t3.Hard   (6 numbers)\n");
		printf("\t\t\t\tChoose:");
		scanf("%c", difficulty);
	} while ((*difficulty < '1') || (*difficulty > '3'));
}

void PrintFieldPlayerOne(int attempt, int attemptNumber[], int cows[], int bulls[]) {
	PrintLogo();
	printf("\tN\t Attempt\tCows\t Bulls\t\n");
	for (int i = 0; i < attempt; ++i) {
		printf("%7d\t", i+1);
		printf("%7d\t", attemptNumber[i]);
		printf("%7d\t", cows[i]);
		printf("%7d\t", bulls[i]);
		printf("\n");
	}
}

void PlayerOne(char difficulty) {
	system("clear");
	PrintDifficulty(difficulty);
	Wait(3);
	system("clear");
	
	int range; //Диапазон - 4х-, 5и-, 6и-значное число
	long int rangeMin, rangeMax; // Минимальное и максимальное допустимое вводимое значение
	long int attemptNumber = 0; //Попытка
	int bulls, cows;
	int flag; 
	int tmpCows[10]; //Запоминаем предыдущие значения коров, быков, попыток
	int tmpBulls[10];
	int tmpAttemptNumber[10];
	//Проверка на сложность
	if (difficulty == '1') {
		range = 4;
		rangeMin = 1000;
		rangeMax = 9999;
	}
	else if (difficulty == '2') {
		range = 5;
		rangeMin = 10000;
		rangeMax = 99999;
	}
	else {
		range = 6;
		rangeMin = 100000;
		rangeMax = 999999;
	}
	int attemptNumberMas[range]; //Попытка, разделенная на массив поразрядно
	int targetNumber[range]; //Загаданное число

	
	//Загадываем число
	printf("Guessing number...\n");
	int i = 1;
	targetNumber[0] = 1 + rand() %9;
	while (i < range) {
		flag = 0;
		targetNumber[i] = rand() %10;
		for (int j = i-1; j >= 0; --j)
			if (targetNumber[j] == targetNumber[i])
				flag = 1;
		if (flag != 1) ++i;
	}
	for (int i = 0; i < range; ++i)
		printf("%d", targetNumber[i]);
	Wait(rand() % 5);
	system("clear");
	
	//Процесс игры
	for (int attempt = 1; attempt < 10; ++attempt) {
		bulls = 0;
		cows = 0;
		flag = 1;
		//Считываем число, проверяем его и делим в массив
		while (flag) {
			flag = 0;
			printf("Guess number:");
			scanf("%ld", &attemptNumber);
			if (attemptNumber < rangeMin 
				|| attemptNumber > rangeMax)
				flag = 1;
			tmpAttemptNumber[attempt - 1] = attemptNumber;
			for (i = 0; i < range; ++i) {
				attemptNumberMas[range-i-1] = attemptNumber % 10;
				attemptNumber /= 10;
			}
			for (i = range - 1; i >= 1; --i)
				for (int j = i-1; j >= 0; --j)
					if (attemptNumberMas[i] == attemptNumberMas[j])
						flag = 1;
		}

		//Считаем быков
		for (int i = 0; i < range; ++i) {
			if (attemptNumberMas[i] == targetNumber[i]){
				bulls++;
			}
		}
		//Считаем коров
		for (int i = 0; i < range; ++i) {
			for (int j = 0; j < range; ++j)
				if (attemptNumberMas[i] == targetNumber[j])
					cows++;
		}
		cows -= bulls;

		//быки - на своих местах
		//коровы - угаданные числа
		tmpCows[attempt - 1] = cows;
		tmpBulls[attempt - 1] = bulls;
		PrintFieldPlayerOne(attempt, tmpAttemptNumber, tmpCows, tmpBulls);
		if (bulls == range) {
			printf("\nYou win!\n");
			Wait(3);
			break;
		}
		
	}
	system("PAUSE");
}

void PlayerTwo(char difficulty) {}/*
	system("clear");
	PrintDifficulty(difficulty);
	Wait(3);
	system("clear");

	int range; //Диапазон - 4х-, 5и-, 6и-значное число
	long int rangeMin, rangeMax; // Минимальное и максимальное допустимое вводимое значение
	long int attemptNumber = 0; //Попытка
	int bulls[2]; 
	int cows[2]; 
	int flag[2]; 
	int tmpCows[10][2]; //Запоминаем предыдущие значения коров, быков, попыток
	int tmpBulls[10][2];
	int tmpAttemptNumber[10][2];
	//Проверка на сложность
	if (difficulty == '1'){
		range = 4;
		rangeMin = 1000;
		rangeMax = 9999;
	}
	else if (difficulty == '2'){
		range = 5;
		rangeMin = 10000;
		rangeMax = 99999;
	}
	else {
		range = 6;
		rangeMin = 100000;
		rangeMax = 999999;
	}
	int attemptNumberMas[range]; //Попытка, разделенная на массив поразрядно
	long int targetNumberMas[range][2]; //Загаданное число
	long int targetNumberOne;
	long int targetNumberTwo;
	while (flag){
		system("clear");
		flag = 0;
		printf("First player input his number:");
		scanf("%ld", &targetNumber);
		if (targetNumberOne < rangeMin || targetNumberOne > rangeMax)
			flag = 1;
		for (i = 0; i < range; ++i){
			targetNumberMas[range-i-1][0] = targetNumberOne % 10;
			targetNumberOne /= 10;
		}
		for (i = range - 1; i >= 1; --i)
			for (int j = i-1; j >= 0; --j)
				if (targetNumberMas[i][0] == targetNumberMas[j][0])
					flag = 1;
	}
	while (flag){
		system("clear");
		flag = 0;
		printf("Second player input his number:");
		scanf("%ld", &targetNumber);
		if (targetNumberTwo < rangeMin || targetNumberTwo > rangeMax)
			flag = 1;
		for (i = 0; i < range; ++i){
			targetNumberMas[range-i-1][1] = targetNumberTwo % 10;
			targetNumberTwo /= 10;
		}
		for (i = range - 1; i >= 1; --i)
			for (int j = i-1; j >= 0; --j)
				if (targetNumberMas[i][1] == targetNumberMas[j][1])
					flag = 1;
	}
	
	//Процесс игры
	for (int attempt = 1; attempt < 10; ++attempt){
		bulls = 0;
		cows = 0;
		flag = 1;
		//Считываем число, проверяем его, и делим в массив
		while (flag){
			flag = 0;
			printf("Guess number:");
			scanf("%ld", &attemptNumber);
			if (attemptNumber < rangeMin || attemptNumber > rangeMax)
				flag = 1;
			tmpAttemptNumber[attempt - 1] = attemptNumber;
			for (i = 0; i < range; ++i){
				attemptNumberMas[range-i-1] = attemptNumber % 10;
				attemptNumber /= 10;
			}
			for (i = range - 1; i >= 1; --i)
				for (int j = i-1; j >= 0; --j)
					if (attemptNumberMas[i] == attemptNumberMas[j])
						flag = 1;
		}

		//Считаем быков
		for (int i = 0; i < range; ++i){
			if (attemptNumberMas[i] == targetNumber[i]){
				bulls++;
			}
		}
		//Считаем коров
		for (int i = 0; i < range; ++i){
			for (int j = 0; j < range; ++j)
				if (attemptNumberMas[i] == targetNumber[j])
					cows++;
		}
		cows -= bulls;

		//быки - на своих местах
		//коровы - угаданные числа
		tmpCows[attempt - 1] = cows;
		tmpBulls[attempt - 1] = bulls;
		PrintFieldPlayerOne(attempt, tmpAttemptNumber, tmpCows, tmpBulls);
		if (bulls == range){
			printf("\nYou win!\n");
			break;
		}
		
	}
	system("PAUSE");
}*/

int main(int argc, char *argv[]) {
	srand(time(NULL));
	char flag;
	char difficulty = '3';
	while(1) {
		Menu(&flag);
		switch(flag) {
			case '1': {
				PlayerOne(difficulty);
				break;
			}
			case '2': {
				PlayerTwo(difficulty);
				break;
			}
			case '3': {
				GameRules();
				break;
			}
			case '4': {
				MenuDifficulty(&difficulty);
				break;
			}
			case '0': {
				return 0;
			}
		}
	}
}
