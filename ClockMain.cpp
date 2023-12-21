/***********************************************************************************
**                                                                                **
** Amanda Kerr                                                                    **
** Project Name: ClockMain.cpp                                                    **
** Course: CS210                                                                  **
** Date: 16 July 2023                                                             **
** Description: Simple clock with few features                                    **
**                                                                                **
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Parts.h"



int main()
{
	//Initialize variables
	int menuInput;
	bool running = true;
	int hour = 0;
	int minute = 0;
	int second = 0;


	//Obtain user input for set up and check for negative input
	std::cout << "Please enter the hours: ";
	std::cin >> hour;
	NegCheck(hour);

	std::cout << "Please enter the minutes: ";
	std::cin >> minute;
	NegCheck(minute);

	std::cout << "Please enter the seconds: ";
	std::cin >> second;
	NegCheck(second);


	system("CLS");  //clear previous display from screen


	DisplayClock(hour, minute, second);  //first display and menu selection prior to loop start
	std::cout << std::endl;
	DisplayMenu();

	std::cout << "Menu selection : ";
	std::cin >> menuInput;
	std::cout << std::endl;


	//while loop menu functionality
	while (running)
	{

		if (menuInput == 1)
		{
			AddHour(hour);
		}

		else if (menuInput == 2)
		{
			AddMinute(minute);
		}

		else if (menuInput == 3)
		{
			AddSecond(second);
		}

		else if (menuInput == 4)
		{
			EndClock(running);
			continue;
		}

		else
		{
			system("CLS");
			DisplayClock(hour, minute, second);
			WrongInput(menuInput);
			std::cin >> menuInput;
			system("CLS");
			continue;
		}

		DisplayClock(hour, minute, second);  //display clock changes and menu
		std::cout << std::endl;
		DisplayMenu();

		std::cout << "Menu selection : ";
		std::cin >> menuInput;
	} 
}