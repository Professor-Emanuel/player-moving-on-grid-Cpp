// text-based-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input

#include <iostream>

struct GridObject {
	int x;
	int y;
};

struct Grid {
	int totalX;
	int totalY;

	void Render(GridObject obj) {
		for (int col = 0; col < totalY; col++) {
			for (int row = 0; row < totalX; row++) {
				if (obj.x == row && obj.y == col) {
					std::cout << "P";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
	}
};

struct PlayerInput {
	std::string yourString;

	char GetInput() {
		std::cout << "Say something: ";
		std::cin >> yourString;

		std::cout << std::endl;
		std::cout << "You said: " << yourString << std::endl;
		std::cout << "First letter: " << yourString[0] << std::endl;

		std::cin.clear(); //clear error flags
		std::cout << std::endl;

		return yourString[0];
	}
};

int main()
{
	Grid grid;
	grid.totalX = 8;
	grid.totalY = 12;

	GridObject obj;
	obj.x = 3;
	obj.y = 6;


	PlayerInput playerInput;
	char input = '0';
	while (input != 'q') {

		grid.Render(obj);
		input = playerInput.GetInput();
		if (input == 'w' && obj.x > 0) {
			obj.x -= 1;
		}
		else if (input == 'e' && obj.x < grid.totalX - 1) {
			obj.x += 1;
		}
		else if (input == 'n' && obj.y > 0) {
			obj.y -= 1;
		}
		else if (input == 's' && obj.y < grid.totalY - 1) {
			obj.y += 1;
		}
	}

	return 0;
}