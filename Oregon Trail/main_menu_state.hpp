#pragma once
#include "game.hpp"

#include "state_machine.hpp"

enum class main_menu_options : int
{
	offset,
	travel,
	learn,
	check,
	end
};

class main_menu_state : public state
{
public:
	explicit main_menu_state(std::shared_ptr<game_data> data);

	main_menu_state(const main_menu_state& other) = default;
	main_menu_state(main_menu_state&& other) noexcept = default;
	main_menu_state& operator=(const main_menu_state& other) = default;
	main_menu_state& operator=(main_menu_state&& other) noexcept = default;

	~main_menu_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};

