#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BlackJack.h"

int main(void)
{
	card_t playerHand[HAND], tableHand[HAND];
	bool isBust;
	int playerSize, tableSize = 0, playerValue, winner, choice;

	srand(time(NULL));

	do
	{

		do
		{
			choice = Menu();
		} while (choice != 1 && choice != 2);

		switch (choice)
		{
			case 1: 
				initiliazeDeck();
				playerSize = tableSize = 0;

				tableHand[tableSize] = drawCard();
				tableSize++;
				displayCard(tableHand[tableSize - 1]);

				tableHand[tableSize] = drawCard();
				tableSize++;
				displayHidden();

				playerHand[playerSize] = drawCard();
				playerSize++;

				playerHand[playerSize] = drawCard();
				playerSize++;

				playerValue = totalValue(playerHand, playerSize);

				isBust = playerAction(playerHand, &playerSize);

				if (isBust)
					printf("BUST! You lost! Better luck next time.\n\n");

				else
				{
					isBust = tableAction(tableHand, &tableSize);

					if (!isBust)
					{
						winner = Winner(playerHand, playerSize, tableHand, tableSize);

						if (winner == -1)
						{
							printf("Hand of the table:\n");
							for (int i = 0; i < tableSize; i++)
							{
								displayCard(tableHand[i]);
							}
							printf("Total value of the table: %d\n", totalValue(tableHand, tableSize));
							printf("Hand of the player:\n");
							for (int i = 0; i < playerSize; i++)
							{
								displayCard(playerHand[i]);
							}
							printf("Total value of the player: %d\n", totalValue(playerHand, playerSize));
							printf("You have lost! Better luck next time.\n\n");
						}

						else if (winner == 0)
						{
							printf("Hand of the table:\n");
							for (int i = 0; i < tableSize; i++)
							{
								displayCard(tableHand[i]);
							}
							printf("Total value of the table: %d\n", totalValue(tableHand, tableSize));
							printf("Hand of the player:\n");
							for (int i = 0; i < playerSize; i++)
							{
								displayCard(playerHand[i]);
							}
							printf("Total value of the player: %d\n", totalValue(playerHand, playerSize));
							printf("Draw! Try your luck again.\n\n");
						}

						else
						{
							printf("Hand of the table:\n");
							for (int i = 0; i < tableSize; i++)
							{
								displayCard(tableHand[i]);
							}
							printf("Total value of the table: %d\n", totalValue(tableHand, tableSize));
							printf("Hand of the player:\n");
							for (int i = 0; i < playerSize; i++)
							{
								displayCard(playerHand[i]);
							}
							printf("Total value of the player: %d\n", totalValue(playerHand, playerSize));
							printf("You have won!! Congratulations!\n\n");
						}
					}

					else
					{
						printf("Hand of the table:\n");
						for (int i = 0; i < tableSize; i++)
						{
							displayCard(tableHand[i]);
						}
						printf("Total value of the table: %d\n", totalValue(tableHand, tableSize));
						printf("Hand of the player:\n");
						for (int i = 0; i < playerSize; i++)
						{
							displayCard(playerHand[i]);
						}
						printf("Total value of the player: %d\n", totalValue(playerHand, playerSize));
						printf("BUST! You have won. Congratulations!\n");
					}
				}

			case 2: break;
		}


	} while (choice != 2);

	return(0);
}