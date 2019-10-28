#pragma once
#include "game_description_state.hpp"

enum class departure_options : int
{
	offset_departure,
	default_departure_date,
	custom_departure_date,
	done_departure
};

enum class custom_departure_options : int
{
	offset_departure,
	departure_month,
	departure_day,
	done_departure
};

class departure_state : public state
{
public:
	explicit departure_state(std::shared_ptr<game_data> data);

	departure_state(const departure_state& other) = default;
	departure_state(departure_state&& other) noexcept = default;
	departure_state& operator=(const departure_state& other) = default;
	departure_state& operator=(departure_state&& other) noexcept = default;

	~departure_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;

	departure_options departure_pick_;
	custom_departure_options custom_departure_pick_;
};

