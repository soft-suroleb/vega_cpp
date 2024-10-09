#include <benchmark/benchmark.h>
#include "addition.hpp"

static void BenchAddition(benchmark::State& state) {
    while (state.KeepRunning()) {
        add(state.range(0), state.range(1));
    }
}

BENCHMARK(BenchAddition)
    ->Args({10, 5})
    ->Args({-4, 10})
    ->Args({0, 0})
    ->Args({-10, -20})
    ->Args({-10, 20})
    ->Args({10, -20});

BENCHMARK_MAIN();
