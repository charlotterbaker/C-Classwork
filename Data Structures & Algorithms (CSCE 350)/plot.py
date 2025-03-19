import matplotlib.pyplot as plt # type: ignore

sizes = [10, 100, 1000]
times = [2e09, 4e09, 6e09]  # Replace with actual averages

plt.plot(sizes, times, marker='o')
plt.xlabel('Input Size')
plt.ylabel('Average Execution Time (microseconds)')
plt.title('QuickSort Average Execution Time')
plt.savefig('Baker_Charlotte_plotAverageExecutionTime.jpg')
plt.show()
