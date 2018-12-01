#pragma once
#include <string>

class player
{
public:
	player();
	~player();

	int get_money() const;
	void set_money(int money);

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

