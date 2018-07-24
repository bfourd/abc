#ifndef INCLUDED_volk_32f_sqrt_32f_a16_H
#define INCLUDED_volk_32f_sqrt_32f_a16_H

#include <inttypes.h>
#include <stdio.h>
#include <math.h>

#if LV_HAVE_SSE
#include <xmmintrin.h>
/*!
  \brief Sqrts the two input vectors and store their results in the third vector
  \param cVector The vector where the results will be stored
  \param aVector One of the vectors to be sqrted
  \param num_points The number of values in aVector and bVector to be sqrted together and stored into cVector
*/
static inline void volk_32f_sqrt_32f_a16_sse(float* cVector, const float* aVector, unsigned int num_points){
    unsigned int number = 0;
    const unsigned int quarterPoints = num_points / 4;

    float* cPtr = cVector;
    const float* aPtr = aVector;

    __m128 aVal, cVal;
    for(;number < quarterPoints; number++){
      
      aVal = _mm_load_ps(aPtr); 
      
      cVal = _mm_sqrt_ps(aVal); 
      
      _mm_store_ps(cPtr,cVal); // Store the results back into the C container

      aPtr += 4;
      cPtr += 4;
    }

    number = quarterPoints * 4;
    for(;number < num_points; number++){
      *cPtr++ = sqrtf(*aPtr++);
    }
}
#endif /* LV_HAVE_SSE */

#if LV_HAVE_GENERIC
/*!
  \brief Sqrts the two input vectors and store their results in the third vector
  \param cVector The vector where the results will be stored
  \param aVector One of the vectors to be sqrted
  \param num_points The number of values in aVector and bVector to be sqrted together and stored into cVector
*/
static inline void volk_32f_sqrt_32f_a16_generic(float* cVector, const float* aVector, unsigned int num_points){
    float* cPtr = cVector;
    const float* aPtr = aVector;
    unsigned int number = 0;

    for(number = 0; number < num_points; number++){
      *cPtr++ = sqrtf(*aPtr++);
    }
}
#endif /* LV_HAVE_GENERIC */

#if LV_HAVE_ORC
extern void volk_32f_sqrt_32f_a16_orc_impl(float *, const float*, unsigned int);
/*!
  \brief Sqrts the two input vectors and store their results in the third vector
  \param cVector The vector where the results will be stored
  \param aVector One of the vectors to be sqrted
  \param num_points The number of values in aVector and bVector to be sqrted together and stored into cVector
*/
static inline void volk_32f_sqrt_32f_a16_orc(float* cVector, const float* aVector, unsigned int num_points){
    volk_32f_sqrt_32f_a16_orc_impl(cVector, aVector, num_points);
}

#endif /* LV_HAVE_ORC */



#endif /* INCLUDED_volk_32f_sqrt_32f_a16_H */
