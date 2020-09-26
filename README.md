# Zeta2d

An SDL2 based 2D game engine with Lua scripting.

## Installation

Install [clangd](https://clangd.llvm.org/installation.html).

## Building

`mkdir` `build` folder. `cd` into `build` folder and run

```
cmake ..
make
```

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json .
```
