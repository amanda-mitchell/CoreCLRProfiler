# CoreCLR Profiler for OS X (and maybe Linux)

This repository contains a minimal CoreCLR profiler demonstrating that the
Profiling API actually works.

## Build It

1. Get CoreCLR building/running on your machine.
2. Clone this repo.
3. Run `make.sh`. (set environment variables as necessary)
4. Profit.

## Use it

Run something like

```
CORECLR_PROFILER={912E73AF-F51D-4E80-894D-F4E9E6DD7C2E} CORECLR_ENABLE_PROFILING=1 CORECLR_PROFILER_PATH=~/coreclrprofiler/profiler.dylib ./corerun HelloWorld.exe
```

`CORECLR_PROFILER` must be set to any valid GUID for the Profiler to be loaded. This requirement will be removed in the future.
