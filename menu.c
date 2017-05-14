#include <stdio.h>
#include <stdlib.h>

void Logo() {
	printf("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
 	printf("\t|B|U|L|L|S| |A|N|D| |C|O|W|S|\n");
 	printf("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
}

void Menu(int *item) {
 	system("clear");
 	Logo();
 	*item = 0;
	printf("\t\tWelcome to menu!\n");
	printf("\t\t1.Play\n\t\t2.Game rules\n\t\t3.Difficulty level\n\t\t4.Exit\n");
	printf("\tMenu item number: ");
	// Дописать выбор в меню
	scanf("%d", item);
	system("clear");
}

void GameRules() {
	system("clear");
	Logo();
	printf("\t\t  +-+-+-+-+-+\n");
 	printf("\t\t  |R|U|L|E|S|\n");
 	printf("\t\t  +-+-+-+-+-+\n");
 	printf("*Rules*\n");
 	int check = 0;
	printf("Input any symbol to back: ");
	scanf("%d", &check);
	system("clear");
	// Добавить правила
}

void DifficultyLVL(int *lvl) {
	system("clear");
	Logo();
	*lvl = 0;
	printf("You can choose the difficulty level!\n");
	printf("\t\t1.Easy (4 numbers)\n");
	printf("\t\t2.Medium (5 numbers)\n");
	printf("\t\t3.Hard (6 numbers)\n");
	printf("LVL (input number): ");
	scanf("%d", lvl);
	lvl = lvl + 3;
	system("clear");
}

void NumberOfPlayers(int *players) {
	system("clear");
	Logo();
	*players = 0;
	printf("Please, choose number of players: ");
	scanf("%d", players);
	system("clear");
}



void OnePlayer(int *lvl) {
	system("clear");
	if (*lvl == 0) DifficultyLVL(&*lvl);
	Logo();
	// Дописать загадывание числа
	printf("N\tAttempt\tCows\tBulls");
}

void Game(int *lvl, int *players) {
	if (*lvl == 0) DifficultyLVL(&*lvl);
	if (*players == 0) NumberOfPlayers(&*players);
	if (*players == 1) OnePlayer(&*lvl);
	//if (*players == '2') TwoPlayers();
}

int main() {
	int item;
	int lvl = 0;
	int players = 0;
	while (1) {
		Menu(&item);
		if (item == 1)
			Game(&lvl, &players);
		if (item == 2)
			GameRules();
		if (item == 3)
			DifficultyLVL(&lvl);
		if (item == 4)
			return 0;
	}
}
