#include "road.h"



road::road()
{
}


road::~road()
{
}

journey_date road::get_start_date() const
{
	return start_date_;
}

journey_date road::get_current_date() const
{
	return current_date_;
}

journey_date road::get_end_date() const
{
	return end_date_;
}

void road::set_start_date_month(const journey_months month)
{
	start_date_.month = month;
}

void road::set_start_date_day(const int day)
{
	start_date_.day = day;
}
