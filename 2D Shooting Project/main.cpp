#include "Render.h"
#include <iostream>




int main()
{
	Render render;	

	while (true)
	{
		
		system("cls");
		Sleep(250);
	}


	if (WaitForSingleObject(render.getEventHandle(), INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "event handle error at " << __FUNCTION__ << ", line: " << __LINE__ << std::endl;
		return(-1);
	}



	return(0);
}