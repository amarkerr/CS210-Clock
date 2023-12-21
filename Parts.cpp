#include "Parts.h"

std::string TwoDigit(int twoDig)  // converts into strings and adds 0 for numbers 0-9
{
	std::string hold = "0";

	if (twoDig < 10)
	{
		hold = std::to_string(twoDig);
		hold = hold.insert(0, "0");
	}

	else
	{
		hold = std::to_string(twoDig);
	}

	return hold;
}


std::string RepeatChar(int count, std::string icon)  //creates line of string
{
	std::string banner = icon;

	for (int i = 1; i < count; ++i)
	{
		banner += icon;
	}

	return banner;
}

std::string Time24HR(int h, int m, int s) //creates 24 hour time for display
{
	std::string time24 = "0";

	if (s > 59)
	{
		while (s > 59)
		{
			s = s - 59;
			++m;
		}
	}

	if (m > 59)
	{
		while (m > 59)
		{
			m = m - 59;
			++h;
		}
	}

	if (h > 24)
	{
		while (h > 24)
		{
			h = h - 24;
		}
	}

	time24 = TwoDigit(h) + ":" + TwoDigit(m) + ":" + TwoDigit(s);

	return time24;
}


std::string Time12HR(int h, int m, int s) //creates 12 hour time for display
{
	std::string meridian = "A M";
	std::string time12 = "0";

	if (h >= 12)
	{
		meridian = "P M";
	}


	if (s > 59)
	{
		while (s > 59)
		{
			s = s - 59;
			++m;
		}
	}

	if (m > 59)
	{
		while (m > 59)
		{
			m = m - 59;
			++h;
		}
	}

	if (h > 12)
	{
		h = h - 12;
		meridian = "P M";

		if (h == 12)
		{
			h = 0;
			meridian = "A M";
		}
	}

	time12 = TwoDigit(h) + ":" + TwoDigit(m) + ":" + TwoDigit(s) + " " + meridian;

	return time12;
}



void DisplayMenu()  //formatted menu display
{
	std::cout << RepeatChar(23, "*") << std::endl;
	std::cout << "* 1-Add One Hour";
	std::cout << std::right << std::setw(7) << "*" << std::endl;
	std::cout << "* 2-Add One Minute";
	std::cout << std::right << std::setw(5) << "*" << std::endl;
	std::cout << "* 3-Add One Second";
	std::cout << std::right << std::setw(5) << "*" << std::endl;
	std::cout << "* 4-Exit Program";
	std::cout << std::right << std::setw(7) << "*" << std::endl;
	std::cout << RepeatChar(23, "*") << std::endl;
}

void DisplayClock(int h, int m, int s)  //formatted dual clock display
{
	std::cout << RepeatChar(23, "*") << RepeatChar(5, " ") << std::right << std::setw(23) << RepeatChar(23, "*") << std::endl;
	std::cout << "*    12-Hour Clock    *" << RepeatChar(5, " ") << std::right << std::setw(23) << "*    24-Hour Clock    *" << std::endl;
	std::cout << "*     " << Time12HR(h, m, s) << "    *" << RepeatChar(5, " ") << "*       " << Time24HR(h, m, s) << "      *" << std::endl;
	std::cout << RepeatChar(23, "*") << RepeatChar(5, " ") << std::right << std::setw(23) << RepeatChar(23, "*") << std::endl;
}

void AddHour(int& h)  //adds 1 hour to both clocks
{
	system("CLS");
	++h;
}

void AddMinute(int& m)  //adds 1 minute to both clocks
{
	system("CLS");
	++m;
}

void AddSecond(int& s)  //adds 1 second to both clocks
{
	system("CLS");
	++s;
}

void EndClock(bool& b)  //ends while loop, ending program
{
	system("CLS");
	std::cout << RepeatChar(23, "*") << std::endl;
	std::cout << "*      THANK YOU      *" << std::endl;
	std::cout << "*       GOODBYE       *" << std::endl;
	std::cout << RepeatChar(23, "*") << std::endl;
	b = false;

}

void WrongInput(int& w)  //advises menu input not valid, prompts user to enter new choice
{

	std::cout << std::endl;
	DisplayMenu();
	std::cout << "Invalid menu choice.\nPlease reenter menu choice: ";
}

void NegCheck(int& num)  //advises setup number input not valid, prompts user to enter new choice
{
	if (num < 0)
	{
		std::cout << "Negative numbers are not accepted.\nPlease enter a new number: ";
		std::cin >> num;
	}
}