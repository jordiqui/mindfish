/*
  Pullfish, a UCI chess playing engine derived from Stockfish 17.1
  Copyright (C) 2004-2025 The Stockfish developers (see AUTHORS file)

  Pullfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Pullfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

#include "bitboard.h"
#include "misc.h"
#include "position.h"
#include "tune.h"
#include "types.h"
#include "uci.h"
#include "wdl/win_probability.h"
#include "learn/learn.h"

using namespace Stockfish;

int main(int argc, char* argv[]) {

    std::cout << engine_info() << std::endl;

    WDLModel::init();

    Bitboards::init();
    Position::init();

    UCIEngine uci(argc, argv);

    LD.init(uci.engine_options());
    Tune::init(uci.engine_options());

    uci.loop();

    return 0;
}
