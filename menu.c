#include <stdio.h>
#include <stdlib.h>

void Logo() {
	printf("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
 	printf("\t|B|U|L|L|S| |A|N|D| |C|O|W|S|\n");
 	printf("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
}

void Menu(char *item) {
 	system("clear");
 	Logo();
	printf("\t\tWelcome to menu!\n");
	printf("\t\t1.Play\n\t\t2.Game rules\n\t\t3.Difficulty level\n\t\t4.Exit\n");
	printf("\tMenu item number: ");
	scanf(" %c", item);
	while ((*item < '1') || (*item > '4')) {
		printf("Sorry, this menu item number is missing :(\nPlease, select again: ");		//Исправить ошибку с повторяющимся выводом
		scanf("%c", item);
		printf("\n");
	}
	printf("Thanks!\n");
	system("clear");
}

void GameRules(char *item) {
	system("clear");
	Logo();
	printf("\t\t  +-+-+-+-+-+\n");
 	printf("\t\t  |R|U|L|E|S|\n");
 	printf("\t\t  +-+-+-+-+-+\n");
 	printf("*Rules*\n");		//Добавить правила
 	*item = 0;
	printf("Input 0 to back: ");
	scanf("%c\n", item);
	while (*item != '0') {
		printf("Sorry, it`s not 0 :(\nPlease, select again: ");
		scanf("%c\n", item);
	}
}

void DifficultyLVL(char *lvl, char *item) {
	system("clear");
	Logo();
	*item = 0;
	*lvl = 0;
	printf("You can choose the difficulty level!\n\t\t1.Easy (4 numbers)\n\t\t2.Medium (5 numbers)\n\t\t3.Hard (6 numbers)\n");
	printf("LVL (input number): ");
	scanf("%c", lvl);
	while ((*lvl < '1') || (*lvl > '3')) {
		printf("Sorry, this difficulty level is missing :(\nPlease, select again: ");		//Исправить ошибку с повторяющимся выводом
		scanf("%c\n", lvl);
	}
}

int main() {
	char item;
	char lvl;
	while (1) {
		Menu(&item);
		if (item == '2')
			GameRules(&item);
		if (item == '3')
			DifficultyLVL(&lvl, &item);
		if (item == '4')
			return 0;
	}
}
