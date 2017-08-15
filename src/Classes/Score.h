#pragma once
#include "SFML\Graphics.hpp"
#include "RandomGenerator.h"

using namespace sf;

class Score{
private:
	randomGenerator* m_Random;
	int curScore;
	int highScore;
	Font font;
	Text message;
	Text t_Score;
	Text finalScores;

public:
	Score();
	void setMessage();
	void setplusScore(float pointX, float pointY);
	void resetScore();
	Text getMessage();
	void updateScore();
	Text getCurScore();
	Text getScores();
	void readHighScore();
	void writeHighScore();
};