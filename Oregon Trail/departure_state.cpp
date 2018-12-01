#include "departure_state.hpp"
#include <iostream>
#include <thread>
#include "Helper.hpp"


departure_state::departure_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
	departure_pick_ = default_departure_date;
	custom_departure_pick_ = offset_custom_departure;
}


departure_state::~departure_state()
{
}

void departure_state::init()
{
}

void departure_state::handle_input()
{
	std::string choice;

	if (departure_pick_ != done_departure)
	{
		std::getline(std::cin, choice);
	}

	const auto value = choice.empty() ? 0 : std::stoi(choice);

	switch (departure_pick_)
	{
	case offset_departure:
		departure_pick_ = default_departure_date;
		break;
	case default_departure_date:
		if (value != 1 && value != 2)
		{
			std::cout << "\n	Invalid choice!";
		}
		else
		{
			if (value == 1)
			{
				departure_pick_ = done_departure;
				// TO DO: add this to road class
			}
			else
			{
				departure_pick_ = custom_departure_date;
			}
		}
		break;
	case custom_departure_date:
		switch (custom_departure_pick_)
		{
		case offset_custom_departure:
			custom_departure_pick_ = custom_departure_month;
			break;
		case custom_departure_month:
			custom_departure_pick_ = custom_departure_day;
			// TO DO: add this to road class
			break;
		case custom_departure_day:
			custom_departure_pick_ = done_custom_departure;
			// TO DO: add this to road class
			break;
		case done_custom_departure:
		default: ;
		}
		break;
	case done_departure:
		break;
	default:;
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void departure_state::update()
{
}

void departure_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n						OREGON TRAIL\n\n\n\n";

	switch (departure_pick_)
	{
	case offset_departure:
		break;
	case default_departure_date:
		std::cout << "	It is 1847. Your jumping off place for Oregon is Independence, Missouri.\n\n" <<
			"		#1 Do you want to start on March 01 1847?\n" <<
			"		#2 Do you want to pick a date between March 01 1847 and May 01 1847?\n\n" <<
			"	Your choice? ";
		break;
	case custom_departure_date:
		switch (custom_departure_pick_)
		{
		case offset_custom_departure:
			custom_departure_pick_ = custom_departure_month;
			break;
		case custom_departure_month:
			std::cout << "	Pick the month to leave.\n\n";
			std::cout << "		#1 March" <<
				"		#1 April" <<
				"		#1 May\n" <<
				"	Your choice? ";

			// TO DO: add month
			break;
		case custom_departure_day:
			std::cout << "	Pick the day to leave.\n\n";
			std::cout << "		1-31\n" <<
				"	Your choice? ";
			custom_departure_pick_ = done_custom_departure;
			// TO DO: add this to road class
			break;
		case done_custom_departure:
			// TO DO: read the date from road
			break;
		default: ;
		}
	case done_departure:
		std::cout << "\n	You start on March 01 1847!";
		break;
	default: ;
	}
}

void departure_state::resume()
{
}

void departure_state::pause()
{
}