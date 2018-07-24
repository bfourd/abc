/* -*- c++ -*- */
/*
 * Copyright 2005,2009 Free Software Foundation, Inc.
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
#include "gsm_fr_encode_sp.h"
#include "gsm_fr_decode_ps.h"
%}

GR_SWIG_BLOCK_MAGIC(gsm_fr,encode_sp);

gsm_fr_encode_sp_sptr gsm_fr_make_encode_sp ();

class gsm_fr_encode_sp : public gr_sync_decimator {
public:
  ~gsm_fr_encode_sp ();
};

// ----------------------------------------------------------------

GR_SWIG_BLOCK_MAGIC(gsm_fr,decode_ps);

gsm_fr_decode_ps_sptr gsm_fr_make_decode_ps ();

class gsm_fr_decode_ps : public gr_sync_interpolator {
public:
  ~gsm_fr_decode_ps ();
};

#if SWIGGUILE
%scheme %{
(load-extension-global "libguile-gnuradio-gsm_full_rate" "scm_init_gnuradio_gsm_full_rate_module")
%}

%goops %{
(use-modules (gnuradio gnuradio_core_runtime))
%}
#endif
