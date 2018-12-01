#pragma once
#include <map>

enum journey_months
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
	{march, 31},
	{april, 30},
	{may, 31},
	{june, 30},
	{july, 30},
	{august, 31},
	{september, 30},
	{october, 31},
	{november, 30}
};

static std::map<journey_months, std::string> months_names =
{
	{march, "March"},
	{april, "April"},
	{may, "May"},
	{june, "June"},
	{july, "July"},
	{august, "August"},
	{september, "September"},
	{october, "October"},
	{november, "November"}
};

struct journey_date
{
	journey_months month = march;
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

