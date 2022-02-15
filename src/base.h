#pragma once
#define Vec2 = Vector

struct Vector2
{
private:
	float _X, _Y;

public:
	Vector2(int X, int Y)
	{
		_X = X;
		_Y = Y;
	}
	Vector2(float X, float Y)
	{
		_X = X;
		_Y = Y;
	}
	Vector2 getVector2(Vector2 vec)
	{
		return vec;
	}
};

namespace mem 
{
	namespace nop 
	{
		void nopFunc(PVOID memAdress, int sizeOfNop);
		void restoreNopFunc(PVOID memAdress, int sizeOfNop, const char* restoreOpCode);
	}
}

namespace hooks
{
	
}