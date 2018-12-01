#include "main_menu_state.hpp"
#include "helper.hpp"

#include "description_state.hpp"

#include "end_state.h"

#include <chrono>

#include <iostream>

#include <ostream>

#include <string>

#include <thread>


main_menu_state::main_menu_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}


main_menu_state::~main_menu_state()
{
}

void main_menu_state::init()
{
}

void main_menu_state::handle_input()
{
	std::string choice;
	
	std::getline(std::cin, choice);

	const auto choice_value = static_cast<main_menu_options>(std::stoi(choice));

	switch (choice_value)
	{
	case travel:
		std::cout << "\n\n	Your choice is to travel!";
		break;
	case learn:
		std::cout << "\n\n	Your choice is to learn!";
		data_->machine->add_state(std::make_shared<description_state>(description_state(data_)), false);
		break;
	case check:
		std::cout << "\n\n	Your choice is to check!";
		break;
	case end:
		std::cout << "\n\n	Your choice is to end!";
		data_->machine->add_state(std::make_shared<end_state>(end_state(data_)), false);
		break;
	case offset:
	default: 
		std::cout << "\n\n	Your choice is invalid!";
	}	

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void main_menu_state::update()
{
}

void main_menu_state::draw()
{
	helper::clear_console();

	// std::cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM" <<
	// 	" INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847.\n" <<
	// 	"YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5 - 6 MONTHS..." <<
	// 	" IF YOU MAKE IT ALIVE." << std::endl;

	std::cout << "\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "	You may:\n\n" <<
		"		1. Travel the trail\n" <<
		"		2. Learn about the trail\n" <<
		"		3. See the Oregon Top Ten\n" <<
		"		4. End\n\n" <<
		"	What is your choice? ";

}

void main_menu_state::resume()
{
}

void main_menu_state::pause()
{
}
