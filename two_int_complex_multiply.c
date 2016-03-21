#include <stdio.h>
#include "emmintrin.h"
#include <stdint.h>

int16_t conjugate[8] __attribute__((aligned(16))) = {1,-1,1,-1,1,-1,1,-1};

void two_int_complex_multiply(int16_t *inputa, int16_t *inputb, int length, int16_t *output, int16_t shift)
{
	/*
	 *	inputa: RE(16 bit),IM(16 bit); RE(16 bit),IM(16 bit)
	 *	inputb: RE(16 bit),IM(16 bit); RE(16 bit),IM(16 bit)
	 *	output: RE(16 bit),IM(16 bit); RE(16 bit),IM(16 bit)
	 */

	__m128i *a128 = (__m128i *) inputa;
	__m128i *b128 = (__m128i *) inputb;
	__m128i *o128 = (__m128i *) output;

	__m128i mmtmp_re, mmtmp_im, mmtmp_lo, mmtmp_hi;

	mmtmp_re = _mm_sign_epi16(*b128, *(__m128i*)&conjugate[0]);
	mmtmp_re = _mm_madd_epi16(*a128, mmtmp_re);

	mmtmp_im = _mm_shufflelo_epi16(*b128, _MM_SHUFFLE(2,3,0,1));
	mmtmp_im = _mm_shufflehi_epi16(mmtmp_im, _MM_SHUFFLE(2,3,0,1));
	mmtmp_im = _mm_madd_epi16(*a128, mmtmp_im);

	mmtmp_re = _mm_srai_epi32(mmtmp_re, shift);
	mmtmp_im = _mm_srai_epi32(mmtmp_im, shift);
	
	mmtmp_lo = _mm_unpacklo_epi32(mmtmp_re,mmtmp_im);
	mmtmp_hi = _mm_unpackhi_epi32(mmtmp_re,mmtmp_im);
	o128[0]  = _mm_packs_epi32(mmtmp_lo,mmtmp_hi);

	a128 ++;
	b128 ++;
	o128 ++;

}
int main(int argc, char *argv[])
{


	return 0;
}
