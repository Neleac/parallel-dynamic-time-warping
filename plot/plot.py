import pandas as pd
import matplotlib.pyplot as plt


fname = "diag-speedup.txt"

df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)
print("var names =", var_names)

problem_sizes = df[var_names[0]].values.tolist()
p2 = df[var_names[1]].values.tolist()
p4 = df[var_names[2]].values.tolist()
p8 = df[var_names[3]].values.tolist()
p16 = df[var_names[4]].values.tolist()
p32 = df[var_names[5]].values.tolist()
variable = df[var_names[6]].values.tolist()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(10)

plt.title("Speedup w.r.t. Diagonal Traversal")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(p2, "r-+")
plt.plot(p4, "g-+")
plt.plot(p8, "b-+")
plt.plot(p16, "c-+")
plt.plot(p32, "m-+")
plt.plot(variable, "y-+")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Size")
plt.ylabel("Speedup")

varNames = var_names[1:]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

plt.show()