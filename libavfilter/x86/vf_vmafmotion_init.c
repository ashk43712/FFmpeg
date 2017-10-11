/*
 * Copyright (c) 2017 Ashish Pratap Singh <ashk43712@gmail.com>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
 
#include "libavutil/x86/cpu.h"

#include "libavfilter/vmaf_motion.h"

uint64_t ff_sad_sse3(const uint16_t *img1, const uint16_t *img2, int w, int h,
                        ptrdiff_t img1_stride, ptrdiff_t img2_stride);
void ff_convolution_x_sse3(const uint16_t *filter, int filt_w, const uint16_t *src,
                  uint16_t *dst, int w, int h, ptrdiff_t src_stride,
                  ptrdiff_t dst_stride);
void ff_convolution_y_sse3(const uint16_t *filter, int filt_w, const uint8_t *src,
                  uint16_t *dst, int w, int h, ptrdiff_t src_stride,
                  ptrdiff_t dst_stride);                        

void ff_vmafmotion_init_x86(VMAFMotionDSPContext *dsp)
{
    int cpu_flags = av_get_cpu_flags();

    if (EXTERNAL_SSE3(cpu_flags)) {
        dsp->sad = ff_sad_sse3;
        //dsp->convolution_x = ff_convolution_x_sse3;
        //dsp->convolution_y = ff_convolution_y_sse3;
    }
}
