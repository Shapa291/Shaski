#pragma once

#include "Cell.h"
#include <map>

using map = std::map<pos, Cell>;

class Board
{
public:

	enum class moveResult { SUCCESFULL_MOVE, SUCCESFULL_COMBAT, PROHIBITED };

	Board();

	void resetMap();
	
	moveResult makeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat);

	const map& getMap() const { return mCells; }

private:

	moveResult checkMove(const pos& startPos, const pos& endPos, bool direction);
	const size_t mMboardsize;
	map mCells;
};

