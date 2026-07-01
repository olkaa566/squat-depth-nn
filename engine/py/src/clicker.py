import matplotlib.pyplot as plt
import matplotlib.image as mpimg

image = mpimg.imread('assets/test_squat.png')

plt.imshow(image)
plt.title("Click on knee, hip, ankle. Middle-click to stop.")

print("Waiting for clicks.")
coordinates = plt.ginput(n =- 1, timeout = 0) 

plt.close()

print("\nYou clicked these exact coordinates (X, Y):")
for point in coordinates:
    print(point)