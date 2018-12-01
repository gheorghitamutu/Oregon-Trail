#pragma once
#include "game.hpp"

class game_description_state : public state
{
public:
	explicit game_description_state(std::shared_ptr<game_data> data);

	game_description_state(const game_description_state& other) = default;
	game_description_state(game_description_state&& other) noexcept = default;
	game_description_state& operator=(const game_description_state& other) = default;
	game_description_state& operator=(game_description_state&& other) noexcept = default;

	~game_description_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};

