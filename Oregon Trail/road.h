#pragma once

#include <map>
#include <string>

enum class journey_months
{
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november
};

static std::map<journey_months, int> months = 
{
	{journey_months::march, 31},
	{journey_months::april, 30},
	{journey_months::may, 31},
	{journey_months::june, 30},
	{journey_months::july, 30},
	{journey_months::august, 31},
	{journey_months::september, 30},
	{journey_months::october, 31},
	{journey_months::november, 30}
};

static std::map<journey_months, std::string> months_names =
{
	{journey_months::march, "March"},
	{journey_months::april, "April"},
	{journey_months::may, "May"},
	{journey_months::june, "June"},
	{journey_months::july, "July"},
	{journey_months::august, "August"},
	{journey_months::september, "September"},
	{journey_months::october, "October"},
	{journey_months::november, "November"}
};

struct journey_date
{
	journey_months month = journey_months::march;
	int day = 1;
};

class road
{
public:
	road();

	road(const road& other) = default;
	road(road&& other) noexcept = default;
	road& operator=(const road& other) = default;
	road& operator=(road&& other) noexcept = default;

	~road();

	journey_date get_start_date() const;
	journey_date get_current_date() const;
	journey_date get_end_date() const;

	void set_start_date_month(journey_months month);
	void set_start_date_day(int day);

private:
	journey_date start_date_;
	journey_date current_date_;
	journey_date end_date_;
};

