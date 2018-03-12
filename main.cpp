#include <benchmark\benchmark.h>
#include <cmath>
#include "test.h"

static void BM_acos(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(acos(state.range(0)));
}
BENCHMARK(BM_acos)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_atan(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(atan(state.range(0)));
}
BENCHMARK(BM_atan)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_cosh(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(cosh(state.range(0)));
}
BENCHMARK(BM_cosh)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_tanh(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(tanh(state.range(0)));
}
BENCHMARK(BM_tanh)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_pow(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize( pow(state.range(0), 1027) );
}
BENCHMARK(BM_pow)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_modf(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(fmodf((float)state.range(0), 1.6180319));
}
BENCHMARK(BM_modf)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_log(benchmark::State& state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(log2(state.range(0)));
}
BENCHMARK(BM_log)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_sine(benchmark::State& state) {
    for (auto _ : state)
            benchmark::DoNotOptimize(sin(state.range(0)));
}
BENCHMARK(BM_sine)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void BM_memcpy(benchmark::State& state) {
    char* src = new char[state.range(0)];
    char* dst = new char[state.range(0)];
    memset(src, 'x', state.range(0));
    for (auto _ : state)
        memcpy(dst, src, state.range(0));
    state.SetBytesProcessed(int64_t(state.iterations()) *
        int64_t(state.range(0)));
    state.SetComplexityN(state.range(0));
    delete[] src;
    delete[] dst;
}
BENCHMARK(BM_memcpy)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10)->Complexity(benchmark::oN);

static void BM_StringCompare(benchmark::State& state) {
    std::string s1(state.range(0), '-');
    std::string s2(state.range(0), '-');
    for (auto _ : state) {
        benchmark::DoNotOptimize(s1.compare(s2));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StringCompare)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);

BENCHMARK_MAIN();
