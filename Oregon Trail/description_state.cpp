#include "description_state.hpp"
#include <string>
#include "Helper.hpp"
#include <iostream>
#include <chrono>
#include <thread>


description_state::description_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}


description_state::~description_state()
{
}

void description_state::init()
{
}

void description_state::handle_input()
{
	std::string choice;

	std::getline(std::cin, choice);

	data_->machine->remove_state();
}

void description_state::update()
{
}

void description_state::draw()
{
	helper::clear_console();	

	std::cout << "\n\n\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "			THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM\n" <<
		"			INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847.\n" <<
		"			YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5 - 6 MONTHS...\n" <<
		"			IF YOU MAKE IT ALIVE.\n\n" <<
		"			PRESS ANY KEY TO CONTINUE...";

}

void description_state::resume()
{
}

void description_state::pause()
{
}
