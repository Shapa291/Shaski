#pragma once
class Game
{
public:

	enum class Winner { NONE, BLACK, WHITE };
	Winner getWinner() const;

};

