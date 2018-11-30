#pragma once
class game
{
public:
	game();
	~game();

	void run();

	void process_input();
	void update();
	void render();
};

