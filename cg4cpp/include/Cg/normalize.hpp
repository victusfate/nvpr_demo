/* 
 * Copyright 2005 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 */

#ifndef __Cg_normalize_hpp__
#define __Cg_normalize_hpp__

#ifdef __Cg_stdlib_hpp__
#pragma message("error: include this header file (" __FILE__ ") before <Cg/stdlib.hpp>")
#endif

#include <Cg/vector.hpp>

#include <cmath>  // for std::sqrt

namespace Cg {

template <typename T, int N>
static inline __CGvector<typename __CGtype_trait<T>::realType,N> normalize(const __CGvector<T,N> & v)
{
    typename __CGtype_trait<T>::dotType sum = v[0] * v[0];
    for (int i=1; i<N; i++)
        sum += v[i] * v[i];
    return __CGvector<T,N>(v / std::sqrt(sum));
}
template <typename T, int N, typename Tstore>
static inline __CGvector<typename __CGtype_trait<T>::realType,N> normalize(const __CGvector_usage<T,N,Tstore> & v)
{
    typename __CGtype_trait<T>::dotType sum = v[0] * v[0];
    for (int i=1; i<N; i++)
        sum += v[i] * v[i];
    return __CGvector<T,N>(v / std::sqrt(sum));
}

} // namespace Cg

#endif // __Cg_normalize_hpp__
