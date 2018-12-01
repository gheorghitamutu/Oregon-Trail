#pragma once
#include "game_description_state.hpp"
#include <vector>

enum pick_state : int
{
	offset_pick,
	main,
	second,
	third,
	fourth,
	fifth,
	done
};

class pick_names_state : public state
{
public:
	explicit pick_names_state(std::shared_ptr<game_data> data);

	pick_names_state(const pick_names_state& other) = default;
	pick_names_state(pick_names_state&& other) noexcept = default;
	pick_names_state& operator=(const pick_names_state& other) = default;
	pick_names_state& operator=(pick_names_state&& other) noexcept = default;

	~pick_names_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;

	pick_state pick_;
};

