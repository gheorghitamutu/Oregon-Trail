#include "game_description_state.hpp"
#include <string>
#include "Helper.hpp"
#include <iostream>
#include <chrono>
#include <thread>


game_description_state::game_description_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}


game_description_state::~game_description_state()
{
}

void game_description_state::init()
{
}

void game_description_state::handle_input()
{
	std::string choice;

	std::getline(std::cin, choice);

	data_->machine->remove_state();
}

void game_description_state::update()
{
}

void game_description_state::draw()
{
	helper::clear_console();	

	std::cout << "\n\n\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "			THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM\n" <<
		"			INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847.\n" <<
		"			YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5 - 6 MONTHS...\n" <<
		"			IF YOU MAKE IT ALIVE.\n\n" <<
		"			PRESS ENTER TO CONTINUE...";

}

void game_description_state::resume()
{
}

void game_description_state::pause()
{
}
