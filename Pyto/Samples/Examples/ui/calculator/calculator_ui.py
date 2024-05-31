import pyto_ui as ui
from enum import Enum


class Console(ui.Label):
    """
    The label containing the output and input of the calculator.
    """
    
    @ui.Label.text.setter
    def text(self, new_value: str):
        if new_value.endswith(".0"): # Remove .0
            new_value = new_value[:-2]
        
        ui.Label.text.fset(self, new_value)


class Operation(Enum):
    """
    The name of each operation button.
    """
    
    MINUS_PLUS = "minus_plus"
    ADDITION = "addition"
    SUBSTRACTION = "substraction"
    MULTIPLICATION = "multiplication"
    DIVISION = "division"
    MODULO = "modulo"
    RESULT = "result"


def operation(symbol: str) -> Operation:
    """
    Returns the name of the button corresponding to the given math symbol.
    """
    
    match symbol:
        case "+":
            return Operation.ADDITION
        case "-":
            return Operation.SUBSTRACTION
        case "*":
            return Operation.MULTIPLICATION
        case "/":
            return Operation.DIVISION
        case "%":
            return Operation.MODULO
        case "\r" | "\n" | "=":
            return Operation.RESULT
    
    return None

class Calculator(ui.View):
    """
    The calculator.
    """
    
    console: Console
    
    def ib_init(self):
        self.number = ""
        self.operation = ""
    
    def key_press_ended(self, key: ui.Key):
        op = operation(key.characters)
        if op is not None:
            self.handle_operation(op) # Operation
        elif key.characters != "":
            self.write(key.characters) # Write number
    
    @ui.ib_action
    def clear(self, sender: ui.Button):
        """
        Clears the screen.
        """
        
        self.number = ""
        self.operation = ""
        self.console.text = "0"
    
    def write(self, number: str):
        """
        Writes the given number to the console.
        """
        
        self.number += number
        self.console.text = self.number
    
    def handle_operation(self, operation: Operation):
        """
        Handles the given operation.
        """
        
        if operation != Operation.MINUS_PLUS: 
            # Calculate the previous operation before doing something else
            # if we pressed "=", we do nothing else after
            self.operation += self.number
            self.operation = str(eval(self.operation))
            self.console.text = self.operation
            self.number = ""
            
        match operation: # Write the symbol
            case Operation.ADDITION:
                self.operation += "+"
            case Operation.SUBSTRACTION:
                self.operation += "-"
            case Operation.MULTIPLICATION:
                self.operation += "*"
            case Operation.DIVISION:
                self.operation += "/"
            case Operation.MODULO:
                self.operation += "%"
            case Operation.MINUS_PLUS: # Multiply by -1 the current number
                if self.number != "":
                    self.number = str(float(-1) * float(self.number))
                    self.console.text = self.number
                else:
                    self.operation = str(float(-1) * float(self.operation))
                    self.console.text = self.operation
    
    @ui.ib_action
    def on_press(self, sender: ui.Button):
        if sender.name == "" or sender.name is None: # Number
            self.write(sender.title)

        else: # Operation
            self.handle_operation(Operation(sender.name))
            
