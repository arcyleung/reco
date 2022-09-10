#!/bin/bash

clang -g -O0 -msse4.2 -DSSE test_vec.cpp -lstdc++ -ldl -lm -o test_vec_sse.out && hyperfine ./test_vec_sse.out 
clang -g -O0 -mavx -DAVX test_vec.cpp -lstdc++ -ldl -lm -o test_vec_avx.out && hyperfine ./test_vec_avx.out 
clang -g -O0 -mavx512f -DAVX512 test_vec.cpp -lstdc++ -ldl -lm -o test_vec_avx512.out && hyperfine ./test_vec_avx512.out
