#include "stdafx.h"
#include "Score.h"
#include "string"

Score::Score(){
	m_Random = new randomGenerator();
    font.loadFromFile("Fonts/Carten.otf");
	curScore = 0;
	readHighScore();

	t_Score.setFont(font);
	t_Score.setString("Score: "+std::to_string(curScore));
    t_Score.setCharacterSize(40); 
	t_Score.setFillColor(sf::Color::Black);
	t_Score.setPosition(30,20);

	finalScores.setFont(font);
    finalScores.setCharacterSize(30); 
	finalScores.setFillColor(sf::Color::Magenta);
	finalScores.setPosition(130,140);
}

void Score::setMessage(){
	String messages[4] = {"Nice Shot","Amazing Shot","Wonderful Shot","Awesome Shot"};
	int random = m_Random->generateRandom(4);
    message.setFont(font);
	message.setString(messages[random]);
    message.setCharacterSize(70); 
	message.setFillColor(sf::Color(25,163,25));
	message.setPosition(250,230);
}

void Score::setplusScore(float pointX, float pointY){
	message.setFont(font);
	message.setString("+10");
    message.setCharacterSize(40);
	message.setFillColor(sf::Color(0,0,255));
	message.setPosition(pointX, pointY);
}

Text Score::getMessage(){
	return message;
}

void Score::resetScore(){
	curScore = 0;
}

void Score::updateScore(){
	curScore+=10;
}

Text Score::getCurScore(){
	t_Score.setString("Score: "+std::to_string(curScore));
	return t_Score;
}

Text Score::getScores(){
	finalScores.setString("High Score: " + std::to_string(highScore) + "\nYour Score: " + std::to_string(curScore));
	return finalScores;
}

void Score::readHighScore(){
	FILE *in;
	fopen_s(&in,"highscore","rb");
	if(in==NULL){
		highScore = 0;
	}
	else{
		fread(&highScore,1,sizeof(long),in);
		fclose(in);
	}
}

void Score::writeHighScore(){
	if(curScore <= highScore)	return;
	highScore = curScore;
	FILE *out;
	fopen_s(&out,"highscore","wb");
	if(out==NULL)	return;
	fwrite(&highScore,1,sizeof(long),out);
	fclose(out);
}