#include "departure_state.hpp"
#include "helper.hpp"
#include "store_description_state.hpp"
#include "store.h"

#include <iostream>
#include <thread>


departure_state::departure_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
	departure_pick_ = default_departure_date;
	custom_departure_pick_ = custom_departure_month;
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
			if (value != 1 && value != 2 && value != 3)
			{
				std::cout << "\n	Invalid choice!";
			}
			else
			{
				if (value == 1)
				{
					data_->journey_road->set_start_date_month(journey_months::march);
				}
				else if (value == 2)
				{
					data_->journey_road->set_start_date_month(journey_months::april);
				}
				else if (value == 3)
				{
					data_->journey_road->set_start_date_month(journey_months::may);
				}
				custom_departure_pick_ = custom_departure_day;
			}
			break;
		case custom_departure_day:
			if (value < 1 || value > months[data_->journey_road->get_start_date().month])
			{
				std::cout << "\n	Invalid choice!";
			}
			else
			{
				data_->journey_road->set_start_date_day(value);
				custom_departure_pick_ = done_custom_departure;
			}
			break;
		case done_custom_departure:
			{
				const auto wagon_cost = data_->universal_store->get_supply_cost(supplies::wagon);
				data_->player_party->buy(wagon_cost);
			}
			data_->machine->add_state(std::make_shared<store_description_state>(store_description_state(data_)), true);
			break;
		default: ;
		}
		break;
	case done_departure: 
		{
			const auto wagon_cost = data_->universal_store->get_supply_cost(supplies::wagon);
			data_->player_party->buy(wagon_cost);
		}
		data_->machine->add_state(std::make_shared<store_description_state>(store_description_state(data_)), true);
		break;
	default: ;
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


	const auto start_date = data_->journey_road->get_start_date();

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
			std::cout << "		#1 March\n" <<
				"		#2 April\n" <<
				"		#3 May\n\n" <<
				"	Your choice? ";
			break;
		case custom_departure_day:
			std::cout << "	Pick the day to leave.\n\n";
			std::cout << "		1-" << months[start_date.month] << "\n\n" <<
				"	Your choice? ";
			break;
		case done_custom_departure:
			std::cout << "\n	You start on " << months_names[start_date.month] << " " << start_date.day << " 1847!";
			break;
		default: ;
		}
		break;
	case done_departure:
		std::cout << "\n	You start on " << months_names[start_date.month] << " " << start_date.day << " 1847!";
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