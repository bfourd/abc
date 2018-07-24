/* -*- c++ -*- */
/*
 * Copyright 2002,2003 Free Software Foundation, Inc.
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
 * WARNING: This file is automatically generated by generate_gr_fir_XXX.py
 * Any changes made to this file will be overwritten.
 */


#ifndef INCLUDED_GR_FIR_FCC_H
#define INCLUDED_GR_FIR_FCC_H

#include <vector>
#include <gr_types.h>
#include <gr_reverse.h>

/*!
 * \brief Abstract class for FIR with float input, gr_complex output and gr_complex taps
 * \ingroup filter_primitive
 * 
 * This is the abstract class for a Finite Impulse Response filter.
 *
 * The trailing suffix has the form _IOT where I codes the input type,
 * O codes the output type, and T codes the tap type.
 * I,O,T are elements of the set 's' (short), 'f' (float), 'c' (gr_complex), 'i' (int)
 */

class gr_fir_fcc {

protected:
  std::vector<gr_complex>	d_taps;		// reversed taps

public:

  // CONSTRUCTORS

  /*!
   * \brief construct new FIR with given taps.
   *
   * Note that taps must be in forward order, e.g., coefficient 0 is
   * stored in new_taps[0], coefficient 1 is stored in
   * new_taps[1], etc.
   */
  gr_fir_fcc () {}
  gr_fir_fcc (const std::vector<gr_complex> &taps) : d_taps (gr_reverse(taps)) {}

  virtual ~gr_fir_fcc ();

  // MANIPULATORS

  /*!
   * \brief compute a single output value.
   *
   * \p input must have ntaps() valid entries.
   * input[0] .. input[ntaps() - 1] are referenced to compute the output value.
   *
   * \returns the filtered input value.
   */
  virtual gr_complex filter (const float input[]) = 0;

  /*!
   * \brief compute an array of N output values.
   *
   * \p input must have (n - 1 + ntaps()) valid entries.
   * input[0] .. input[n - 1 + ntaps() - 1] are referenced to compute the output values.
   */
  virtual void filterN (gr_complex output[], const float input[],
			unsigned long n) = 0;

  /*!
   * \brief compute an array of N output values, decimating the input
   *
   * \p input must have (decimate * (n - 1) + ntaps()) valid entries.
   * input[0] .. input[decimate * (n - 1) + ntaps() - 1] are referenced to 
   * compute the output values.
   */
  virtual void filterNdec (gr_complex output[], const float input[],
			   unsigned long n, unsigned decimate) = 0;

  /*!
   * \brief install \p new_taps as the current taps.
   */
  virtual void set_taps (const std::vector<gr_complex> &taps)
  {
    d_taps = gr_reverse(taps);
  }

  // ACCESSORS

  /*!
   * \return number of taps in filter.
   */
  unsigned ntaps () const { return d_taps.size (); }

  /*!
   * \return current taps
   */
  virtual const std::vector<gr_complex> get_taps () const
  {
    return gr_reverse(d_taps);
  }
};

#endif /* INCLUDED_GR_FIR_FCC_H */
