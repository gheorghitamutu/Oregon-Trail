#include "store.h"



store::store()
{
	supplies_costs_ =
	{
		{wagon, 200},
		{oxen, 40},
		{food, 200},
		{ammunition, 200},
		{miscellaneous_supplies, 200},
	};
}


store::~store()
{
}

void store::increase_rate()
{
	rate_ += rate_increase_;

	for (auto& supply : supplies_costs_)
	{
		supply.second = static_cast<int>(supply.second * rate_);
	}
}

int store::get_supply_cost(const supplies supply)
{
	return supplies_costs_[supply];
}
