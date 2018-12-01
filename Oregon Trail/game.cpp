#include "game.hpp"
#include "splash_state.hpp"

#include <iostream>


game::game() noexcept
{
	data_->machine->add_state(std::make_shared<splash_state>(splash_state(data_)));
	data_->machine->process_state_changes();

	run();
}

void game::run() const
{
	while (true)
	{
		data_->machine->get_active_state()->handle_input();
		data_->machine->get_active_state()->update();
		
		data_->machine->process_state_changes();

		data_->machine->get_active_state()->draw();
	}
}