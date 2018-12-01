#pragma once

#include "state.hpp"

#include "game.hpp"

#include <ctime>
#include <memory>


class splash_state : public state
{
public:
	explicit splash_state(std::shared_ptr<game_data> data);

	splash_state(const splash_state& other) = default;
	splash_state(splash_state&& other) noexcept = default;
	splash_state& operator=(const splash_state& other) = default;
	splash_state& operator=(splash_state&& other) noexcept = default;

	~splash_state() = default;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void pause() override;
	void resume() override;

private:
	std::shared_ptr<game_data> data_;

	clock_t initial_time_;

	const int state_duration_ = 3;

};

