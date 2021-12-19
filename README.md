# onward

A C++ implementation of the Forth programming language

## Build

```sh
# Clone repository
git clone https://github.com/tetsuo-cpp/onward.git
cd onward/

# Configure CMake
cmake -B build/ -S .

# Build
cmake --build build/ -j

# Run interpreter
./build/tools/onward
```

## Features

```forth
ONWARD> 1 2
ONWARD> +
ONWARD> .
3
ONWARD> : add-five 5 + ;
ONWARD> 10
ONWARD> add-five
ONWARD> .s
[15]
```
