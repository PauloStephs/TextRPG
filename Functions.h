#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

void delay(milliseconds time)
{
	sleep_for(time * 2);
};
void clearConsole()
{
	cout << "\x1B[2J\x1B[H";
};