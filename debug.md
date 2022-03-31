This repository contains x264 with the modification that you can pass in a file that specifies an importance per block.
The values stored in this file are positive floating point numbers. A value of 1 means no change. A value greater than one means put more emphasis on a block, a value less than 1 is less emphasis.  The weight can be thought of as modifying the loss function `distortion * w + lambda * bits` that determines the mode selection and QP for each macroblock.

Instructions to run the code and debug the code for an example file:

1. Build the code:

```
./configure --disable-interlaced --disable-thread
make -j 8
```
If you want to run the server, this is sufficient. If you want to debug the x264 code line by line, add the `--enable_debug` to the configure command. This may result in slower code.

2. Copy the test video.

```
cd <project_root>
mkdir data
cp <> data/ParkScene_480x288.y4m
```

3. Run the command at the top of `test_mask.c` -> this saves an example mask and tests loading it.

4. Run the command in the `launch.json` file.