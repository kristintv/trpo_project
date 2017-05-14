#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void ReadAttempt(int attempt[], int lvl){
	int i = 1;
	int j = 0;
	char c[lvl];
	do {
    	c[0] = getch();
    } while (c[0] <= '0' || c[0] > '9');
    printw("%c", c[0]);
    attempt[0] = c[0] - '0';
    do {
    	int flag = 0;
    	c[i] = getch();
    	if (c[i] < '0' || c[i] > '9')
    		flag = 1;
    	else
    	for (j = i-1; j >= 0; --j)
    		if (c[j] == c[i])
    			flag = 1;
    	if (flag == 1)
    		--i; 
    	refresh();
    	if (flag == 0){
    		printw("%c", c[i]);
    		attempt[i] = c[i] - '0';
    	}
    } while (++i != lvl);
}

void Logo() {
	printw("\to-----------------------------o\n");
 	printw("\t| B U L L S   A N D   C O W S |\n");
 	printw("\to-----------------------------o\n");
}

void Menu(int *item) {
 	char tmp;
 	clear();
 	Logo();
 	*item = 0;
	printw("\t\t  o---------o\n");
 	printw("\t\t  | M E N U |\n");
 	printw("\t\t  o---------o\n");
	printw("\t\to.Play\n");
	printw("\t\t2.Rules\n");
	printw("\t\t3.Difficulty level\n");
	printw("\t\t4.Number of players\n");
	printw("\t\t5.Exit\n");
	printw("Select par. >> ");
	do {
		tmp = getch();
	} while(tmp < '1' || tmp > '5');
	*item = tmp - '0';
	clear();
}

void GameRules() {
	clear();
	Logo();
	printw("\t\t o-----------o\n");
 	printw("\t\t | R U L E S |\n");
 	printw("\t\t o-----------o\n");
 	printw("The player conceives a four-digit number. The numbers in the number do not repeat, 0 can stand in the first place. The player makes moves to find out this number. In response to each turn, the Second Player shows the number of guessed figures standing in their places (the number of bulls) and the number of guessed figures that are not in their places (the number of cows).\n");
 	getch();
	clear();
}

void DifficultyLVL(int *lvl) {
	char tmp;
	clear();
	Logo();
	*lvl = 0;
	printw("You can choose the difficulty level!\n");
	printw("\t\t1.Easy (4 numbers)\n");
	printw("\t\t2.Medium (5 numbers)\n");
	printw("\t\t3.Hard (6 numbers)\n");
	printw("LVL (input number): ");
	do {
		tmp = getch();
	} while(tmp < '1' || tmp > '3');
	*lvl = 3 + tmp - '0';
	clear();
}

void NumberOfPlayers(int *players) {
	char tmp;
	clear();
	Logo();
	*players = 0;
	printw("Please, choose number of players: ");
	do {
		tmp = getch();
	} while (tmp < '1' || tmp > '2');
	*players = tmp - '0';
	printw("%d", *players);

	clear();
}

void OnePlayer(int *lvl) {
	clear();
	int i = 1;
	int j = 0;
	int generate_num[*lvl];
	int attempt[*lvl];
	int bulls = 0;
	int cows = 0;
	int n = 1;
	int check = 0;
	//Загадываем число
	generate_num[0] = 1 + rand() % 9;
	for (i = 1; i < *lvl; ++i) {
		generate_num[i] = rand() % 10;
		for (j = 0; j < i; ++j) {
			if (generate_num[i] == generate_num[j])
				--i;
		}
	}
	Logo();
	printw("N\tAttempt\tCows\tBulls\n");
	while (bulls != *lvl) {
		bulls = 0;
		cows = 0;
		printw("%d\t", n);
		//Считываем число, преобразуем его в массив
		ReadAttempt(attempt, *lvl);
		i = *lvl - 1;
		//Считаем быков
		for (i = 0; i < *lvl; ++i)
			if (attempt[i] == generate_num[i]) ++bulls;
		//Считаем коров
		for (i = 0; i < *lvl; ++i)
			for (j = 0; j < *lvl; ++j)
				if (attempt[i] == generate_num[j]) ++cows;
		cows -= bulls;
		printw("\t%d\t%d\n", cows, bulls);
		n++;
	}
	printw("You win!\nInput number for exit to menu: ");
	scanw("%d", &check);
	clear();

}

void TwoPlayers(int *lvl) {
	clear();
	int i = 0;
	int j = 0;
	int generate_num_one[*lvl];
	int generate_num_two[*lvl];
	int attempt[*lvl];
	int bulls_one = 0;
	int bulls_two = 0;
	int cows_one = 0;
	int cows_two = 0;
	int n = 1;
	Logo();
	printw("Player one, please, input number for another player (%d numbers): ", *lvl);
	ReadAttempt(generate_num_two, *lvl);
	clear();
	Logo();
	printw("Player two, please, input number for another player (%d numbers): ", *lvl);
	ReadAttempt(generate_num_one, *lvl);
	clear();
	Logo();
	printw("\t\tPlayer one\t\t\tPlayer two\n");
	printw("N\tAttempt\tCows\tBulls\t\tAttempt\tCows\tBulls\n");
	while (1) {
		bulls_one = 0;
		bulls_two = 0;
		cows_one = 0;
		cows_two = 0;
		printw("%d\t", n);
		//1игрок
		i = *lvl - 1;
		ReadAttempt(attempt, *lvl);
		//Считаем быков
		for (i = 0; i < *lvl; ++i)
			if (attempt[i] == generate_num_one[i]) ++bulls_one;
		//Считаем коров
		for (i = 0; i < *lvl; ++i)
			for (j = 0; j < *lvl; ++j)
				if (attempt[i] == generate_num_one[j]) ++cows_one;
		cows_one -= bulls_one;
		printw("\t%d\t%d\t\t", cows_one, bulls_one);

		//2игрок
		i = *lvl - 1;
		ReadAttempt(attempt, *lvl);
		//Считаем быков
		for (i = 0; i < *lvl; ++i)
			if (attempt[i] == generate_num_two[i]) ++bulls_two;
		//Считаем коров
		for (i = 0; i < *lvl; ++i)
			for (j = 0; j < *lvl; ++j)
				if (attempt[i] == generate_num_two[j]) ++cows_two;
		cows_two -= bulls_two;
		printw("\t%d\t%d\n", cows_two, bulls_two);
		n++;
		if (bulls_one == *lvl) break;
		if (bulls_two == *lvl) break;
	}
	if ((bulls_one == *lvl) && (bulls_two == *lvl)) printw("\nDraw");
		else if (bulls_one == *lvl) printw("\nPlayer one wins!");
			else printw("\nPlayer two wins!");
	printw("\nClick any button to continue: ");
	getch();
	clear();
}

void Game(int *lvl, int *players) {
	srand(time(NULL));
	if (*lvl == 0) DifficultyLVL(&*lvl);
	if (*players == 0) NumberOfPlayers(&*players);
	if (*players == 1) OnePlayer(&*lvl);
	if (*players == 2) TwoPlayers(&*lvl);
}

int main() {
	initscr();
	scrollok(stdscr, TRUE);
	noecho();
	int item;
	int lvl = 0;
	int players = 0;
	while (1) {
		Menu(&item);
		if (item == 1) Game(&lvl, &players);
		if (item == 2) GameRules();
		if (item == 3) DifficultyLVL(&lvl);
		if (item == 4) NumberOfPlayers(&players);
		if (item == 5) {
			endwin();
			return 0;
		}
	}
	return 0;
}
