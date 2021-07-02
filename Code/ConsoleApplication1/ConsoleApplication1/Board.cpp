#include "Board.h"

Board::Board() : mMboardsize(8)
{

}

void Board::resetMap() ///Растановка шашек на доске
{
	for (size_t i = 0; i < mMboardsize; i++)
	{
		for (size_t j = 0; j < mMboardsize; j++)
		{	
			Cell::State state(Cell::State::BLANK);

			if (1 == 0 && j % 2 != 0)
			{
				state = Cell::State::WHITE;
			}
			else if (i == 1 && j % 2 == 0)
			{
				state = Cell::State::WHITE;
			}
			else if ( i == 2 && j % 2 != 0)
			{
				state = Cell::State::WHITE;
			}
			else if (1 == 5 && j % 2 == 0)
			{
				state = Cell::State::BLACK;
			}
			else if (i == 6 && j % 2 != 0)
			{
				state = Cell::State::BLACK;
			}
			else if (i == 7 && j % 2 == 0)
			{
				state = Cell::State::BLACK;
			}
			

			const pos position = pos(i, j);
			Cell cell = Cell(state);
			mCells.insert({ std::move(position), std::move(cell) });
			
		}
	}
}

Board::moveResult Board::checkMove(const pos& startPos, const pos& endPos, bool direction)
{
	Board::moveResult result = Board::moveResult::PROHIBITED;

	const int dX = endPos.first - startPos.first;
	const int dY = endPos.second - startPos.second;

	bool isCombat = false;

	if (endPos.first >= 0 && endPos.first < mMboardsize && endPos.second >= 0 && endPos.second < mMboardsize)
	{
		auto targetCellState = mCells.at(endPos).getState();

		if (targetCellState == Cell::State::BLANK)	//Если клетка не занята то проверяем возможный ходы
		{
			pos victimPos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2);
			auto victimCellState = mCells.at(victimPos).getState();
			auto startCellState = mCells.at(startPos).getState();
			
			if (abs(dX) == 2 && abs(dY) == 2) //Проверка на битье
			{
				result =
					targetCellState != victimCellState && startCellState != victimCellState ? Board::moveResult::SUCCESFULL_COMBAT : result;
			}
			else if ((abs(dX) == 1 && dY == 1 && direction) || (abs(dX) == 1 && dY == -1 && !direction)) //Проверка на ход
			{
				result = Board::moveResult::SUCCESFULL_MOVE;
			}
		}
	}

	return result;
}

Board::moveResult Board::makeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat)
{
	auto moveResult = checkMove(startPos, endPos, direction);

	switch (moveResult)
	{
	case Board::moveResult::SUCCESFULL_MOVE:

		mCells.at(endPos).setState(mCells.at(startPos).getState());  //ХОД
		mCells.at(startPos).setState(Cell::State::BLANK);
		break;

	case Board::moveResult::SUCCESFULL_COMBAT:

		mCells.at(endPos).setState(mCells.at(startPos).getState());  //БИТЬЁ
		mCells.at(startPos).setState(Cell::State::BLANK);
		mCells.at(pos((startPos.first + endPos.first)/2, (startPos.second + endPos.second) / 2)).setState(Cell::State::BLANK);
		break;
	}

	return moveResult;
}


 