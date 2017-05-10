#include <stdio.h>
#include <stdlib.h>

int Menu(char *item) {
 	system("clear");
 	printf("\t+---------+ +-----+ +-------+\n");
 	printf("\t|B U L L S| |A N D| |C O W S|\n");
 	printf("\t+---------+ +-----+ +-------+\n");
	
    printf("\t\tWelcome to menu!\n");
	printf("\t\t1.Play\n\t\t2.Game rules\n\t\t3.Difficulty level\n\t\t4.Exit\n");
	
    printf("\tMenu item number: ");
	scanf("%c%*c", item);
    
	while ((*item < '1') || (*item > '4')) {
		printf("Sorry, this menu item number missing :(\nPlease, select again: ");
		scanf("%c%*c", item);
		printf("\n");
	}
	printf("Thanks!\n");
	return 0;
	system("clear");
}

int main() {
	char item;
	Menu(&item);
	if (*item == 3)*/
	return 0;
}
