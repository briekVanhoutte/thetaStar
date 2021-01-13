#pragma once

struct Float2
{
	float x;
	float y;
};

struct Color3f
{
	float r;
	float g;
	float b;
};

enum class TileState
{
	actor,
	notChecked,
	checked,
	wall,
	goal,
	path,
	checkedNotPath
};

