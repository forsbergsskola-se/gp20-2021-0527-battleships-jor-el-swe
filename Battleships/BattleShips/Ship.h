#pragma once
class Ship
{
	private:
		bool isSunk = false;
		int coordinate = 0;
	public:
		int getPosition()
		{
			return coordinate;
		}

		void setPosition(int pos)
		{
			coordinate = pos;
		}

		bool getIsSunk()
		{
			return isSunk;
		}
};

