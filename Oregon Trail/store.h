#pragma once
#include <map>


enum class supplies
{
	wagon,
	oxen,
	food,
	ammunition,
	miscellaneous_supplies
};

class store
{
public:
	store();

	store(const store& other) = default;
	store(store&& other) noexcept = default;
	store& operator=(const store& other) = default;
	store& operator=(store&& other) noexcept = default;

	~store();

	void increase_rate();

	int get_supply_cost(supplies supply);

private:
	std::map<supplies, int> supplies_costs_;
	float rate_ = 0.0;
	float rate_increase_ = 0.25;
};

