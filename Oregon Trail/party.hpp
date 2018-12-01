#pragma once
#include "player.hpp"
#include <vector>

class party
{
public:
	party();

	party(const party& other) = default;
	party(party&& other) noexcept = default;
	explicit party(party* other);
	party& operator=(const party& other) = default;
	party& operator=(party&& other) noexcept = default;

	~party() = default;

	bool is_party_able_to_continue();
	void check_party();

	std::vector<player> get_players() const;
	void set_player_name(int player_index, const std::string& name);
	void set_money(int money);
	void buy(int money);
private:
	std::vector<player> players_;
	const int players_count_ = 5;
	int players_alive_ = 5;
	bool party_failed_ = false;

	int wagon_count_ = 1;
	int oxens_ = 0;
	int food_pounds_ = 0;
	int bullet_boxes_ = 0;
	int wagon_parts_ = 0;
	int medical_kits_ = 0;

};

