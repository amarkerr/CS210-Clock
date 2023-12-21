#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
#endif

#include <iostream>
#include <iomanip>
#include <string>

std::string TwoDigit(int);
std::string RepeatChar(int, std::string);
std::string Time24HR(int, int, int);
std::string Time12HR(int, int, int);

void DisplayMenu();
void DisplayClock(int, int, int);
void AddHour(int& h);
void AddMinute(int& m);
void AddSecond(int& s);
void EndClock(bool&);
void WrongInput(int&);
void NegCheck(int&);