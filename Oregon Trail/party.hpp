#pragma once
#include "player.hpp"
#include <vector>

class party
{
public:
	party();
	~party();

	bool is_party_able_to_continue();
	void check_party();

	std::vector<player> get_players() const;
	void set_player_name(int player_index, std::string name);
private:
	std::vector<player> players_;
	const int players_count_ = 5;
	int players_alive_ = 5;
	bool party_failed_ = false;
};

