#pragma once
#include <map>

#include <string>


enum things_to_buy
{
	wagon,
	oxen,
	food,
	ammunition,
	miscellaneous_supplies
};

static std::map<things_to_buy, int> things_cost =
{
	{wagon, 200},
	{oxen, 40},
	{food, 200},
	{ammunition, 200},
	{miscellaneous_supplies, 200},
};

class player
{
public:
	player();

	player(const player& other) = default;
	player(player&& other) noexcept = default;
	explicit player(player* other);
	player& operator=(const player& other) = default;
	player& operator=(player&& other) noexcept = default;

	~player() = default;

	int get_money() const;
	void set_money(int money);
	void drop_money_by(int money);
	bool buy(int money);

	int get_health() const;
	void set_health(int health);
	void drop_health_by(int damage);

	bool is_alive() const;

	std::string get_name() const;
	void set_name(std::string name);
private:
	std::string name_ = "";

	int money_ = 0;
	int health_ = 100;
	bool is_alive_ = true;
};

