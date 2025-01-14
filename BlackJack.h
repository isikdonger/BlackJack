#pragma once

#define COLOURS 2
#define COLOURNAME 6
#define SHAPES 4
#define SHAPENAME 10
#define NAME 10
#define SPECIALCARDS 10
#define HAND 12
#define DECK 14
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define BACKGROUND "\033[47m"
#define CRESET "\033[0m"

typedef struct {
	char colour[COLOURNAME];
	char shape[SHAPENAME];
	char name[NAME];
	int value;
	bool inDeck;
}card_t;

//Strings
char colours[COLOURS][COLOURNAME] = { "Red","Blue" };
char shapes[SHAPES][SHAPENAME] = { "Diaomond", "Spade", "Hearth", "Club" };
char names[DECK][NAME] = { "", "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

//The Deck
card_t Deck[SHAPES][DECK];

//Ace
bool AceinHand = false;
int indexofAce = -1;

//Functions
void initiliazeDeck(card_t[SHAPES][DECK]);
int Menu(void);
card_t drawCard(void);
void displayDiamond(card_t);
void displaySpade(card_t);
void displayHearth(card_t);
void displayClub(card_t);
void displayCard(card_t);
void displayHidden(void);
bool isAce(card_t);
int totalValue(card_t*, int);
bool playerAction(card_t*, int*);
int allProbability(void);
int factorial(int);
int count_set_bits(int);
void generate_combinations(card_t*, int, int, int*, int);
int winningProbability(card_t*, int, int);
bool tableAction(card_t*, int*);
int Winner(card_t*, int, card_t*, int);

void initiliazeDeck(void)
{
	for (int i = 0; i < SHAPES; i++)
	{
		for (int j = 1; j < DECK; j++)
		{
			strcpy(Deck[i][j].shape, shapes[i]);
			strcpy(Deck[i][j].colour, colours[i % COLOURS]);
			strcpy(Deck[i][j].name, names[j]);

			if (j <= SPECIALCARDS)
				Deck[i][j].value = j;

			else
				Deck[i][j].value = SPECIALCARDS;

			Deck[i][j].inDeck = true;
		}
	}
}

int Menu(void)
{
	int temp;
	printf("Menu\n");
	printf("1.Play\n");
	printf("2.Exit\n\n");
	printf("Select an option: ");
	scanf("%d", &temp);
	printf("\n");
	return(temp);
}

card_t drawCard(void)
{
	card_t temp;
	int rndShape, rndName;

	do
	{
		rndShape = rand() % SHAPES;
		rndName = rand() % DECK + 1;
	} while (!Deck[rndShape][rndName].inDeck);

	strcpy(temp.shape, Deck[rndShape][rndName].shape);
	strcpy(temp.name, Deck[rndShape][rndName].name);
	temp.value = Deck[rndShape][rndName].value;
	temp.inDeck = Deck[rndShape][rndName].inDeck = false;

	return(temp);
}

void displayDiamond(card_t card)
{
	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");

	printf("|");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf("|\n");

	printf("|");

	for (int i = 1; i <= 12; i++)
		printf(" ");

	printf("|\n");

	//Drawing the symbol
	{
		{
			printf("|");

			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf(RED);
			printf("/");
			printf("\\");
			printf(CRESET);

			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf("|\n");
		}

		{

			printf("|");

			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf(RED);
			printf("/");

			for (int i = 1; i <= 2; i++)
				printf(" ");

			printf("\\");
			printf(CRESET);

			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf("|\n");
		}

		{
			printf("|");

			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf(RED);
			printf("\\");

			for (int i = 1; i <= 2; i++)
				printf(" ");

			printf("/");
			printf(CRESET);

			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf("|\n");
		}

		{
			printf("|");

			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf(RED);
			printf("\\");
			printf("/");
			printf(CRESET);

			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf("|\n");
		}
	}

	printf("|");

	for (int i = 1; i <= 12; i++)
		printf(" ");

	printf("|\n");

	printf("|");

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	printf("|\n");

	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");
}

void displaySpade(card_t card)
{
	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");

	printf("|");

	printf(BLUE);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf("|\n");

	//Drawing the symbol
	{
		{
			for (int i = 0; i < 3; i++)
			{
				printf("|");

				printf(BLUE);
				for (int j = 1; j <= 5 - i; j++)
					printf(" ");

				printf("/");

				for (int j = 0; j < 2 * i; j++)
					printf(" ");

				printf("\\");

				for (int j = 1; j <= 5 - i; j++)
					printf(" ");
				printf(CRESET);

				printf("|\n");
			}
		}

		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 3; i++)
				printf(" ");

			printf("\\____/");

			for (int i = 1; i <= 3; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf("/\\");

			for (int i = 1; i <= 5; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}
	}

	printf("|");

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf(BLUE);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	printf("|\n");


	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");
}

void displayHearth(card_t card)
{
	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");

	printf("|");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf("|\n");

	//Drawing the symbol
	{
		{
			printf("|");

			printf(RED);
			for (int i = 1; i <= 12; i++)
				if (i == 5 || i == 8)
					printf("_");
				else
					printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			printf("|");

			printf(RED);
			for (int i = 1; i <= 12; i++)
				if (i == 4 || i == 7)
					printf("/");
				else if (i == 6 || i == 9)
					printf("\\");
				else
					printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			for (int i = 0; i < 3; i++)
			{
				printf("|");

				printf(RED);
				for (int j = 1; j <= 3 + i; j++)
					printf(" ");

				printf("\\");

				for (int j = 1; j <= 4 - 2 * i; j++)
					printf(" ");

				printf("/");

				for (int j = 1; j <= 3 + i; j++)
					printf(" ");
				printf(CRESET);

				printf("|\n");
			}
		}
	}

	printf("|");

	for (int i = 1; i <= 12; i++)
		printf(" ");

	printf("|\n");

	printf("|");

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	printf("|\n");

	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");
}

void displayClub(card_t card)
{
	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");

	printf("|");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf("|\n");

	printf("|");

	for (int i = 1; i <= 12; i++)
		printf(" ");

	printf("|\n");

	//Drawing the symbol
	{
		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf("/\\");

			for (int i = 1; i <= 5; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf("/\\/\\");

			for (int i = 1; i <= 4; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 4; i++)
				printf(" ");

			printf("\\/\\/");

			for (int i = 1; i <= 4; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}

		{
			printf("|");

			printf(BLUE);
			for (int i = 1; i <= 5; i++)
				printf(" ");

			printf("/\\");

			for (int i = 1; i <= 5; i++)
				printf(" ");
			printf(CRESET);

			printf("|\n");
		}
	}

	printf("|");

	for (int i = 1; i <= 12; i++)
		printf(" ");

	printf("|\n");

	printf("|");

	if (strcmp(card.name, "Ten"))
		for (int j = 2; j <= 12; j++)
			printf(" ");

	else
		for (int j = 3; j <= 12; j++)
			printf(" ");

	printf(RED);
	if ((card.value >= 2 && card.value < 10) || !strcmp(card.name, "Ten"))
		printf("%d", card.value);

	else
		printf("%c", *card.name);
	printf(CRESET);

	printf("|\n");

	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");
}

void displayCard(card_t card)
{
	int i = 0;

	while (strcmp(card.shape, shapes[i]) != 0)
		i++;

	switch (i)
	{
		case 0: displayDiamond(card);
			break;
		case 1: displaySpade(card);
			break;
		case 2: displayHearth(card);
			break;
		case 3: displayClub(card);
			break;
	}
}

void displayHidden(void)
{
	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");

	for (int i = 1; i <= 8; i++)
	{
		printf("|");

		printf(BACKGROUND);
		for (int i = 1; i <= 12; i++)
			printf(" ");
		printf(CRESET);

		printf("|\n");
	}

	printf(" ");

	for (int i = 1; i <= 12; i++)
		printf("-");

	printf("\n");
}

bool isAce(card_t hand)
{
	if (strcmp(hand.name, names[1]) == 0)
		return(true);

	else
		return(false);
}

int totalValue(card_t* hand, int size)
{
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += hand[i].value;

		if (isAce(hand[i]))
		{
			AceinHand = true;
			indexofAce = i;
		}
	}

	if (AceinHand)
	{
		if (total < 12)
			total += 10;

		else if (total > 21)
			total -= 10;
	}

	return(total);
}

bool playerAction(card_t* hand, int* size)
{
	char choice;
	int handValue;

	do
	{
		handValue = totalValue(hand, *size);

		for (int i = 0; i < *size; i++)
			displayCard(hand[i]);

		if (handValue < 21)
		{
			if (AceinHand && handValue <= 10)
				printf("Your hand is %d or %d\n\n", handValue - 10, handValue);

			else
				printf("Your hand is %d\n\n", handValue);

			printf("Your turn. Will you draw or stand? (Y or y for draw, N or n for stand): ");
			scanf(" %c", &choice);

			if (choice == 'Y' || choice == 'y')
			{
				hand[*size] = drawCard();
				(*size)++;

				handValue = totalValue(hand, *size);
			}
		}

		else if (handValue == 21)
		{
			printf("BLACKJACK! You have to wait for table to win.\n\n");
			return(false);
		}

		else
		{
			printf("BUST! You lost! Better luck next time.\n\n");
			return(true);
		}

	} while (choice == 'Y' || choice == 'y');

	return(false);
}

int allProbability(void) {
	int count = 0, pow = 1;

	for (int i = 0; i < SHAPES; i++)
		for (int j = 1; j < DECK; j++)
			if (Deck[j][i].inDeck)
				count++;

	for (int i = 1; i <= count; i++)
		pow *= 2;

	return pow;
}

int factorial(int num) {
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

int count_set_bits(int num) {
	int count = 0;
	while (num) {
		count += num & 1;
		num >>= 1;
	}
	return count;
}

void generate_combinations(card_t* deck, int n, int r, int* wanted, int handValue) {
	int total_combinations = factorial(n) / (factorial(r) * factorial(n - r));
	int* combination = (int*)malloc(sizeof(int) * r);

	for (int i = 0; i < (1 << n); ++i) {
		if (count_set_bits(i) == r) {  // Selecting combinations with 'r' elements
			int index = 0;
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					if (deck[j].inDeck)
						combination[index++] = deck[j].value;
				}
			}

			// Calculate sum of combination
			int sum = 0;
			for (int k = 0; k < r; ++k) {
				sum += combination[k];
			}

			if (handValue + sum <= 21) {
				(*wanted)++;
			}
		}
	}
	free(combination);
}

int winningProbability(card_t* hand, int size, int handValue) {
	int wanted = 0;

	for (int i = 0; i < SHAPES; i++) {
		for (int r = 1; r <= size; r++) {
			generate_combinations(Deck[i], size, r, &wanted, handValue);
		}
	}

	return wanted;
}

bool tableAction(card_t* hand, int* size) {
	bool action = false;
	int handValue;

	do {
		handValue = totalValue(hand, *size);

		if (handValue < 21) {
			int all, win, choice;

			all = allProbability();
			win = winningProbability(hand, *size, handValue);

			choice = rand() % all;

			if (choice <= win) {
				hand[*size] = drawCard();
				(*size)++;
				action = true;
			}
		}
		else if (handValue == 21) {
			printf("BLACKJACK!\n\n");
			return false;
		}
		else {
			return true;
		}
	} while (action);

	return false;
}

int Winner(card_t* pHand, int pSize, card_t* tHand, int tSize)
{
	int pScore = totalValue(pHand, pSize), tScore = totalValue(tHand, tSize);

	if (pScore < tScore)
		return(-1);

	else if (pScore == tScore)
		return(0);

	else
		return(1);
}