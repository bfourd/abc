/* -*- c++ -*- */
/*
 * Copyright 2004,2008,2009 Free Software Foundation, Inc.
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

// WARNING: this file is machine generated.  Edits will be over written

#ifndef INCLUDED_GR_VECTOR_SINK_C_H
#define INCLUDED_GR_VECTOR_SINK_C_H

#include <gr_sync_block.h>

class gr_vector_sink_c;
typedef boost::shared_ptr<gr_vector_sink_c> gr_vector_sink_c_sptr;

gr_vector_sink_c_sptr
gr_make_vector_sink_c (int vlen = 1);


/*!
 * \brief gr_complex sink that writes to a vector
 * \ingroup sink_blk
 */

class gr_vector_sink_c : public gr_sync_block {
  friend gr_vector_sink_c_sptr gr_make_vector_sink_c (int vlen);
  std::vector<gr_complex>	d_data;
  int			d_vlen;
  gr_vector_sink_c (int vlen);

 public:
  virtual int work (int noutput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);

  void reset() {d_data.clear();}
  void clear() {reset(); }		// deprecated
  std::vector<gr_complex> data () const;
};

#endif
