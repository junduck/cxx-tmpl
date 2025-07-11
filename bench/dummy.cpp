#include <benchmark/benchmark.h>

#include "dev/utils.hpp"

static void bench0(benchmark::State &state) {
  for (auto _ : state) {
    auto r = utils::make_unif_range(10, 0, 100);
    for (auto v : r) {
      benchmark::DoNotOptimize(v); // Prevent optimization of the loop
    }
  }
}
BENCHMARK(bench0);

BENCHMARK_MAIN();
