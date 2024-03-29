#include <chrono>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

#include "main_menu_state.hpp"
#include "helper.hpp"
#include "game_description_state.hpp"
#include "end_state.hpp"
#include "ranking_state.hpp"
#include "social_status_menu.h"


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
	case main_menu_options::travel:
		std::cout << "\n\n	Your choice is to travel!";
		data_->machine->add_state(std::make_shared<social_status_menu>(social_status_menu(data_)), false);
		break;
	case main_menu_options::learn:
		std::cout << "\n\n	Your choice is to learn!";
		data_->machine->add_state(std::make_shared<game_description_state>(game_description_state(data_)), false);
		break;
	case main_menu_options::check:
		std::cout << "\n\n	Your choice is to check!";
		data_->machine->add_state(std::make_shared<ranking_state>(ranking_state(data_)), false);
		break;
	case main_menu_options::end:
		std::cout << "\n\n	Your choice is to end!";
		data_->machine->add_state(std::make_shared<end_state>(end_state(data_)), false);
		break;
	case main_menu_options::offset:
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
