#include "pick_names_state.h"
#include <string>
#include <iostream>
#include <thread>
#include "Helper.hpp"


pick_names_state::pick_names_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
	names_ = {"", "", "", "", ""};
	pick_ = main;
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

	std::getline(std::cin, name);

	switch (pick_)
	{
	case offset_pick:
		pick_ = main;
		break;
	case main:
		if (name.empty())
		{
			name = "Noah";
		}
		names_[0] = name;
		pick_ = second;
		break;
	case second:
		if (name.empty())
		{
			name = "Alan";
		}
		names_[1] = name;
		pick_ = third;
		break;
	case third:
		if (name.empty())
		{
			name = "Joan";
		}
		names_[2] = name;
		pick_ = fourth;
		break;
	case fourth:
		if (name.empty())
		{
			name = "Elise";
		}
		names_[3] = name;
		pick_ = fifth;
		break;
	case fifth:
		if (name.empty())
		{
			name = "Katie";
		}
		names_[4] = name;
		pick_ = done;
		break;
	case done:
		// data_->machine->add_state(std::make_shared<pick_names_state>(pick_names_state(data_)), true);
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
	case offset_pick:
		break;
	case main:
		std::cout << "	What is the first name of the wagon leader?\n\n";
		std::cout << "		#1 ";
		break;
	case second:
	case third:
	case fourth:
	case fifth:
	case done:
		std::cout << "	What are the names of the four other members in your party?\n\n";
		{
			auto index_names = 0;
			for (const auto& name : names_)
			{
				index_names++;
				std::cout << "		#" << index_names << " " << name;

				if (name.empty())
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