#pragma once
#include "game.hpp"

#include <memory>


enum class social_status_menu_options : int
{
	offset_status,
	banker,
	carpenter,
	farmer
};

class social_status_menu : public state
{
public:
	explicit social_status_menu(std::shared_ptr<game_data> data);

	social_status_menu(const social_status_menu& other) = default;
	social_status_menu(social_status_menu&& other) noexcept = default;
	social_status_menu& operator=(const social_status_menu& other) = default;
	social_status_menu& operator=(social_status_menu&& other) noexcept = default;

	~social_status_menu() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};
