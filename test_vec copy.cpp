#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dist(1, 10e14);

#ifdef __AVX__
  #include <immintrin.h>
#else
  #warning No AVX support - will not compile
#endif


#ifdef AVX
void run_avx() {
    for(int i = 0; i < 100000; i++) {
      __m256 a = _mm256_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );
      __m256 b = _mm256_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );

      __m256 c = _mm256_add_ps(a, b);

      float d[8];
      _mm256_storeu_ps(d, c);

      // std::cout << "result equals " << 
      //           d[0] << "," <<
      //           d[1] << "," <<
      //           d[2] << "," <<
      //           d[3] << "," <<
      //           d[4] << "," <<
      //           d[5] << "," <<
      //           d[6] << "," <<
      //           d[7] <<
      //           std::endl;
    }
}
#endif

#ifdef AVX512
void run_avx512() {
  for(int i = 0; i < 50000; i++) {
      __m512 a = _mm512_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );
      __m512 b = _mm512_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );

      __m512 c = _mm512_add_ps(a, b);

      float d[16];
      _mm512_storeu_ps(d, c);

      // std::cout << "result equals " << 
      //           d[0] << "," <<
      //           d[1] << "," <<
      //           d[2] << "," <<
      //           d[3] << "," <<
      //           d[4] << "," <<
      //           d[5] << "," <<
      //           d[6] << "," <<
      //           d[7] << "," <<
      //           d[8] << "," <<
      //           d[9] << "," <<
      //           d[10] << "," <<
      //           d[11] << "," <<
      //           d[12] << "," <<
      //           d[13] << "," <<
      //           d[14] << "," <<
      //           d[15] <<
      //           std::endl;
    }
}
#endif

#ifdef SSE
void run_sse() {
  for(int i = 0; i < 200000; i++) {
      __m128 a = _mm_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );
      __m128 b = _mm_set_ps(
          dist(gen),
          dist(gen),
          dist(gen),
          dist(gen)
        );

      __m128 c = _mm_add_ps(a, b);

      float d[4];
      _mm_storeu_ps(d, c);
  }
}
#endif

// AVX version
int main(int argc, char **argv)
{
    #ifdef AVX
      run_avx(); 
    #endif
    #ifdef AVX512
      run_avx512(); 
    #endif
    #ifdef SSE
      run_sse(); 
    #endif
    return 0;
}