# Parallel Dynamic Time Warping

## Build
`mkdir build`

`cd build`

`cmake ../`

`make`

## Run

Runs on problem sizes 1000, 5000, 10000, 15000, 20000

Serial Row Traversal:

`./row-job`

Serial Diagonal Traversal:

`./diagonal-job`

Parallel Diagonal Traversal, fixed concurrency at 2, 4, 8, 16, 32 threads:

`./parallel-job`

Parallel Diagonal Traversal, varied concurrency:

`./variable-job`