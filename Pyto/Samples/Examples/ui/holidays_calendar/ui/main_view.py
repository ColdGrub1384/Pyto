from ..menu import CountriesMenu, YearMenu
from ..cal import get_current_year, get_holidays, Holiday
from .holiday_view import HolidayView
import pyto_ui as ui
import sf_symbols as sf
import userkeys as uk
import os.path


SELECTED_COUNTRY_KEY = "HOLIDAYS_CALENDAR_SELECTED_COUNTRY"
SELECTED_SUBDIV_KEY = "HOLIDAYS_CALENDAR_SELECTED_SUBDIV"

HOLIDAY_VIEW_PATH = os.path.join(os.path.dirname(__file__), "holiday.pytoui")

class HolidayCell(ui.TableViewCell):
    
    def __init__(self, holiday: Holiday):
        date = holiday.date.strftime("%d %B")
        self.holiday = holiday
        
        super().__init__(text=date, detail=self.holiday.name)
        self.detail_text_label.text_color = ui.SystemColors.SECONDARY_LABEL
        self.image_view.image = ui.image_with_system_name(sf.CLOCK_FILL)
        self.image_view.tint_color = ui.SystemColors.SECONDARY_LABEL
        
        self.accessory_type = ui.AccessoryType.DISCLOSURE_INDICATOR


class CalendarView(ui.View):
    
    year_menu: ui.Button
    
    table_view: ui.TableView
    
    holiday_view: ui.NavigationView
    
    year: int
    
    country: str
    
    subdiv: str
    
    def ib_init(self):
        try:
            self.country = uk.get(SELECTED_COUNTRY_KEY)
        except KeyError:
            self.country = None
            
        try:
            self.subdiv = uk.get(SELECTED_SUBDIV_KEY)
        except KeyError:
            self.subdiv = None
        
        self.year = get_current_year()
        
        self.year_menu.menu = MainMenu(self)
        self.year_menu.menu_primary_action = True
        
        self.holidays = None
        
        self.holiday_view = ui.read(HOLIDAY_VIEW_PATH)
        
    def did_appear(self):
        self.load()
        self.table_view.did_select_cell = self.did_select_cell
    
    def did_select_cell(self, section: ui.TableViewSection, index: int):
        holiday = section.cells[index].holiday
        self.holiday_view.root_view.set_holiday(holiday)
        self.holiday_view.size = ui.SheetSize.IPHONE_MEDIUM
        
        self.table_view.deselect_row()
        
        ui.show_view(self.holiday_view, ui.PresentationMode.SHEET)
    
    def load(self):
        
        self.title = str(self.year)
        
        if not self.country:
            return
        
        uk.set(self.country, SELECTED_COUNTRY_KEY)
        uk.set(self.subdiv, SELECTED_SUBDIV_KEY)
        
        description = self.country + " - "+str(self.year)
        self.year_menu.title = description
        self.year_menu.size_to_fit()
        
        holidays = get_holidays(self.year, self.country, self.subdiv)
        self.holidays = holidays
        cells = map(HolidayCell, holidays)
        
        months_added = ()
        months = ()
        for cell in cells:
            date = cell.holiday.date
            if date.month in months_added:
                months[-1].cells += (cell,)
            else:
                month_name = date.strftime("%B")
                months += (ui.TableViewSection(month_name, [cell]),)
                months_added += (date.month,)
        
        self.table_view.sections = months


class CloseAction(ui.MenuAction):
    
    def attributes(self):
        return ui.MenuElementAttributes.DESTRUCTIVE
    
    def title(self):
        return "Close"
    
    def symbol_name(self):
        return sf.XMARK


class MainMenu(ui.Menu):
    
    def __init__(self, view: CalendarView):
        self.view = view
        super().__init__()
    
    def title(self):
        return ""
    
    def children(self):
        return (
            ui.Menu(
                title="Holidays",
                options=ui.MenuOptions.DISPLAY_INLINE, children=(
                    CountriesMenu(self.view),
                    YearMenu(self.view),
            )),
            CloseAction(action=self.view.close)
        )
