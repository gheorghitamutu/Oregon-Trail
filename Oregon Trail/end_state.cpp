#include "end_state.hpp"
#include <string>
#include <iostream>
#include "Helper.hpp"
#include <thread>


end_state::end_state(std::shared_ptr<game_data> data) : data_(std::move(data))
{
}


end_state::~end_state()
{
}

void end_state::init()
{
}

void end_state::handle_input()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	exit(0);
}

void end_state::update()
{
}

void end_state::draw()
{
	helper::clear_console();

	std::cout << "\n\n\n\n\n\n						OREGON TRAIL\n\n\n\n";
	std::cout << "					   THANK YOU FOR PLAYING!\n\n\n\n";
}

void end_state::resume()
{
}

void end_state::pause()
{
}