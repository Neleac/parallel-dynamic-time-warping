import numpy as np

problem_sizes = np.array([1000, 5000, 10000, 15000, 20000])

row_runtimes = np.array([0.00683828, 0.168952, 0.674809, 1.51823, 2.69993])
diagonal_runtimes = np.array([0.011101, 0.451838, 2.3914, 8.5937, 16.4217])

p2_runtimes = np.array([0.0144166, 0.188146, 1.07772, 4.14788, 8.67249])
p4_runtimes = np.array([0.0125162, 0.116085, 0.382651, 0.844103, 1.53497])
p8_runtimes = np.array([0.0130314, 0.0902386, 0.254491, 0.499425, 0.834749])
p16_runtimes = np.array([0.0169989, 0.092307, 0.225603, 0.391093, 0.60331])
p32_runtimes = np.array([0.0288144, 0.150234, 0.317891, 0.504815, 0.65444])
variable_runtimes = np.array([0.0194823, 0.101825, 0.269018, 0.503473, 0.816683])

p2_row_speedup = row_runtimes / p2_runtimes
p4_row_speedup = row_runtimes / p4_runtimes
p8_row_speedup = row_runtimes / p8_runtimes
p16_row_speedup = row_runtimes / p16_runtimes
p32_row_speedup = row_runtimes / p32_runtimes
variable_row_speedup = row_runtimes / variable_runtimes
print(p2_row_speedup)
print(p4_row_speedup)
print(p8_row_speedup)
print(p16_row_speedup)
print(p32_row_speedup)
print(variable_row_speedup)

print()

p2_diagonal_speedup = diagonal_runtimes / p2_runtimes
p4_diagonal_speedup = diagonal_runtimes / p4_runtimes
p8_diagonal_speedup = diagonal_runtimes / p8_runtimes
p16_diagonal_speedup = diagonal_runtimes / p16_runtimes
p32_diagonal_speedup = diagonal_runtimes / p32_runtimes
variable_diagonal_speedup = diagonal_runtimes / variable_runtimes
print(p2_diagonal_speedup)
print(p4_diagonal_speedup)
print(p8_diagonal_speedup)
print(p16_diagonal_speedup)
print(p32_diagonal_speedup)
print(variable_diagonal_speedup)