/* -*- c++ -*- */
/*
 * Copyright 2008,2009 Free Software Foundation, Inc.
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

// FIXME: move to usrp/usrpm component

%{
#include <usrp/usrp_standard.h>
#include <usrp_spi_defs.h>
#include <usrp/usrp_dbid.h>
%}

%include <usrp_spi_defs.h>
%include <usrp/usrp_dbid.h>

%constant int FPGA_MODE_NORMAL   = usrp_standard_rx::FPGA_MODE_NORMAL;
%constant int FPGA_MODE_LOOPBACK = usrp_standard_rx::FPGA_MODE_LOOPBACK;
%constant int FPGA_MODE_COUNTING = usrp_standard_rx::FPGA_MODE_COUNTING;
