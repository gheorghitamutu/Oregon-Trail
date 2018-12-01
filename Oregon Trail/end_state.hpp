#pragma once
#include <memory>
#include "game.hpp"

class end_state : public state
{
public:
	explicit end_state(std::shared_ptr<game_data> data);

	end_state(const end_state& other) = default;
	end_state(end_state&& other) noexcept = default;
	end_state& operator=(const end_state& other) = default;
	end_state& operator=(end_state&& other) noexcept = default;

	~end_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};

