#include "store.h"



store::store()
{
	supplies_costs_ =
	{
		{supplies::wagon, 200},
		{supplies::oxen, 40},
		{supplies::food, 200},
		{supplies::ammunition, 200},
		{supplies::miscellaneous_supplies, 200},
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
