import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import subprocess 

img = mpimg.imread('assets/mikolaj_squat.png')

plt.imshow(img)
plt.title("Click 2 times: 1. Hip, 2. Knee")
print("Waiting for your clicks.")

points = plt.ginput(2) 
plt.close()

terminal_command = ['.\\eng.exe']

for x, y in points:
    norm_x = x / img.shape[1]
    norm_y = y / img.shape[0]
    terminal_command.append(str(norm_x))
    terminal_command.append(str(norm_y))

subprocess.run(terminal_command)