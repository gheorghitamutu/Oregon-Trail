#include "store_description_state.hpp"
#include <iostream>
#include "helper.hpp"


store_description_state::store_description_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}

store_description_state::~store_description_state()
{
}

void store_description_state::init()
{
}

void store_description_state::handle_input()
{
	std::string choice;

	std::getline(std::cin, choice);

	// TODO: add store state
}

void store_description_state::update()
{
}

void store_description_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n\n\n						OREGON TRAIL\n\n\n\n";

	const auto wagon_cost = data_->universal_store->get_supply_cost(supplies::wagon);
	std::cout << "		YOU HAD SAVED " << (data_->player_party->get_players()[0].get_money() + wagon_cost) << 
		" TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $" << wagon_cost << " FOR A WAGON.\n" <<
		"		YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS :\n\n" <<
		"			- OXEN. YOU CAN SPEND $100 - $200 ON YOUR TEAM.\n" << 
		"			 THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS\n" <<
		"			- FOOD - THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK\n" <<
		"			- AMMUNITION - YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD\n" <<
		"			- MISCELLANEOUS SUPPLIES - THIS INCLUDES MEDICINE AND OTHER THINGS\n" << 
		"			 YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS\n\n" <<
		"		YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP,\n" <<
		"		OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW.\n" <<
		"		HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD.\n\n" <<
		"		PRESS ENTER TO CONTINUE...";

	// TODO: remove this message when the store gets implemented
	std::cout << std::endl << std::endl << "Store not yet implemented!" << std::endl;
}

void store_description_state::resume()
{
}

void store_description_state::pause()
{
}
