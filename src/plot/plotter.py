import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# TODO: replace with the actual code
x = np.arange(10)
ys = [i+x+(i*x)**2 for i in range(10)]

colors = iter(cm.rainbow(np.linspace(0, 1, len(ys))))
for y in ys:
    plt.scatter(x, y, color=next(colors), label=r"$\Delta$")

plt.legend(shadow=True, fancybox=True)
plt.ylabel('Download time (us)')
plt.xlabel('File size (B)')
plt.show()
# plt.savefix("filename.png", bbox_inches='tight')
