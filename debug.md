Instructions to run the code for an example file:

1. Build the code:

```
./configure --disable-interlaced --enable-debug --disable-thread
make -j 8
```
2. Copy the test video.

```
cd <project_root>
mkdir data
cp <> data/ParkScene_480x288.y4m
```


3. Run the command at the top of `test_mask.c` -> this saves an example mask and tests loading it. 

4. Run the command in the `launch.json` file.