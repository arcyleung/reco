# Recombinant

## Demo to automatically detect and replace intrinsics with highest supported level in OS

### Requirements
```bash
python -m pip install -r requirements.txt
```

### Run Recombinant Tool
```bash
python recombinant.py -i source.cpp -o recombinant.cpp --target=[sse|avx|avx512]


```

### Run Benchmark (Test SSE, AVX, AVX512)
```bash
./run_benchmark.sh
```
