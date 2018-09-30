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

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

// Functions required by the assignment:
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

// Additional added functions:
int check_balance_amount(double balance);
int dice_sum_and_indicator(int die1, int die2);
int main_menu();
int wager_or_quit(double balance);