/* -*- c++ -*- */
/*
 * Copyright 2003,2010 Free Software Foundation, Inc.
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

/*
 * WARNING: This file is automatically generated by
 * generate_gr_freq_xlating_fir_filter_XXX.py 
 * Any changes made to this file will be overwritten.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_freq_xlating_fir_filter_ccf.h>
#include <gr_fir_ccc.h>
#include <gr_fir_util.h>
#include <gr_io_signature.h>

gr_freq_xlating_fir_filter_ccf_sptr 
gr_make_freq_xlating_fir_filter_ccf (int decimation, const std::vector<float> &taps,
		     double center_freq, double sampling_freq)
{
  return gnuradio::get_initial_sptr (new gr_freq_xlating_fir_filter_ccf (decimation, taps, center_freq, sampling_freq));
}


gr_freq_xlating_fir_filter_ccf::gr_freq_xlating_fir_filter_ccf (

	int decimation,
	const std::vector<float> &taps,
	double center_freq,
	double sampling_freq)

  : gr_sync_decimator ("freq_xlating_fir_filter_ccf",
		       gr_make_io_signature (1, 1, sizeof (gr_complex)),
		       gr_make_io_signature (1, 1, sizeof (gr_complex)),
		       decimation),
    d_proto_taps (taps), d_center_freq (center_freq), d_sampling_freq (sampling_freq),
    d_updated (false)
{
  std::vector<gr_complex>	dummy_taps;
  d_composite_fir = gr_fir_util::create_gr_fir_ccc (dummy_taps);

  set_history (d_proto_taps.size ());
  build_composite_fir ();
}

gr_freq_xlating_fir_filter_ccf::~gr_freq_xlating_fir_filter_ccf ()
{
  delete d_composite_fir;
}

void
gr_freq_xlating_fir_filter_ccf::build_composite_fir ()
{
  std::vector<gr_complex> ctaps (d_proto_taps.size ());

  float fwT0 = 2 * M_PI * d_center_freq / d_sampling_freq;
  for (unsigned int i = 0; i < d_proto_taps.size (); i++)
    ctaps[i] = d_proto_taps[i] * exp (gr_complex (0, i * fwT0));

  d_composite_fir->set_taps (gr_reverse(ctaps));
  d_r.set_phase_incr (exp (gr_complex (0, fwT0 * decimation ())));
}

void
gr_freq_xlating_fir_filter_ccf::set_center_freq (double center_freq)
{
  d_center_freq = center_freq;
  d_updated = true;
}

void
gr_freq_xlating_fir_filter_ccf::set_taps (const std::vector<float> &taps)
{
  d_proto_taps = taps;
  d_updated = true;
}

int
gr_freq_xlating_fir_filter_ccf::work (int noutput_items,
		   gr_vector_const_void_star &input_items,
		   gr_vector_void_star &output_items)
{
  gr_complex     *in  = (gr_complex *) input_items[0];
  gr_complex     *out = (gr_complex *) output_items[0];

  // rebuild composite FIR if the center freq has changed

  if (d_updated){
    set_history (d_proto_taps.size ());
    build_composite_fir ();
    d_updated = false;
    return 0;		     // history requirements may have changed.
  }

  unsigned j = 0;
  for (int i = 0; i < noutput_items; i++){
    out[i] = d_r.rotate (d_composite_fir->filter (&in[j]));
    j += decimation ();
  }
  
  return noutput_items;
}