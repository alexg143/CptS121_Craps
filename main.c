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

int main(void)
{
	// Variable declarations
	double wager = 0.0, initial_balance = 0.0, current_balance = 0.0, balance = 0.0;
	int die1 = 0, die2 = 0, sum_first = 0, sum_second = 0, point = 0, add_or_subtract = 0,
		balance_check = 0, wager_check = 0, number_rolls = 0, item = 0, menu_option = 0, 
		wager_option = 0;

	srand((unsigned int)time(NULL)); // given by Andy during lecture

	menu_option = main_menu();

	while (menu_option == 1)
	{
		do // Ensures that a balance greater than 0 is entered
		{
			balance = get_bank_balance();
			balance_check = check_balance_amount(balance);
		} while (balance_check == 0);

		while (balance_check == 1 && balance > 0) // Loop while a balance greater than 0 is entered
		{
			initial_balance = balance;
			do
			{
				wager = get_wager_amount();
				wager_check = check_wager_amount(wager, balance);
			} while (wager_check == 0); // Ensures that a wager smaller than the balance is entered

			sum_first = dice_sum_and_indicator(die1, die2);
			add_or_subtract = is_win_loss_or_point(sum_first); // Evaluates the first roll of dice

			if (add_or_subtract == -1) // If the first roll gave a point, roll consecutive times
			{
				point = sum_first;
				do
				{
					sum_second = dice_sum_and_indicator(die1, die2);
					add_or_subtract = is_point_loss_or_neither(sum_second, point);
				} while (add_or_subtract == -1); // Keep rolling until the user wins or loses
			}

			balance = adjust_bank_balance(balance, wager, add_or_subtract);
			current_balance = balance;
			number_rolls += 1;
			chatter_messages(number_rolls, add_or_subtract, initial_balance, current_balance);
			wager_option = wager_or_quit(balance); // Prompts the user to quit or keep playing

			if (wager_option == 2) // If user chose to quit, exit all loops and quit game
			{
				balance = 0;
				menu_option = 0;
			}
		}
	}
	return 0;
}