#include "social_status_menu.h"
#include <string>
#include <iostream>
#include "helper.hpp"
#include <chrono>
#include <thread>
#include "pick_names_state.hpp"


social_status_menu::social_status_menu(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}


social_status_menu::~social_status_menu()
{
}

void social_status_menu::init()
{
}

void social_status_menu::handle_input()
{
	std::string choice;

	std::getline(std::cin, choice);

	const auto choice_value = static_cast<social_status_menu_options>(std::stoi(choice));

	switch (choice_value)
	{
	case banker:
		std::cout << "\n\n	Your choice is to be a banker!";
		data_->player_party->get_players()[0].set_money(1200);
		data_->machine->add_state(std::make_shared<pick_names_state>(pick_names_state(data_)), true);
		break;
	case carpenter:
		std::cout << "\n\n	Your choice is to be a carpenter!";
		data_->player_party->get_players()[0].set_money(800);
		data_->machine->add_state(std::make_shared<pick_names_state>(pick_names_state(data_)), true);
		break;
	case farmer:
		std::cout << "\n\n	Your choice is to be a farmer!";
		data_->player_party->get_players()[0].set_money(400);
		data_->machine->add_state(std::make_shared<pick_names_state>(pick_names_state(data_)), true);
		break;
	case offset_status:
	default:
		std::cout << "\n\n	Your choice is invalid!";
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void social_status_menu::update()
{
}

void social_status_menu::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "	Many kinds people made the trip to Oregon\n\n";
	std::cout << "	You may:\n\n" <<
		"		1. Be a banker from Boston\n" <<
		"		2. Be a carpenter from Ohio\n" <<
		"		3. Be a farmer from Illinois\n\n" <<
		"	What is your choice? ";

}

void social_status_menu::resume()
{
}

void social_status_menu::pause()
{
}
