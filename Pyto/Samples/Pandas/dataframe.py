"""
An example of Pandas DataFrame.

Taken from https://www.tutorialspoint.com/python_pandas/python_pandas_dataframe
"""

import pandas as pd

data = [['Alex',10],['Bob',12],['Clarke',13]]
df = pd.DataFrame(data,columns=['Name','Age'])
print(df)
