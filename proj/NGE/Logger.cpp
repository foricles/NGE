#include "Logger.h"


void Logger::Log(const std::string & message, LogType logType)
{
	/*��������� �����������*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
	SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::White));

	switch (logType)
	{
	case LogType::MESS:
		std::cout << "Message: " << message << std::endl;
			break;
	case LogType::INF:
		/*���� �������� - �������. ���� ���� - ������*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::LightGreen));
		std::cout << "Info: " << message << std::endl;
		break;
	case LogType::ATTMP:
		/*���� �������� - ������. ���� ���� - ������*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::Yellow));
		std::cout << "Attemption: " << message << std::endl;
		break;
	case LogType::ERR:
		/*���� �������� - �������. ���� ���� - ������*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::LightRed));
		std::cout << "Error: " << message << std::endl;
		break;
	}

	SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::White));

}

void Logger::fatalError(const std::string & message)
{
	Logger::Log(message, LogType::ERR);
	system("pause");
	exit(69);
}
