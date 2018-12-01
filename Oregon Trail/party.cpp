#include "party.hpp"



party::party()
{
	player default_player;;

	for (auto index = 0; index < players_count_; index++)
	{
		players_.emplace_back(default_player);
	}
}

party::party(party* other)
{
}

bool party::is_party_able_to_continue()
{
	if (!players_[0].is_alive())
	{
		return false;
	}

	if (oxens_ < 2)
	{
		return false;
	}

	if (food_pounds_ < 1)
	{
		return false;
	}

	return true;
}

void party::check_party()
{
	if (!players_[0].is_alive())
	{
		party_failed_ = true;
	}

	players_alive_ = 0;
	for (const auto& member : players_)
	{
		if (member.is_alive())
		{
			players_alive_++;
		}
	}
}

std::vector<player> party::get_players() const
{
	return players_;
}

void party::set_player_name(const int player_index, const std::string& name)
{
	if (player_index > players_count_)
	{
		return;
	}

	players_[player_index].set_name(name);
}

void party::set_money(const int money)
{
	players_[0].set_money(money);
}

void party::buy(const int money)
{
	players_[0].buy(money);
}
