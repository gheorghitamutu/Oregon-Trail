#pragma once
#include "state_machine.hpp"

#include "memory"
#include "party.hpp"


struct game_data
{
	std::shared_ptr<state_machine> machine = std::make_shared<state_machine>(state_machine());
	std::shared_ptr<party> player_party = std::make_shared<party>(party());

	game_data() = default;

	game_data(const game_data& other) = delete;
	game_data(game_data&& other) noexcept = default;

	explicit game_data(game_data* other)
	{
	};
	game_data& operator=(const game_data& other) = delete;
	game_data& operator=(game_data&& other) noexcept = delete;

	~game_data() = default;
};

enum class game_progress
{
	playing,
	pause,
	won,
	lose
};

class game
{
public:
	game() noexcept;

	game(const game& other) = default;
	game(game&& other) noexcept = default;
	game& operator=(const game& other) = delete;
	game& operator=(game&& other) noexcept = delete;

	~game() = default;
	
	void run() const;
private:

	std::shared_ptr<game_data> data_ = std::make_shared<game_data>(game_data());
};

