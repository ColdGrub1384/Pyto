from datetime import date, timedelta
from dataclasses import dataclass
import holidays
import calendar as cal


@dataclass
class Holiday:
    date: date
    name: str


def get_current_year() -> int:
    return date.today().year


def get_days(year: int) -> date:
    start_date = date(year, 1, 1) 
    end_date = date(year, 12, 31)

    delta = end_date - start_date
    
    days = ()
    for i in range(delta.days + 1):
        day = start_date + timedelta(days=i)
        days += (day,)
    
    return days


def get_holidays(year: int, country: str, subdiv: str = None) -> tuple[Holiday]:
    
    calendar = holidays.country_holidays(country, subdiv=subdiv)
    
    dates = ()
    
    days = get_days(year)
    for day in days:
        name = calendar.get(day)
        if name is None:
            continue
        
        dates += (Holiday(day, name),)
    
    return dates


