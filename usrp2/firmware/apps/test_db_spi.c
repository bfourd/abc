/* -*- c++ -*- */
/*
 * Copyright 2008 Free Software Foundation, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <u2_init.h>
#include <nonstdio.h>
#include <hal_io.h>
#include <spi.h>

int
main(void)
{
  u2_init();

  puts("\ntest_db_spi");

  while(1){
    spi_transact(SPI_TXONLY, SPI_SS_RX_DB, 0xCC33, 16, SPIF_PUSH_FALL);
    spi_transact(SPI_TXONLY, SPI_SS_TX_DB, 0x33CC, 16, SPIF_PUSH_FALL);
  }
}
