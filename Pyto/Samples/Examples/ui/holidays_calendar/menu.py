import holidays
import pyto_ui as ui
import sf_symbols as sf
from .cal import get_current_year
from dataclasses import dataclass

class CalendarView(ui.View):
    
    year: int
    country: str
    subdiv: str
    
    def load(self): pass

@dataclass
class Country:
    code: str
    name: str
    subdiv: tuple[str]


def country_name(a: Country) -> str:
    return a.name


def get_countries() -> tuple[Country]:
    countries_raw = holidays.utils.list_supported_countries()
    countries = ()
    
    for (code, subdiv) in countries_raw.items():
        name = holidays.country_holidays(code).__class__.__base__.__name__
        countries += (Country(code, name, subdiv),)
    
    return sorted(countries, key=country_name)


class TerritoryAction(ui.MenuAction):
    
    def __init__(self, country: Country, view: CalendarView, subdiv: str = None):
        self.country = country
        self.subdiv = subdiv
        self.view = view
        super().__init__()
    
    def title(self):
        if self.subdiv:
            return self.subdiv
        else:
            return self.country.name
        
    def subtitle(self):
        if self.subdiv:
            return self.country.name
        else:
            return self.country.code
    
    def symbol_name(self):
        if self.subdiv:
            return sf.MAPPIN
        else:
            return sf.GLOBE
    
    def state(self):
        if self.view.country == self.country.code and self.view.subdiv == self.subdiv:
            return ui.MenuElementState.ON
        else:
            return ui.MenuElementState.OFF
    
    def action(self):
        self.view.country = self.country.code
        self.view.subdiv = self.subdiv
        self.view.load()


class SubdivMenu(ui.Menu):
    
    def __init__(self, country: Country, view: CalendarView):
        self.country = country
        self.view = view
        super().__init__()
    
    def title(self):
        return self.country.name
        
    def subtitle(self):
        return self.country.code
    
    def symbol_name(self):
        if self.view.country == self.country.code:
            return sf.CHECKMARK
        else:
            return sf.GLOBE
    
    def children(self):
        actions = ()
        
        for subdiv in self.country.subdiv:
            actions += (TerritoryAction(self.country, self.view, subdiv),)

        return actions


class CountriesMenu(ui.Menu):
    
    def __init__(self, view: CalendarView):
        self.view = view
        super().__init__()
    
    def title(self):
        return "Country"
    
    def symbol_name(self):
        return sf.GLOBE
    
    def children(self):
        countries = get_countries()
        actions = ()
        
        for country in countries:
            if len(country.subdiv) > 0:
                actions += (SubdivMenu(country, self.view),)
            else:
                actions += (TerritoryAction(country, self.view),)
        
        return actions


class YearMenu(ui.Menu):
    
    def __init__(self, view: CalendarView):
        self.view = view
        self.__children = None
        super().__init__()
    
    def title(self):
        return "Year"
    
    def symbol_name(self):
        return sf.CALENDAR
    
    def select(self, action: ui.MenuAction):
        self.view.year = int(action.title)
        self.view.load()
    
    def children(self):
        actions = ()
        
        for i in range(1950, get_current_year()+1):
            
            if self.view.year == i:
                state = ui.MenuElementState.ON
            else:
                state = ui.MenuElementState.OFF
            
            actions = (
                ui.MenuAction(
                    title=str(i),
                    symbol_name=sf.CALENDAR,
                    state=state,
                    action=self.select
                ),
            )+actions
        
        return actions
        