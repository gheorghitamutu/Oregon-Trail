#include "pick_names_state.hpp"
#include <string>
#include <iostream>
#include <thread>
#include "Helper.hpp"
#include "departure_state.hpp"


pick_names_state::pick_names_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
	pick_ = pick_state::main;
}


pick_names_state::~pick_names_state()
{
}

void pick_names_state::init()
{
}

void pick_names_state::handle_input()
{
	std::string name;

	if (pick_ != pick_state::done)
	{
		std::getline(std::cin, name);
	}

	switch (pick_)
	{
	case pick_state::offset_pick:
		pick_ = pick_state::main;
		break;
	case pick_state::main:
		if (name.empty())
		{
			name = "Noah";
		}
		data_->player_party->set_player_name(0, name);
		pick_ = pick_state::second;
		break;
	case pick_state::second:
		if (name.empty())
		{
			name = "Alan";
		}
		data_->player_party->set_player_name(1, name);
		pick_ = pick_state::third;
		break;
	case pick_state::third:
		if (name.empty())
		{
			name = "Joan";
		}
		data_->player_party->set_player_name(2, name);
		pick_ = pick_state::fourth;
		break;
	case pick_state::fourth:
		if (name.empty())
		{
			name = "Elise";
		}
		data_->player_party->set_player_name(3, name);
		pick_ = pick_state::fifth;
		break;
	case pick_state::fifth:
		if (name.empty())
		{
			name = "Katie";
		}
		data_->player_party->set_player_name(4, name);
		pick_ = pick_state::done;
		break;
	case pick_state::done:
		data_->machine->add_state(std::make_shared<departure_state>(departure_state(data_)), true);
		break;
	default: ;
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void pick_names_state::update()
{
}

void pick_names_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n						OREGON TRAIL\n\n\n\n";

	switch (pick_)
	{
	case pick_state::offset_pick:
		break;
	case pick_state::main:
		std::cout << "	What is the first name of the wagon leader?\n\n";
		std::cout << "		#1 ";
		break;
	case pick_state::second:
	case pick_state::third:
	case pick_state::fourth:
	case pick_state::fifth:
	case pick_state::done:
		std::cout << "	What are the names of the four other members in your party?\n\n";
		{
			auto index_names = 0;
			for (const auto& player : data_->player_party->get_players())
			{
				index_names++;
				std::cout << "		#" << index_names << " " << player.get_name();

				if (player.get_name().empty())
				{
					break;
				}

				std::cout << std::endl;
			}
		}
	default: ;
	}
}

void pick_names_state::resume()
{
}

void pick_names_state::pause()
{
}