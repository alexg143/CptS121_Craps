/*
Programmer: Alexander Glenn
Class: CptS 121; Lab Section 6
Programming Assignment: Programming Assignment 4
Date: February 23, 2018
Description: This program runs a game of Craps that the user can
			 play. The game is intialized with a start menu and
			 the user can quit at any time after each roll. The
			 program uses loops in main(), as well as the three
			 file format. It is the 4th programming assignment
			 for CptS 121, Spring 2018.
*/

#include "header.h" // Include header file

/*
Function: void print_game_rules(void)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function prints the game rules
Input parameters: None
Returns: None
Preconditions: None
Postconditions: The game rules are printed
*/
void print_game_rules(void)
{
	printf("*********************************-CRAPS-**************************************\n\nA player\
 rolls two dice. \Each die has six faces.These faces contain 1, 2, 3, 4\n5, and 6 spots. \
After the dice have come to rest, the sum of the spots on the\ntwo upward faces is calculated. If the \
sum is 7 or 11 on the first throw, the\nplayer wins. If the sum is 2, 3, or 12 on the first throw \
(called \"craps\"),\nthe player loses (i.e.the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on\nthe first\
 throw, then the sum becomes the player's \"point.\" To win, you must\ncontinue rolling the dice until you \
\"make your point.\" The player loses by\nrolling a 7 before making the point.\n\n(Description adopted from\
 Deitel & Deitel)\n\n******************************************************************************\n\n");
}

/*
Function: double get_bank_balance(void)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function prompts for a bank
			 balance and returns it.
Input parameters: None
Returns: bank_balance
Preconditions: None
Postconditions: bank_balance is returned
*/
double get_bank_balance(void)
{
	double bank_balance = 0.0;
	printf("Please enter your initial bank balance: $");
	scanf("%lf", &bank_balance);
	return bank_balance;
}

/*
Function: double get_wager_amount(void)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function prompts for a wager
			 and returns it.
Input parameters: None
Returns: wager_amount
Preconditions: None
Postconditions: wager_amount is returned
*/
double get_wager_amount(void)
{
	double wager_amount = 0.0;
	printf("Please enter a wager for this roll: $");
	scanf("%lf", &wager_amount);
	printf("\n");
	return wager_amount;
}

/*
Function: int check_wager_amount(double wager, double balance)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function returns 0 if the wager is
			 larger than the balance, and 1 otherwise.
Input parameters: double wager, double balance
Returns: success
Preconditions: wager and balance are defined
Postconditions: success is returned
*/
int check_wager_amount(double wager, double balance)
{
	int success = 1;
	if (wager > balance)
	{
		success = 0;
	}
	return success;
}

/*
Function: int roll_die(void)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function sets die to a random
			 number between one and six, and then
			 returns die.
Input parameters: None
Returns: die
Preconditions: None
Postconditions: die is returned
*/
int roll_die(void) // given by Andy during lecture
{
	int die = 0;
	die = rand() % 6 + 1;
	return die;
}

/*
Function: int calculate_sum_dice(int die1_value, int die2_value)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function sums two dice values.
Input parameters: int die1_value, int die2_value
Returns: sum
Preconditions: die1_value and die2_value are defined
Postconditions: sum is returned
*/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;
	sum = die1_value + die2_value;
	return sum;
}

/*
Function: int is_win_loss_or_point(int sum_dice)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function determines if the first
			 dice roll is a win, loss, or point, and
			 returns -1, 1, or 0 depending on that.
Input parameters: int sum_dice
Returns: success
Preconditions: sum_dice is defined
Postconditions: success is returned
*/
int is_win_loss_or_point(int sum_dice) // determines result of first roll
{
	int success = -1;
	if (sum_dice == 7 || sum_dice == 11)
	{
		success = 1;
	}
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		success = 0;
	}
	return success;
}

/*
Function: int is_point_loss_or_neither(int sum_dice, int point_value)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This functions determines the results of any
			 successive rolls after the first one, and returns
			 -1, 1, and 0 accordingly.
Input parameters: int sum_dice, int point_value
Returns: success
Preconditions: sum_dice and point_value is defined
Postconditions: success is returned
*/
int is_point_loss_or_neither(int sum_dice, int point_value) // determins the result of any successive roll
{
	int success = -1;
	if (sum_dice == point_value)
	{
		success = 1;
	}
	if (sum_dice == 7)
	{
		success = 0;
	}
	return success;
}

/*
Function: double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function adjusts the bank balance based on
			 the add_or_subtract variable, which determines 
			 a win or a loss.
Input parameters: double bank_balance, double wager_amount, int add_or_subtract
Returns: bank_balance
Preconditions: bank_balance, wager_amount, and add_or_subtract are defined
Postconditions: bank_balance is returned
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) // add or subtract determined by above two func
{
	if (add_or_subtract == 1)
	{
		bank_balance += wager_amount;
	}
	if (add_or_subtract == 0)
	{
		bank_balance -= wager_amount;
	}
	return bank_balance;
}

/*
Function: void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
Date Created: February 21, 2018
Date Last Modified: February 21, 2018
Description: This function prints messages to the user after each roll
			 dependent on the parameters and if-statements.
Input parameters: int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance
Returns: None
Preconditions: number_rolls, win_loss_neither, initial_bank_balance, and current_bank_balance are defined
Postconditions: A message is printed
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	printf("\nYour new balance is $%0.2lf and your last balance was $%0.2lf\n", current_bank_balance, initial_bank_balance);
	if ((current_bank_balance > initial_bank_balance) && (number_rolls > 2))
	{
		printf("It might be time to cash in those chips!\n\n");
	}
	else if (win_loss_neither == 1)
	{
		printf("Nice win!\n\n");
	}
	else if (current_bank_balance == 0)
	{
		printf("Sorry, your balance is now $0!\n\n");
	}
	else if ((win_loss_neither == 0) && (number_rolls > 2))
	{
		printf("Shucks!\n\n");
	}
	else if (current_bank_balance < initial_bank_balance)
	{
		printf("Don't give up yet!\n\n");
	}
}

/*
Function: int check_balance_amount(double balance)
Date Created: February 22, 2018
Date Last Modified: February 22, 2018
Description: This function checks to see if the balance
			 inputted is greater than 0. If so, it returns
			 1, and if not it returns 0.
Input parameters: double balance
Returns: None
Preconditions: balance is defined
Postconditions: success is returned
*/
int check_balance_amount(double balance)
{
	int success = 0;
	if (balance > 0)
	{
		success = 1;
	}
	return success;
}

/*
Function: int dice_sum_and_indicator(int die1, int die2)
Date Created: February 22, 2018
Date Last Modified: February 22, 2018
Description: This function rolls both dice and calculates the sum
			 of the dice. Sum is returned, and a message is printed
			 each time the dice are rolled.
Input parameters: int die1, int die2
Returns: sum
Preconditions: die1 and die2 are defined
Postconditions: sum is returned
*/
int dice_sum_and_indicator(int die1, int die2)
{
	int sum = 0;
	die1 = roll_die();
	die2 = roll_die();
	sum = calculate_sum_dice(die1, die2);
	printf("[] Rolling dice... The sum is %d\n", sum);
	return sum;
}

/*
Function: int main_menu()
Date Created: February 23, 2018
Date Last Modified: February 23, 2018
Description: This function prints the game menu and
			 prompts the user to play game or quit. 
			 The response to the prompt is returned.
Input parameters: None
Returns: prompt
Preconditions: None
Postconditions: prompt is returned
*/
int main_menu()
{
	int prompt = 0;
	print_game_rules();
	printf("Enter 1 to play game or 2 to quit: ");
	scanf("%d", &prompt);
	printf("\n*********************************************************\
*********************\n\n");
	return prompt;
}

/*
Function: int wager_or_quit(double balance)
Date Created: February 23, 2018
Date Last Modified: February 23, 2018
Description: This function prompts the user based on
			 if the balance is less than or equal to
			 0 or not.
Input parameters: double balance
Returns: prompt
Preconditions: balance is defined
Postconditions: prompt is returned
*/
int wager_or_quit(double balance)
{
	int prompt = 0;
	if (balance <= 0)
	{
		printf("Enter 1 to enter a new balance or 2 to quit to menu: ");
	}
	else
	{
		printf("Enter 1 to enter a new wager or 2 to quit game: ");
	}
	scanf("%d", &prompt);
	printf("\n*********************************************************\
*********************\n\n");
	return prompt;
}