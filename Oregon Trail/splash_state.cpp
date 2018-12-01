#include "splash_state.hpp"
#include "main_menu_state.hpp"

#include <iostream>

#include <memory>

#include <utility>
#include <chrono>
#include <thread>
#include "helper.hpp"


splash_state::splash_state(std::shared_ptr<game_data> data) : data_(std::move(data)), initial_time_(clock())
{
}

void splash_state::init()
{
}

void splash_state::handle_input()
{
}

void splash_state::update()
{
	if ((clock() - initial_time_) * 1.0 / CLOCKS_PER_SEC > state_duration_)
	{
		data_->machine->add_state(std::make_shared<main_menu_state>(main_menu_state(data_)), true);
	}
}

void splash_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n						OREGON TRAIL...\n\n\n\n";

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void splash_state::pause()
{
}

void splash_state::resume()
{
}
