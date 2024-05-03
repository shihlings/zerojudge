#include <iostream>

//#define debugging

namespace start {
int year, month, day;
};

namespace end {
int year, month, day;
};

namespace result {
int day;
}

namespace calculation {
int start_month_to_day, end_month_to_day;
int day;
int year;
int month;
}

bool cindata() {
    int year1, year2, month1, month2, day1, day2;
    std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
#ifdef debugging
    std::cerr << "\nyear1, month1, day1, year2, month2, day2:\n" << year1 << ' ' << month1 << ' ' << day1 << ' ' << year2 << ' ' << month2 << ' ' << day2 << '\n';
#endif
    if (year1 > year2) {
        start::year = year2;
        start::month = month2;
        start::day = day2;
        end::year = year1;
        end::month = month1;
        end::day = day1;
    }
    else if (year1 == year2) {
        if (month1 == month2) {
            if (day1 == day2) {
                start::year = year2;
                start::month = month2;
                start::day = day2;
                end::year = year1;
                end::month = month1;
                end::day = day1;
            }
            else if (day1 > day2){
                start::year = year2;
                start::month = month2;
                start::day = day2;
                end::year = year1;
                end::month = month1;
                end::day = day1;
            }
            else if (day2 > day1) {
                start::year = year1;
                start::month = month1;
                start::day = day1;
                end::year = year2;
                end::month = month2;
                end::day = day2;
            }
        }
        else if (month1 > month2) {
            start::year = year2;
            start::month = month2;
            start::day = day2;
            end::year = year1;
            end::month = month1;
            end::day = day1;
        }
        else if (month2 > month1){
            start::year = year1;
            start::month = month1;
            start::day = day1;
            end::year = year2;
            end::month = month2;
            end::day = day2;
        }
    }
    else if (year2 > year1) {
        start::year = year1;
        start::month = month1;
        start::day = day1;
        end::year = year2;
        end::month = month2;
        end::day = day2;
    }
    return true;
}

int monthtoday(int month) {
    int day = 0;
#ifdef debugging
    static int count = 1;
#endif
    switch (month) {
        case 1:
            day = 0;
            break;
        case 2:
            day = 31;
            break;
        case 3:
            day = 59;
            break;
        case 4:
            day = 90;
            break;
        case 5:
            day = 120;
            break;
        case 6:
            day = 151;
            break;
        case 7:
            day = 181;
            break;
        case 8:
            day = 212;
            break;
        case 9:
            day = 243;
            break;
        case 10:
            day = 273;
            break;
        case 11:
            day = 304;
            break;
        case 12:
            day = 334;
            break;
    }
#ifdef debugging
    std::cerr << "\nmonthtoday " << count << " day: \n" << day << ' ' << '\n';
    ++count;
#endif
    return day;
}

int resultscalculation(int years, int days, int months, int add = 0) {
    int results = years * 365 + days + add + months;
    return results;
}

int main() {
#ifdef debugging
    std::cerr << ">>>DEBUGGING MODE ON<<<\n";
#endif
    while (cindata()) {
#ifdef debugging
        std::cerr << "\nstart::year, start::month, start::day, end::year, end::month, end::day:\n" << start::year << ' ' << start::month << ' ' << start::day << ' ' << end::year << ' ' << end::month << ' ' << end::day << '\n';
#endif
        
        
        //year
        int start_year = start::year / 4;
        int end_year = end::year / 4;
#ifdef debugging
        std::cerr << "\nstart_year, end_year, end_year - start_year:\n" << start_year << ' ' << end_year << ' ' << end_year - start_year << '\n';
#endif
        int add = 0;
        if ((end::year % 4 == 0 && end::month > 2 && start::month < 3) || (end_year - start_year > 0)){
            if (start::year % 4 == 0 && (start::month < 2 || (start::month == 2 && start::day <= 28)) && end::month > 2) {
                add = end_year - start_year + 1;
            }
            else if (start::year == end::year) {
                add = end_year - start_year + 1;
            }
            else {
                add = end_year - start_year;
            }
            if ((start::month == 2 && start::day == 29) || (end::month == 2 && end::day == 29)) {
                --add;
            }
        }
        int everyhundredyears;
        int everyfourhundredyears;
        everyhundredyears = end_year / 25 - start_year / 25;
        everyfourhundredyears = end_year / 100 - start_year /100;
        add = add - everyhundredyears + everyfourhundredyears;
#ifdef debugging
        std::cerr << "\neveryhundredyears, everyfourhundredyears:\n" << everyhundredyears << ' ' << everyfourhundredyears << '\n';
        std::cerr << "\nadd:\n" << add << '\n';
#endif
        calculation::year = end::year - start::year;
#ifdef debugging
        std::cerr << "\ncalculation::year:\n" << calculation::year << '\n';
#endif
        
         
        //month
        for (int loopcount = 1; loopcount <= 2; ++loopcount) {
            int month = 0;
            switch (loopcount) {
                    
                case 1:
                    month = start::month;
                    calculation::start_month_to_day = monthtoday(month);
#ifdef debugging
                    std::cerr << "\ncalculation::start_month_to_day:\n" << calculation::start_month_to_day << '\n';
#endif
                    break;
                    
                case 2:
                    month = end::month;
                    calculation::end_month_to_day = monthtoday(month);
#ifdef debugging
                    std::cerr << "\ncalculation::end_month_to_day:\n" << calculation::end_month_to_day << '\n';
#endif
                    break;
            }
        }
        calculation::month = calculation::end_month_to_day - calculation::start_month_to_day;
#ifdef debugging
        std::cerr << "\ncalculation::month:\n" << calculation::month << '\n';
#endif
        
        
        //day
        calculation::day = end::day - start::day;
#ifdef debugging
        std::cerr << "\ncalculation::day:\n" << calculation::day << '\n';
#endif
        
        
        //results
#ifdef debugging
        std::cerr << "\nresult::day: \n";
#endif
        result::day = resultscalculation(calculation::year, calculation::day, calculation::month, add);
        std::cout << result::day << '\n';
#ifdef debugging
        std::cerr << "\n------------DEBUGGING SESSION ENDED------------\n";
#endif
    }
}
