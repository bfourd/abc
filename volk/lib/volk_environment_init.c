/*this file is auto_generated by volk_register.py*/

#include<volk/volk_environment_init.h>
#include<volk/volk_config.h>
#if LV_HAVE_SSE
#include<xmmintrin.h>
#endif
#if LV_HAVE_SSE3
#include<pmmintrin.h>
#endif


void volk_environment_init(){
#if LV_HAVE_SSE
        _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
#endif
#if LV_HAVE_SSE3
        _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
#endif
}
