import pandas as pd

marks = pd.Series([1, 2, 3, 4, 5])
s = pd.Series([10, 20, 30], index=["A", "B", "C"])
print(marks)
print(s) 