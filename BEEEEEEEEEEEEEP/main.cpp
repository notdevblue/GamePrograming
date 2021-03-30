#include <Windows.h>
#include <iostream>
#define FULL	2250
#define HALF	FULL / 2
#define QUATER	HALF / 2
#define EIGHT	QUATER / 2
#define SIXTEEN EIGHT / 2

struct Freq
{
	DWORD C1	= 32;
	DWORD C1s	= 34;
	DWORD D1	= 36;
	DWORD D1s	= 38;
	DWORD E1	= 41;
	DWORD F1	= 43;
	DWORD F1s	= 46;
	DWORD G1	= 48;
	DWORD G1s	= 51;
	DWORD A1	= 55;
	DWORD A1s	= 58;
	DWORD B1	= 61;

	DWORD C5	= 523;
	DWORD C5s	= 554;
	DWORD D5	= 587;
	DWORD D5s	= 622;
	DWORD E5	= 659;
	DWORD F5	= 698;
	DWORD F5s	= 739;
	DWORD G5	= 783;
	DWORD G5s	= 830;
	DWORD A5	= 880;
	DWORD A5s	= 932;
	DWORD B5	= 987;

	DWORD C6	= 1046;
	DWORD C6s	= 1108;
	DWORD D6	= 1174;
	DWORD D6s	= 1244;
	DWORD E6	= 1318;
	DWORD F6	= 1396;
	DWORD F6s	= 1479;
	DWORD G6	= 1567;
	DWORD G6s	= 1661;
	DWORD A6	= 1760;
	DWORD A6s	= 1864;
	DWORD B6	= 1975;
};

DWORD WINAPI ThreadProc(LPVOID lpParam);


int main()
{
	
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);

	if (WaitForSingleObject(hThread, INFINITE) == WAIT_OBJECT_0)
	{
		std::cout << "\r\n좋네요" << std::endl;
	}
	else
	{
		CloseHandle(hThread);
		return(-1);
	}
	
	



	CloseHandle(hThread);
	return(0);
}

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	Freq freq;

	std::cout << "솔";
	Beep(freq.G5, EIGHT);

	std::cout << "도";
	Beep(freq.C6, QUATER);
	std::cout << "솔";
	Beep(freq.G5, EIGHT + SIXTEEN);
	std::cout << "라";
	Beep(freq.A5, SIXTEEN);
	std::cout << "시";
	Beep(freq.B5, QUATER);
	std::cout << "미";
	Beep(freq.E5, EIGHT);
	std::cout << "미";
	Beep(freq.E5, EIGHT);

	std::cout << "라";
	Beep(freq.A5, QUATER);
	std::cout << "솔";
	Beep(freq.G5, EIGHT + SIXTEEN);
	std::cout << "파";
	Beep(freq.F5, SIXTEEN);
	std::cout << "솔";
	Beep(freq.G5, QUATER);
	std::cout << "도";
	Beep(freq.C5, EIGHT);
	std::cout << "도";
	Beep(freq.C5, EIGHT);

	std::cout << "레";
	Beep(freq.D5, QUATER);
	std::cout << "레";
	Beep(freq.D5, EIGHT);
	std::cout << "미";
	Beep(freq.E5, EIGHT);
	std::cout << "파";
	Beep(freq.F5, QUATER);
	std::cout << "파";
	Beep(freq.F5, EIGHT);
	std::cout << "솔";
	Beep(freq.G5, EIGHT);

	std::cout << "라";
	Beep(freq.A5, QUATER);
	std::cout << "시";
	Beep(freq.B5, EIGHT);
	std::cout << "도";
	Beep(freq.C6, EIGHT);
	std::cout << "레";
	Beep(freq.D6, QUATER + EIGHT);
	std::cout << "(쉼표)";
	Sleep(EIGHT);

	std::cout << "미";
	Beep(freq.E6, QUATER);
	std::cout << "레";
	Beep(freq.D6, EIGHT + SIXTEEN);
	std::cout << "도";
	Beep(freq.C6, SIXTEEN);
	std::cout << "레";
	Beep(freq.D6, QUATER);
	std::cout << "시";
	Beep(freq.B5, EIGHT);
	std::cout << "솔";
	Beep(freq.G5, EIGHT);

	std::cout << "도";
	Beep(freq.C6, QUATER);
	std::cout << "시";
	Beep(freq.B5, EIGHT + SIXTEEN);
	std::cout << "라";
	Beep(freq.A5, SIXTEEN);
	std::cout << "시";
	Beep(freq.B5, QUATER);
	std::cout << "미";
	Beep(freq.E5, EIGHT);
	std::cout << "미";
	Beep(freq.E5, EIGHT);

	return(0);
}