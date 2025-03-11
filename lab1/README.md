# How to use?

## Note

all commands should be executed in `($your_path)/Algorithms-labs/lab1/` dir

## do statistics 

```bash
# use quickfind
make qf

# or if you want to use weighted quick union
make wqu

# if you want to remove executable files
make clean
```

## Visualization 

```bash
make visual
```

## test Time Complexity

1. Uncommented `// cout << "Execution time of main function: " << duration.count() << " microseconds" << endl;` in `quickfind.cpp`
2. Uncommented `// cout << "Execution time of main function: " << duration.count() << " microseconds" << endl;` in `weightedQuickUnion.cpp`
3. run `make qfTime` or `make wquTime`

if you want to verify time complexity, you need to modify 

1. `N` in both `macro.h` and `statistics.py`
2. `t` in `statistics.py`
