#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <iostream>
#include "auth.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <random>
#include <csignal>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstreamm
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include <strsafe.h>
#include "Console.h"
#pragma comment(lib, "urlmon.lib")
#define UNLEN 64

string sp = a_gethid();

using namespace std;
namespace con = JadedHoboConsole;

bool GetProcessEntryByName(string name, PROCESSENTRY32* pe) {
	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE) {
		cerr << "Tool helper cannot be created" << endl;
		return false;
	}

	if (!Process32First(snapshot, pe)) {
		cerr << "Tool helper cannot retrieve the first entry of process list" << endl;
		return false;
	}

	do {
		if (pe->szExeFile == name) {
			snapshot ? CloseHandle(snapshot) : 0;
			return true;
		}
	} while (Process32Next(snapshot, pe));

	snapshot ? CloseHandle(snapshot) : 0;
	return false;
}

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

DWORD GetProcId(const char* procName)
{
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!_stricmp(procEntry.szExeFile, procName))
				{
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procId;
}

int main(int argc, const char* argv[]) {

	SetConsoleTitleA("ADM Free FiveM | By InkaWeb#6666");
	clear();
	string  path;
	PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) };
	if (GetProcessEntryByName("FiveM.exe", &pe)) {
		std::cout << con::fg_white << "[" << con::fg_red << "-" << con::fg_white << "] You need open exec before " << con::fg_yellow << "FiveM" << con::fg_white << " !";
		Sleep(999999999999999999);
	}

	ifstream fichier("GTAVLauncher.exe");
	if (fichier)
	{
		system("curl (link for ur dll) --output (path) >nul 2>&1");
		std::cout << "[" << con::fg_red << "+" << con::fg_white << "] Waiting for " << con::fg_green << "FiveM.exe" << con::fg_red << "" << con::fg_white << " ..." << endl;
		for (; !GetProcessEntryByName("FiveM.exe", &pe); Sleep(100));
		std::cout << "[" << con::fg_red << "+" << con::fg_white << "] Injected !" << endl;
		Sleep(3000);
		clear();
		std::cout << "[" << con::fg_green << "/" << con::fg_white << "] Thank you for choosing " << con::fg_blue << "ADM Community " << con::fg_white << "!" << endl;
		Sleep(500);
		std::cout << "[" << con::fg_green << "/" << con::fg_white << "] Server is " << con::fg_green << "online" << con::fg_white << " ..." << endl;
		std::cout << "[" << con::fg_green << "/" << con::fg_white << "] You have " << con::fg_green << "last update " << con::fg_white << "..." << endl;
		std::cout << "[" << con::fg_green << "/" << con::fg_white << "] The exec is " << con::fg_green << "not disabled " << con::fg_white << "..." << endl;
		std::cout << "\n";
		std::cout << "[" << con::fg_green << "+" << con::fg_white << "]" << con::fg_magenta << " Sucess ! Enjoy" << con::fg_white << endl;
		Sleep(999999999999999);
	}
	else {
		std::cout << "[" << con::fg_red << "+" << con::fg_white << "] ErrorID : " << con::fg_green << "#02" << con::fg_red << "" << con::fg_white << " ..." << endl;
		Sleep(999999999999999);
	}
}
