#include <cmath> 

const int DAILY_WORK_HOURS{ 8 };
const int MONTHLY_BILLABLE_DAYS{ 22 };

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate*8;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double DiscountedPrice = before_discount - before_discount * (discount/100); //wonder if 100 is int.
    if (DiscountedPrice < 0)
        return 0;
    else
        return DiscountedPrice;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    int numHoursInMonth = MONTHLY_BILLABLE_DAYS * 8;
    double nonDiscountHourlyRate = numHoursInMonth * hourly_rate;
    double discountMonthlyRate = apply_discount(nonDiscountHourlyRate, discount);
    return std::ceil(discountMonthlyRate);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    return budget / apply_discount(hourly_rate*DAILY_WORK_HOURS,discount);
}