#pragma once

#include <utility> //std::pair

using pos = std::pair<size_t, size_t>;

class Cell
{
public:
	enum class State { BLACK, WHITE, BLANK };

	Cell(/*const pos& position,*/ State state);
	~Cell();

	State getState() const { return mState; }
	void setState(State state) { mState = state; }
	
	//const pos& getPosition() const { return mPosition; }
	//void setPosition(const pos& position) { mPosition = position; }

private:
	State mState;
	//pos mPosition;

};