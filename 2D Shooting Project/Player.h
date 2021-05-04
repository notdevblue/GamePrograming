#pragma once
#include "Han.h"
#include "Render.h"

class Player : public Render
{
private:
	SHORT xPos;
	SHORT yPos;

public:

	VOID addRender() override;

	CONSTRUCTOR Player();
	DESTRUCTOR ~Player();


};

