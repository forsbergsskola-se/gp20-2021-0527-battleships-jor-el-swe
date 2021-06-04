#pragma once
class PlayingField
{
	private:
		char grid[100]{};
	public:
		void init(void);
		void getRowNumber(int, char*);
		bool setShipAtPosition(int, int);
};

