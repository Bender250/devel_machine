int IsLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int GetCurrentYear(int days) {
    int year = 1980;

    while (days > 365)
    {
        if (IsLeapYear(year))
        {
            if (days > 366)
            {
                days -= 366;
                year += 1;
            }
        }
        else
        {
            days -= 365;
            year += 1;
        }
    }
    return year;
}

int main(void) {
    return GetCurrentYear(10228); // = 31. 12. 2011
    // error for 10593 = 31. 12. 2012
}
