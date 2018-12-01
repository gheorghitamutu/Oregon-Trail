#include "player.hpp"


player::player()
{
}

player::player(player* other)
{
}

int player::get_money() const
{
	return money_;
}

void player::set_money(const int money)
{
	money_ = money;
}

void player::drop_money_by(const int money)
{
	if (money > money_)
	{
		money_ -= money;
	}
}

bool player::buy(const int money)
{
	if (money > money_)
	{
		money_ -= money;
		return true;
	}
	return false;
}

int player::get_health() const
{
	return health_;
}

void player::set_health(const int health)
{
	health_ = health;

	if (health_ <= 0)
	{
		is_alive_ = false;
	}
}

void player::drop_health_by(const int damage)
{
	health_ -= damage;

	if (health_ <= 0)
	{
		is_alive_ = false;
	}
}

bool player::is_alive() const
{
	return is_alive_;
}

std::string player::get_name() const
{
	return name_;
}

void player::set_name(const std::string name)
{
	name_ = name;
}
