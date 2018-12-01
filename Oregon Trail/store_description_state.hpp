#pragma once
#include <memory>
#include "game.hpp"

class store_description_state : public state
{
public:
	explicit store_description_state(std::shared_ptr<game_data> data);

	store_description_state(const store_description_state& other) = default;
	store_description_state(store_description_state&& other) noexcept = default;
	store_description_state& operator=(const store_description_state& other) = default;
	store_description_state& operator=(store_description_state&& other) noexcept = default;

	~store_description_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;
};

