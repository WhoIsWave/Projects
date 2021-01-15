#pragma once

struct InputState
{
	InputState() : playerUp(false), playerDown(false), playerRight(false), playerLeft(false), playerClick(false)
	{}

	bool playerUp;
	bool playerDown;
	bool playerRight;
	bool playerLeft;
	bool playerClick;
	//bool showCrosshair;
};