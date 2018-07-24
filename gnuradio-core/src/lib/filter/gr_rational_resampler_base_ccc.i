/* -*- c++ -*- */
/*
 * Copyright 2005 Free Software Foundation, Inc.
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
 * generate_gr_rational_resampler_base_XXX.py Any changes made to this
 * file will be overwritten.
 */

GR_SWIG_BLOCK_MAGIC(gr,rational_resampler_base_ccc);

gr_rational_resampler_base_ccc_sptr gr_make_rational_resampler_base_ccc (int interpolation, int decimation, const std::vector<gr_complex> &taps);

class gr_rational_resampler_base_ccc : public gr_block
{
 private:
  gr_rational_resampler_base_ccc (int interpolation, int decimation, const std::vector<gr_complex> &taps);

 public:
  ~gr_rational_resampler_base_ccc ();

  void set_taps (const std::vector<gr_complex> &taps);
};
