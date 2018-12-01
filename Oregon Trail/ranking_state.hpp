#pragma once
#include <memory>
#include "game.hpp"
#include <vector>

class ranking_state : public state
{
public:
	explicit ranking_state(std::shared_ptr<game_data> data);

	ranking_state(const ranking_state& other) = default;
	ranking_state(ranking_state&& other) noexcept = default;
	ranking_state& operator=(const ranking_state& other) = default;
	ranking_state& operator=(ranking_state&& other) noexcept = default;

	~ranking_state() override;

	void init() override;

	void handle_input() override;
	void update() override;
	void draw() override;

	void resume() override;
	void pause() override;

private:
	std::shared_ptr<game_data> data_;

	std::vector<std::string> ranks_;

	const std::string rankings_filename_ = "results.txt";
};

