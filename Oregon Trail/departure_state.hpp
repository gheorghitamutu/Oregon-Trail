#pragma once
#include "description_state.hpp"

enum departure_options : int
{
	offset_departure,
	default_departure_date,
	custom_departure_date,
	done_departure
};

enum custom_departure_options : int
{
	offset_custom_departure,
	custom_departure_month,
	custom_departure_day,
	done_custom_departure
};

struct months
{
	int march = 31;
	int april = 30;
	int may = 31;
	int june = 30;
	int july = 30;
	int august = 31;
	int september = 30;
	int october = 31;
	int november = 30;
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
