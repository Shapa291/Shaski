#include "IO.h"

#include <iostream>
#include <string>

const movePos& IO::getMove()
{
	movePos position;

	size_t p1, p2;


	//¬вод хода
	std::cin >> p1;
	std::cin >> p2;

	position.first.first = p1 / 10;
	position.first.second = p1 - 10 * position.first.first;

	position.second.first = p2 / 10;
	position.second.second = p2 - 10 * position.second.first;

	return position;
}

void IO::drawBoard(const map& board)
{
	size_t boardSize = board.size();
	for (size_t i = 0; i < boardSize; i++)
	{
		std::cout << "|" << std::endl;

		for (size_t j = 0; j < boardSize; j++)
		{
			std::string cellValue = castState(board.at(pos(i, j)).getState());
			std::cout << cellValue;
			std::cout << "|" << std::endl;
		}
	}
}

const std::string& IO::castState(Cell::State state)
{
	std::string result("");

	switch (state)
	{
	case Cell::State::BLACK:

		result = "B";
		break
			;
	case Cell::State::WHITE:

		result = "W";
		break;

	default:

		result = " ";
		break;

	}

	return result; 
}
