"""
Save an array for debugging purposes.
"""
import numpy as np

mask_loc = "/tmp/mask.bin"
n_frames = 10
h = 18  # Dimensions for park scene video.
w = 30

def save_array(arr, path):
    with open(path, "w") as fid:
        arr.tofile(fid)

if __name__ == '__main__':
    arr = np.zeros((n_frames, h, w)).astype('float32')
    for i in range(n_frames):
        arr[i] = (i + 1) * 0.25   
    save_array(arr, mask_loc)