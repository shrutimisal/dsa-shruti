import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = {
    "Month" : ["Jan","Feb","Mar","Apr","May"],
    "Sales" : [100,450,400,323,500]
}

df = pd.DataFrame(data)
print("Sales Data :")
print(df)

total_sales = np.sum(df["Sales"])
avg_sales = np.mean(df["Sales"])

print("\nAverage Marks:", avg_sales)
print("Total Sales:", total_sales)

plt.plot(df["Month"],df["Sales"])
plt.xlabel("Month")
plt.ylabel("Sales")
plt.title("Monthly Sales Report")
plt.show()
