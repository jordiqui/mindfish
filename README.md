<div align="center">

  [![Pullfish][stockfish128-logo]][website-link]

  <h3>Pullfish</h3>

  A free and strong UCI chess engine derived from Stockfish 17.1.
  <br>
  <strong>[Explore Stockfish docs »][wiki-link]</strong>
  <br>
  <br>
  [Report bug][issue-link]
  ·
  [Open a discussion][discussions-link]
  ·
  [Discord][discord-link]
  ·
  [Blog][website-blog-link]

  [![Build][build-badge]][build-link]
  [![License][license-badge]][license-link]
  <br>
  [![Release][release-badge]][release-link]
  [![Commits][commits-badge]][commits-link]
  <br>
  [![Website][website-badge]][website-link]
  [![Fishtest][fishtest-badge]][fishtest-link]
  [![Discord][discord-badge]][discord-link]

</div>

> **Pullfish** es un motor UCI derivado de **Stockfish 17.1** y mantenido por
> **Jorge Ruiz**, con créditos especiales para **ChatGPT** y para los autores de
> Stockfish listados en [AUTHORS](AUTHORS). Este repositorio expone los fuentes
> del derivado para facilitar la colaboración y el mantenimiento del motor.

## Overview

[Pullfish][website-link] is a **free and strong UCI chess engine** derived from
[Stockfish 17.1][readme-link] and ultimately from Glaurung 2.1. It analyzes
chess positions and computes the optimal moves while preserving full
compatibility with the upstream project.

Pullfish **does not include a graphical user interface** (GUI) and is normally
paired with third-party front-ends such as Fritz 20 or Cutechess. It implements
the Universal Chess Interface (UCI) protocol so those GUIs can discover it as
**Pullfish** in their engine lists.

See also the Stockfish [documentation][wiki-usage-link] for further usage help
that continues to apply to Pullfish due to the close upstream relationship.

## Files

This distribution of Pullfish consists of the following files:

  * [README.md][readme-link], the file you are currently reading.

  * [Copying.txt][license-link], a text file containing the GNU General Public
    License version 3.

  * [AUTHORS][authors-link], a text file with the list of authors for Pullfish
    alongside the upstream Stockfish developers.

  * [src][src-link], a subdirectory containing the full source code, including a
    Makefile that can be used to compile Pullfish on Unix-like systems.

  * a file with the .nnue extension, storing the neural network for the NNUE
    evaluation. Binary distributions will have this file embedded.

## Contributing

__See [Contributing Guide](CONTRIBUTING.md).__

### Donating hardware

Improving Pullfish requires a massive amount of testing. You can donate your
hardware resources by installing the [Fishtest Worker][worker-link] and viewing
the current tests on [Fishtest][fishtest-link].

### Improving the code

In the [chessprogramming wiki][programming-link], many techniques used in
Pullfish and Stockfish are explained with a lot of background information.
The [section on Stockfish][programmingsf-link] describes many features
and techniques used upstream. However, it is generic rather than
focused on Pullfish's precise implementation.

The engine testing is done on [Fishtest][fishtest-link].
If you want to help improve Pullfish, please read this [guideline][guideline-link]
first, where the basics of Stockfish development are explained.

Discussions about Pullfish take place these days mainly in the Stockfish
[Discord server][discord-link], where the upstream community meets. This is also
the best place to ask questions about the codebase and how to improve it.

## Compiling Pullfish

Pullfish has support for 32 or 64-bit CPUs, certain hardware instructions,
big-endian machines such as Power PC, and other platforms.

On Unix-like systems, it should be easy to compile Pullfish directly from the
source code with the included Makefile in the folder `src`. In general, it is
recommended to run `make help` to see a list of make targets with corresponding
descriptions. An example suitable for most Intel and AMD chips:

```
cd src
make -j profile-build
```

Detailed compilation instructions for all platforms can be found in the
Stockfish [documentation][wiki-compile-link]. The wiki also has information
about the [UCI commands][wiki-uci-link] supported by Pullfish.

## Terms of use

Pullfish is free and distributed under the
[**GNU General Public License version 3**][license-link] (GPL v3). Essentially,
this means you are free to do almost exactly what you want with the program,
including distributing it among your friends, making it available for download
from your website, selling it (either by itself or as part of some bigger
software package), or using it as the starting point for a software project of
your own.

The only real limitation is that whenever you distribute Pullfish in some way,
you MUST always include the license and the full source code (or a pointer to
where the source code can be found) to generate the exact binary you are
distributing. If you make any changes to the source code, these changes must
also be made available under GPL v3.

## Credits

Pullfish 17.1 is maintained by Jorge Ruiz with credits for ChatGPT and for the
Stockfish developers listed in [AUTHORS](AUTHORS). The project remains a
derivative of Stockfish 17.1 and continues to benefit from the upstream
community's innovations.

## Acknowledgements

Pullfish uses neural networks trained on [data provided by the Leela Chess Zero
project][lc0-data-link], which is made available under the [Open Database License][odbl-link] (ODbL).


[authors-link]:       https://github.com/official-stockfish/Stockfish/blob/master/AUTHORS
[build-link]:         https://github.com/official-stockfish/Stockfish/actions/workflows/stockfish.yml
[commits-link]:       https://github.com/official-stockfish/Stockfish/commits/master
[discord-link]:       https://discord.gg/GWDRS3kU6R
[issue-link]:         https://github.com/official-stockfish/Stockfish/issues/new?assignees=&labels=&template=BUG-REPORT.yml
[discussions-link]:   https://github.com/official-stockfish/Stockfish/discussions/new
[fishtest-link]:      https://tests.stockfishchess.org/tests
[guideline-link]:     https://github.com/official-stockfish/fishtest/wiki/Creating-my-first-test
[license-link]:       https://github.com/official-stockfish/Stockfish/blob/master/Copying.txt
[programming-link]:   https://www.chessprogramming.org/Main_Page
[programmingsf-link]: https://www.chessprogramming.org/Stockfish
[readme-link]:        https://github.com/official-stockfish/Stockfish/blob/master/README.md
[release-link]:       https://github.com/official-stockfish/Stockfish/releases/latest
[src-link]:           https://github.com/official-stockfish/Stockfish/tree/master/src
[stockfish128-logo]:  https://stockfishchess.org/images/logo/icon_128x128.png
[uci-link]:           https://backscattering.de/chess/uci/
[website-link]:       https://stockfishchess.org
[website-blog-link]:  https://stockfishchess.org/blog/
[wiki-link]:          https://github.com/official-stockfish/Stockfish/wiki
[wiki-compile-link]:  https://github.com/official-stockfish/Stockfish/wiki/Compiling-from-source
[wiki-uci-link]:      https://github.com/official-stockfish/Stockfish/wiki/UCI-&-Commands
[wiki-usage-link]:    https://github.com/official-stockfish/Stockfish/wiki/Download-and-usage
[worker-link]:        https://github.com/official-stockfish/fishtest/wiki/Running-the-worker
[lc0-data-link]:      https://storage.lczero.org/files/training_data
[odbl-link]:          https://opendatacommons.org/licenses/odbl/odbl-10.txt

[build-badge]:        https://img.shields.io/github/actions/workflow/status/official-stockfish/Stockfish/stockfish.yml?branch=master&style=for-the-badge&label=stockfish&logo=github
[commits-badge]:      https://img.shields.io/github/commits-since/official-stockfish/Stockfish/latest?style=for-the-badge
[discord-badge]:      https://img.shields.io/discord/435943710472011776?style=for-the-badge&label=discord&logo=Discord
[fishtest-badge]:     https://img.shields.io/website?style=for-the-badge&down_color=red&down_message=Offline&label=Fishtest&up_color=success&up_message=Online&url=https%3A%2F%2Ftests.stockfishchess.org%2Ftests%2Ffinished
[license-badge]:      https://img.shields.io/github/license/official-stockfish/Stockfish?style=for-the-badge&label=license&color=success
[release-badge]:      https://img.shields.io/github/v/release/official-stockfish/Stockfish?style=for-the-badge&label=official%20release
[website-badge]:      https://img.shields.io/website?style=for-the-badge&down_color=red&down_message=Offline&label=website&up_color=success&up_message=Online&url=https%3A%2F%2Fstockfishchess.org
