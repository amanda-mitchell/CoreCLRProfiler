# CoreCLR Profiler for OS X (and maybe Linux)

This repository contains a minimal CoreCLR profiler demonstrating that the
Profiling API actually works.

## Build It

1. Download the latest release of .NET Core
2. Clone the [CoreCLR](https://github.com/dotnet/coreclr) repository.
3. Clone this repo.
4. Run `make.sh`. (set environment variables as necessary; most notably `CORECLR_PATH` should point to the Core CLR repo from step 2)
5. Profit.

## Use it

Navigate to a .NET project and run it like this:

```
CORECLR_PROFILER={912E73AF-F51D-4E80-894D-F4E9E6DD7C2E} CORECLR_ENABLE_PROFILING=1 CORECLR_PROFILER_PATH=~/coreclrprofiler/profiler.dylib dotnet run
```

With the appropriate location of your profiler.

If you don't have an existing project, `dotnet new && dotnet restore && dotnet build` should give you a reasonable starting point.
