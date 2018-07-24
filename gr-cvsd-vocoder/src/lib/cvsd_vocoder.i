/* -*- c++ -*- */
/*
 * Copyright 2007,2009 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

%include "gnuradio.i"

%{
#include "cvsd_encode_sb.h"
#include "cvsd_decode_bs.h"
%}

GR_SWIG_BLOCK_MAGIC(cvsd,encode_sb);

cvsd_encode_sb_sptr cvsd_make_encode_sb (short min_step=10,
					 short max_step=1280,
					 double step_decay=0.9990234375,
					 double accum_decay= 0.96875,
					 int K=32,
					 int J=4,
					 short pos_accum_max=32767,
					 short neg_accum_max=-32767);

class cvsd_encode_sb : public gr_sync_decimator
{
private:
  cvsd_encode_sb (short min_step, short max_step, double step_decay,
		  double accum_decay, int K, int J,
		  short pos_accum_max, short neg_accum_max);
  

 public:
  short min_step() { return d_min_step; }
  short max_step() { return d_max_step; }
  double step_decay() { return d_step_decay; }
  double accum_decay() { return d_accum_decay; }
  int K() { return d_K; }
  int J() { return d_J; }
  short pos_accum_max() { return d_pos_accum_max; }
  short neg_accum_max() { return d_neg_accum_max; }
};

// ----------------------------------------------------------------

GR_SWIG_BLOCK_MAGIC(cvsd,decode_bs);

cvsd_decode_bs_sptr cvsd_make_decode_bs (short min_step=10,
					 short max_step=1280,
					 double step_decay=0.9990234375,
					 double accum_decay= 0.96875,
					 int K=32,
					 int J=4,
					 short pos_accum_max=32767,
					 short neg_accum_max=-32767);

class cvsd_decode_bs : public gr_sync_interpolator
{
private:
  cvsd_decode_bs (short min_step, short max_step, double step_decay,
		  double accum_decay, int K, int J,
		  short pos_accum_max, short neg_accum_max);
  
 public:
};

#if SWIGGUILE
%scheme %{
(load-extension-global "libguile-gnuradio-cvsd_vocoder" "scm_init_gnuradio_cvsd_vocoder_module")
%}

%goops %{
(use-modules (gnuradio gnuradio_core_runtime))
%}
#endif
