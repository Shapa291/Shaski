#pragma once

#include<utility>
#include <map>
#include "Cell.h"

using movePos = std::pair<pos, pos>;
using map = std::map<pos, Cell>;


class IO
{
public:
	IO();

	static const movePos& getMove();
	static void drawBoard(const map& board);

private:
	static const std::string& castState(Cell::State state);
};

