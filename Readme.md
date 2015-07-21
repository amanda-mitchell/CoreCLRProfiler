# CoreCLR Profiler for OS X (and maybe Linux)

This repository contains a minimal CoreCLR profiler demonstrating that the
Profiling API actually works.

NOTE: This only works if you build CoreCLR with the Profiling API enabled.
See the [relevant GitHub issue](https://github.com/dotnet/coreclr/issues/445)
for more details.

## Build It

1. Get CoreCLR building/running on your machine.
2. Clone this repo.
3. Run `make.sh`. (set environment variables as necessary)
4. Profit.

## Use it

Run something like

```
CORECLR_PROFILER={912E73AF-F51D-4E80-894D-F4E9E6DD7C2E} CORECLR_ENABLE_PROFILING=1 CORECLR_PROFILER_PATH=~/coreclrprofiler/profiler.dylib corerun HelloWorld.exe
```

With appropriate values for the location of your profiler, `corerun`, and a managed executable.
