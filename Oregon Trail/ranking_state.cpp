#include "ranking_state.hpp"
#include <string>
#include <iostream>
#include "Helper.hpp"
#include <fstream>


ranking_state::ranking_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{	
}


ranking_state::~ranking_state()
{
}

void ranking_state::init()
{
	ranks_.clear();

	std::ifstream file(rankings_filename_);

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			ranks_.emplace_back(line);
		}
		file.close();
	}
}

void ranking_state::handle_input()
{
	std::string choice;

	std::getline(std::cin, choice);

	data_->machine->remove_state();
}

void ranking_state::update()
{
	ranks_.clear();

	std::ifstream file(rankings_filename_);

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			ranks_.emplace_back(line);
		}
		file.close();
	}
}

void ranking_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "		RANKING\n\n";

	if (ranks_.empty())
	{
		std::cout << "		" << "EMPTY" << std::endl;
	}

	auto rank_index = 0;
	for (const auto& rank : ranks_)
	{
		rank_index++;
		if (rank_index > 10)
		{
			break;
		}
		std::cout << "		#" << rank_index << " " << rank << std::endl;
	}

	std::cout << "\n		" << "PRESS ANY KEY TO CONTINUE...";
}

void ranking_state::resume()
{
}

void ranking_state::pause()
{
}