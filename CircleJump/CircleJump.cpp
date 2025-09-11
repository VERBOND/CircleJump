#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>


//Sleep
#include <thread>
#include <chrono>


//Vector
#include <vector>

//Random
#include <cstdlib>
#include <ctime>


//ConsoleClearing
#include <windows.h>

using namespace std;



class Character
{
private:
	string CharacterSkin;
	int cords[2];
	float cordsfloat[2];


	bool jump;
	int jumpHeight;
	int jumpTime;
	int jumpSpeed;
public:
	Character()
	{
		cords[0] = 0;
		cords[1] = 7;



		jump = false;
		jumpHeight = 1;
		jumpTime = 0;
		jumpSpeed = 1;


	}

	string GetCharacterSkin()
	{
		return CharacterSkin;
	}

	int GetCharacterX()
	{
		return cords[0];
	}

	int GetCharacterY()
	{
		return cords[1];
	}


	void Jump()
	{
		if (true)
		{
			jump = true;
			jumpTime = 0;
			cordsfloat[1] = cords[1];
		}
	}


	void Update(int fieldHeight)
	{
			if (jump)
			{
				if (jumpTime <= 20 and cords[1] <= fieldHeight - 1)
				{
					if (jumpTime % 10 == 0)
					{
						cords[1]++;
					}
				}
				if (jumpTime > 20 and cords[1] >= 1)
				{
					if (jumpTime % 10 == 0)
					{
						cords[1]--;
					}
				}
				jumpTime++;

			//Я старався:(
			/*{
				jumpTime++;
				cordsfloat[1] = cordsfloat[1] + jumpHeight * sin(jumpSpeed * jumpTime * 3.14159 / 180.0);
				if (cordsfloat[1] <= fieldHeight)
				{
					cords[1] = cordsfloat[1];

				}
				else
				{
					cordsfloat[1] = cords[1];
					jump = false;
				}
				if (jumpTime >= 180 / jumpSpeed)
				{
					isJumping = false;
					jumpTime = 0;
				}
			}

			else
			{
				jumpTime++;
				cordsfloat[1] = cordsfloat[1] - jumpHeight * sin(jumpSpeed * jumpTime * 3.14159 / 180.0);
				if (cordsfloat[1] >= 1)
				{
					cords[1] = cordsfloat[1];

				}
				else
				{
					cordsfloat[1] = cords[1];
				}
			}*/
		}

	}

};



class Pillar
{
protected:
	int pillarCords[2];
	int direction;


public:

	Pillar()
	{
		pillarCords[0] = 0;
		pillarCords[1] = 0;
		direction = 1; // 1 - up, 0 - down
	}

	int GetPillarX()
	{
		return pillarCords[0];
	}

	int GetPillarY()
	{
		return pillarCords[1];
	}

	int GetPillarDirection()
	{
		return direction;
	}

	void RandomizePosition(int fieldHeight, int playerX)
	{
		pillarCords[0] = playerX + 60;
		pillarCords[1] = rand() % fieldHeight + 1;
		if (pillarCords[1] <= fieldHeight / 2)
		{
			direction = 1;
		}
		else
		{
			direction = 0;
		}
	}
	void PillarCordXMinusMinus(int time)
	{
		pillarCords[0]-- - 0.01 * time * time;
	}

	void PillarSetXCord(int X)
	{
		pillarCords[0] = X;
	}

	void PillarSetYCord(int Y)
	{
		pillarCords[Y] = Y;
	}

	void PillarSetDirection(bool Direction)
	{
		direction = Direction;
	}

};
class DoublePillar : public Pillar
{
protected:
	int secondPillarCords[2];

public:
	DoublePillar()
	{
		secondPillarCords[0] = 0;
		secondPillarCords[1] = 0;
	}

	int GetSecondPillarX()
	{
		return secondPillarCords[0];
	}

	int GetSecondPillarY()
	{
		return secondPillarCords[1];
	}

	void UpdateSecondPosition()
	{
		secondPillarCords[0] = pillarCords[0];
		if (direction == 1)
		{
			secondPillarCords[1] = pillarCords[1] + 4;
		}
		else if (direction == 0)
		{
			
			int temp = pillarCords[1] - 4;
			secondPillarCords[1] = pillarCords[1];
			pillarCords[1] = temp;
		}
		direction = 2;

	}
};




bool CheckingIfUIstxtExists()
{
	ifstream UIs("UIs.txt");
	if (!UIs.is_open())
	{
		ofstream UIs("UIs.txt");
		UIs << "+-------------------------------------------------------------------+\n";
		UIs << "|                                                                   |\n";
		UIs << "|                            CIRCLE JUMP                            |\n";
		UIs << "|                                                                   |\n";
		UIs << "|-------------------------------HELLO-------------------------------|\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                        RESIZE YOUR WINDOW                         |\n";
		UIs << "|                     FOR A BETTER EXPERIENCE                       |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                       AND INPUT SOMETHING                         |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "+-------------------------------------------------------------------+\n";
		UIs << "+-------------------------------------------------------------------+\n";
		UIs << "|                                                                   |\n";
		UIs << "|                            CIRCLE JUMP                            |\n";
		UIs << "|                                                                   |\n";
		UIs << "|-------------------------------------------------------------------|\n";
		UIs << "|                                                                   |\n";
		UIs << "|        +--------------+                                           |\n";
		UIs << "|        |1 - Start game|                                           |\n";
		UIs << "|        +--------------+                                           |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "|                                                                   |\n";
		UIs << "+-------------------------------------------------------------------+\n";
		UIs.close();
		CheckingIfUIstxtExists();
	}
	else
	{
		return 1;
	}
}





void SleepMS(int time)
{
	this_thread::sleep_for(chrono::milliseconds(time));
}



void UpdateMap(Character& player, vector<Pillar>& pillars, vector<DoublePillar>& doublePillars, int fieldHeight)
{
	ofstream Map("Map.txt");


	for (int i = 0; i <= 66; i++)
	{
		for (int j = 0; j <= fieldHeight; j++)
		{
			bool writed = false;
			if (player.GetCharacterY() == j and player.GetCharacterX() == i)
			{
				Map << "O";
				writed = true;
			}
			else
			{
				for (auto& pillar : pillars)
				{
					if (writed == false)
					{
						if (pillar.GetPillarX() == i or pillar.GetPillarX() + 1 == i)
						{
							if (pillar.GetPillarDirection() == 1)
							{
								if (pillar.GetPillarY() >= j)
								{
									Map << "#";
									writed = true;
								}
							}
							else if (pillar.GetPillarDirection() == 0)
							{
								if (pillar.GetPillarY() <= j)
								{
									Map << "#";
									writed = true;
								}
							}
						}
					
					}
				}
				for (auto& doublePillar : doublePillars)
				{
					if (writed == false)
					{
						if (doublePillar.GetPillarX() == i or doublePillar.GetPillarX() + 1 == i)
						{
							if (doublePillar.GetPillarY() >= j or doublePillar.GetSecondPillarY() <= j)
							{
								Map << "#";
								writed = true;
							}
						}
					}
				}
			}
			if (writed == false)
			{
				Map << " ";
			}
		}
		Map << endl;

	}
}


void MapToVisualMap(int playerX, int playerY, int score)
{

	ifstream Map("Map.txt");
	ofstream VisualMap("VisualMap.txt");

	VisualMap << "+-------------------------------------------------------------------+\n";
	VisualMap << "|                                                                   |\n";
	VisualMap << "|                            CIRCLE JUMP                            |\n";
	VisualMap << "|                                                                   |\n";
	VisualMap << "|-------------------------------";
	if (score >= 10000)
	{
		VisualMap << score;
	}
	else if (score >= 1000)
	{
		VisualMap << "0" << score;
	}
	else if (score >= 100)
	{
		VisualMap << "00" << score;
	}
	else if (score >= 10)
	{
		VisualMap << "000" << score;
	}
	else
	{
		VisualMap << "0000" << score;
	}
	VisualMap << "-------------------------------|\n";

	
	vector<string> map;
	string line;
	while (getline(Map, line))
	{
		map.push_back(line);
	}


	vector<string> visualMap(map[0].size(), string(map.size(), ' '));


	for (size_t i = 0; i < map.size(); ++i)
	{
		for (size_t j = 0; j < map[i].size(); ++j)
		{
			visualMap[map[i].size() - j - 1][i] = map[i][j];
		}
	}


	for (const auto& row : visualMap)
	{
		VisualMap << row << endl;
	}


	VisualMap << "+-------------------------------------------------------------------+\n";
}


void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void ShowVisualMap()
{
	ClearScreen();
	ifstream VisualMap("VisualMap.txt");
	string line;
	while (getline(VisualMap, line))
	{
		cout << line << endl;
	}
}

bool CheckIfTouched(Character& player, vector<Pillar>& pillars, vector<DoublePillar>& doublePillars)
{
	for (auto& pillar : pillars)
	{
		if (player.GetCharacterX() == pillar.GetPillarX() or player.GetCharacterX() == pillar.GetPillarX() + 1)
		{
			if (pillar.GetPillarDirection())
			{
				if (player.GetCharacterY() <= pillar.GetPillarY())
				{
					return 0;
				}
			}
			else
			{
				if (player.GetCharacterY() >= pillar.GetPillarY())
				{
					return 0;
				}
			}
		}
	}

	for (auto& doublePillar : doublePillars)
	{
		if (player.GetCharacterX() == doublePillar.GetPillarX() or player.GetCharacterX() == doublePillar.GetPillarX() + 1)
		{
			
				if (player.GetCharacterY() <= doublePillar.GetPillarY() or player.GetCharacterY() >= doublePillar.GetSecondPillarY())
				{
					return 0;
				}
		}
	}
}


int CheckIfPassed(Character& player, vector<Pillar>& pillars, vector<DoublePillar>& doublePillars)
{
	for (auto& pillar : pillars)
	{
		if (player.GetCharacterX() == pillar.GetPillarX())
		{
			if (pillar.GetPillarDirection() == 1)
			{
				if (player.GetCharacterY() > pillar.GetPillarY())
				{
					return 1;
				}
			}
			else if (pillar.GetPillarDirection() == 0)
			{
				if (player.GetCharacterY() < pillar.GetPillarY())
				{
					return 1;
				}
			}
		}
	}
	for (auto& doublePillar : doublePillars)
	{
		if (player.GetCharacterX() == doublePillar.GetPillarX())
		{
			if (player.GetCharacterY() > doublePillar.GetPillarY() or player.GetCharacterY() < doublePillar.GetSecondPillarY())
			{
				return 2;
			}
		}
	}
	return 0;
}

void Game()
{

	Character player;
	vector<Pillar> pillars;
	vector<DoublePillar> doublePillars;
	int fieldHeight = 14;
	int timeUntilEnd = 0;
	int Score = 0;

	Pillar newPillar;
	newPillar.RandomizePosition(fieldHeight, -100);
	pillars.push_back(newPillar);

	DoublePillar newDPillar;
	newDPillar.RandomizePosition(fieldHeight, -100);
	newDPillar.UpdateSecondPosition();
	doublePillars.push_back(newDPillar);

	bool playing = true;
	while (playing)
	{
		timeUntilEnd++;
		Pillar pillar;
		player.Update(fieldHeight);


		if (_kbhit())
		{
			char key = _getch();
			if (key == ' ')
			{
				player.Jump();
			}
		}

		if (timeUntilEnd % 5 == 0)
		{
			for (auto& pillar : pillars)
			{
				pillar.PillarCordXMinusMinus(timeUntilEnd);
			}
			for (auto& doublePillar : doublePillars)
			{
				doublePillar.PillarCordXMinusMinus(timeUntilEnd);
				doublePillar.UpdateSecondPosition();

			}
		}
		
		if (timeUntilEnd % 30 == 0)
		{
				if (rand() % 3 == 0)
				{
					DoublePillar newPillar;
					newPillar.RandomizePosition(fieldHeight, player.GetCharacterX());
					newPillar.UpdateSecondPosition();
					doublePillars.push_back(newPillar);
				}
				else if(rand() % 6 == 0)
				{
					Pillar newPillar;
					newPillar.RandomizePosition(fieldHeight, player.GetCharacterX());
					pillars.push_back(newPillar);
				}		
		}

		UpdateMap(player, pillars, doublePillars, fieldHeight);
		MapToVisualMap(player.GetCharacterX(), player.GetCharacterY(), Score);
		ShowVisualMap();

		playing = CheckIfTouched(player, pillars, doublePillars);
		Score += CheckIfPassed(player, pillars, doublePillars);


		SleepMS(16); // ~60 Ticks in a Second
	}
	char temp = _getch();
}



void FileReadingAndOutput(int value)
{
	ClearScreen();
	int firstLine = 22;
	int lastLine = 42;

	if (value == 1) // Console Resizing
	{
		firstLine = 1;
		lastLine = 21;
	}
	if (value == 2) // Main menu
	{
		firstLine = 22;
		lastLine = 42;
	}

	ifstream UIs("UIs.txt");
	if (UIs.is_open())
	{

		string line;
		int lineNumber = 0;


		while (getline(UIs, line))
		{
			lineNumber++;
			if (lineNumber >= firstLine && lineNumber <= lastLine)
			{
				cout << line << endl;
			}
		}

		UIs.close();


		char temp1 = _getch();
		string temp;
		temp = temp1;

		ClearScreen();

		if (value == 2)
		{
			if (temp == "1")
			{
				Game();
			}
		}
	}
	else
	{
		FileReadingAndOutput(value);
	}
}





int main()
{
	CheckingIfUIstxtExists();
	FileReadingAndOutput(1);

	while (true)
	{
		FileReadingAndOutput(2);
	}
	
}