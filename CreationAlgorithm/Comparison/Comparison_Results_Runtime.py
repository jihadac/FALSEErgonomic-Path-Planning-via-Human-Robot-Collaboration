import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from matplotlib.ticker import MultipleLocator
from matplotlib.ticker import FuncFormatter
from openpyxl import load_workbook
import numpy as np


num_lines = 3

line_color = ['red', 'blue', 'green']
# Create custom legend handles
legend_handles = [Line2D([0], [0], color=color, marker='o', linestyle='', label=f'$h_{i+1}$') for i, color in enumerate(line_color[:num_lines])]

categories = ['Graph 1', 'Graph 2', 'Graph 3']

# Set the width of each line
line_width = 0.4

# Load workbook
workbook = load_workbook('C:/Users\jihad\Documents\VUB\Master 2\Master Thesis/Comparison.xlsx',data_only=True)
worksheet = workbook['Workspace1']

# Workspace 1
desired_columns = ['C','D','E']
list_workspace1 = []
list_h = []

for name in desired_columns:
    for i in range(84,164):
        cell_value = worksheet[name + str(i)].value
        list_h.append(cell_value)
    list_workspace1.append(list_h)
    list_h =[]
    
# Workspace 2
worksheet = workbook['Workspace2']

desired_columns = ['C','D','E']
list_workspace2 = []
list_h = []

for name in desired_columns:
    for i in range(36,68):
        cell_value = worksheet[name + str(i)].value
        list_h.append(cell_value)
    list_workspace2.append(list_h)
    list_h = []

# Workspace 3
worksheet = workbook['Workspace3']

desired_columns = ['C','D','E']
list_workspace3 = []
list_h = []

for name in desired_columns:
    for i in range(69,134):
        cell_value = worksheet[name + str(i)].value
        list_h.append(cell_value)
    list_workspace3.append(list_h)
    list_h = []


# Generate a numeric range for the x-axis
x = np.arange(len(categories))
positions = [0,2,4]
width = 0.6

# Plotting
fig, ax = plt.subplots()


# Plot boxplots
ax.boxplot([list_workspace1[0],list_workspace2[0],list_workspace3[0]], positions=[positions[0]-width,positions[1]-width,positions[2]-width], widths=0.3, whiskerprops=dict(color=line_color[0]), capprops=dict(color=line_color[0]),boxprops=dict(color=line_color[0]),medianprops=dict(color=line_color[0]), flierprops=dict(markeredgecolor=line_color[0]))
ax.boxplot([list_workspace1[1],list_workspace2[1],list_workspace3[1]], positions=[positions[0],positions[1],positions[2]], widths=0.3, whiskerprops=dict(color=line_color[1]), capprops=dict(color=line_color[1]),boxprops=dict(color=line_color[1]),medianprops=dict(color=line_color[1]), flierprops=dict(markeredgecolor=line_color[1]))
ax.boxplot([list_workspace1[2],list_workspace2[2],list_workspace3[2]], positions=[positions[0]+width,positions[1]+width,positions[2]+width], widths=0.3, whiskerprops=dict(color=line_color[2]), capprops=dict(color=line_color[2]),boxprops=dict(color=line_color[2]),medianprops=dict(color=line_color[2]), flierprops=dict(markeredgecolor=line_color[2]))

# Set x-axis labels
ax.set_xticks(positions)
ax.set_xticklabels(categories, rotation=0)

ax.yaxis.set_major_locator(MultipleLocator(0.0002))
ax.yaxis.set_minor_locator(MultipleLocator(0.0001))

scale_factor = 1e-4

# Define a function to format the y-axis tick labels
def format_yticks(x, pos):
    return f'{x / scale_factor:.0f}'

# Set the y-axis tick labels using the formatter function
ax.yaxis.set_major_formatter(FuncFormatter(format_yticks))

# Add a text label at the top of the y-axis
ax.text(0, 1, r'$\times 10^{-4}$', transform=ax.transAxes, ha='right', va='bottom')


# Set y-axis label
ax.set_ylabel('Difference in runtime (s)')

# Set plot title
ax.set_title('Differences in runtime between Dijkstra and A*')

# Add legend with custom handles
ax.legend(handles=legend_handles,handlelength=0.5, labelspacing=0.2)

# Add grid
#ax.grid(which = 'both', axis="y",linestyle='--')
ax.grid(True, which='major', axis='y', linestyle='-')
ax.grid(True, which='minor', axis='y', linestyle='--')
# Increase distance between frame and first tick on x-axis
ax.set_xlim(-1, 5)

# Display the plot
plt.show()
