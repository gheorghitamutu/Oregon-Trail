#pragma once
#include "game.hpp"

class description_state : public state
{
public:
	explicit description_state(std::shared_ptr<game_data> data);

	description_state(const description_state& other) = default;
	description_state(description_state&& other) noexcept = default;
	description_state& operator=(const description_state& other) = default;
	description_state& operator=(description_state&& other) noexcept = default;

	~description_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};

