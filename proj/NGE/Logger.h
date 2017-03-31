#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>


enum ConsoleColor 
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

enum class LogType
{
	MESS,
	ATTMP,
	INF,
	ERR
};

class Logger
{
public:
	static void Log(const std::string &message, LogType logType = LogType::INF);
	static void fatalError(const std::string &message);
};

