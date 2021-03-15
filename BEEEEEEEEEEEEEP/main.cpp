#include <Windows.h>

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



int main()
{
	Freq freq;

	Beep(freq.G5, EIGHT);
	
	Beep(freq.C6, QUATER);
	Beep(freq.G5, EIGHT + SIXTEEN);
	Beep(freq.A5, SIXTEEN);
	Beep(freq.B5, QUATER);
	Beep(freq.E5, EIGHT);
	Beep(freq.E5, EIGHT);

	Beep(freq.A5, QUATER);
	Beep(freq.G5, EIGHT + SIXTEEN);
	Beep(freq.F5, SIXTEEN);
	Beep(freq.G5, QUATER);
	Beep(freq.C5, EIGHT);
	Beep(freq.C5, EIGHT);

	Beep(freq.D5, QUATER);
	Beep(freq.D5, EIGHT);
	Beep(freq.E5, EIGHT);
	Beep(freq.F5, QUATER);
	Beep(freq.F5, EIGHT);
	Beep(freq.G5, EIGHT);

	Beep(freq.A5, QUATER);
	Beep(freq.B5, EIGHT);
	Beep(freq.C6, EIGHT);
	Beep(freq.D6, QUATER + EIGHT);
	Sleep(EIGHT);

	Beep(freq.E6, QUATER);
	Beep(freq.D6, EIGHT + SIXTEEN);
	Beep(freq.C6, SIXTEEN);
	Beep(freq.D6, QUATER);
	Beep(freq.B5, EIGHT);
	Beep(freq.G5, EIGHT);

	Beep(freq.C6, QUATER);
	Beep(freq.B5, EIGHT + SIXTEEN);
	Beep(freq.A5, SIXTEEN);
	Beep(freq.B5, QUATER);
	Beep(freq.E5, EIGHT);
	Beep(freq.E5, EIGHT);

	return(0);
}