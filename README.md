<div align="center">

  <img src="assets/pullsfish-logo.svg" alt="Pullfish logo" width="160">

  <h3>Pullfish 1.0 171025</h3>

  A free and strong UCI chess engine derived from Stockfish 17.1.
  <br>
  <strong>Developed, maintained, and improved by Jorge Ruiz together with the ChatGPT AI, with full credit to the Stockfish authors and contributors.</strong>
  <br>
  <br>
  <a href="https://github.com/jorgeluisruiz/pullfish/issues/new">Report bug</a>
  ·
  <a href="https://github.com/jorgeluisruiz/pullfish/discussions/new">Open a discussion</a>
  ·
  <a href="https://discord.gg/GWDRS3kU6R">Discord</a>
  ·
  <a href="https://pullfish.org/blog">Blog</a>

</div>

> **Pullfish 1.0 171025** is a UCI chess engine derived from **Stockfish 17.1**. The
> project is jointly authored by **Jorge Ruiz** and the **ChatGPT AI**, with
> credits to the Stockfish authors and every contributor listed in
> [AUTHORS](AUTHORS). This repository provides the complete source so the
> community can collaborate on maintenance and future improvements.

This release and all distributed binaries identify themselves as **Pullfish 1.0 171025**.
You should see that exact name (including the build tag `171025`) in the engine
headers, UCI responses, and compiled executable filenames. If a GUI shows a
different string, make sure it is loading the binaries built from this version
of the source tree.

## Overview

Pullfish 1.0 171025 is a **free and strong UCI chess engine** that analyzes chess positions
and computes the optimal moves while preserving full compatibility with popular
front-ends.

Pullfish 1.0 171025 **does not include a graphical user interface** (GUI) and is normally
paired with third-party front-ends such as Fritz 20 or Cutechess. It implements
the Universal Chess Interface (UCI) protocol so those GUIs can discover it as
**Pullfish 1.0 171025** in their engine lists.

## Files

This distribution of Pullfish 1.0 171025 consists of the following files:

  * [README.md](README.md), the file you are currently reading.

  * [Copying.txt](Copying.txt), a text file containing the GNU General Public
    License version 3.

  * [AUTHORS](AUTHORS), a text file with the list of authors for Pullfish 1.0 171025.

  * [src](src), a subdirectory containing the full source code, including a
    Makefile that can be used to compile Pullfish 1.0 171025 on Unix-like systems.

  * a file with the .nnue extension, storing the neural network for the NNUE
    evaluation. Binary distributions will have this file embedded.

## Contributing

__See [Contributing Guide](CONTRIBUTING.md).__

### Donating hardware

Improving Pullfish 1.0 171025 requires a massive amount of testing. You can donate your
hardware resources by installing the Pullfish worker and joining the community
channels to coordinate testing campaigns.

### Improving the code

In the [chessprogramming wiki](https://www.chessprogramming.org/Main_Page), many
techniques used in Pullfish 1.0 171025 are explained with a lot of background information.
The [section on evaluation techniques](https://www.chessprogramming.org/Evaluation)
describes many features and techniques used by modern engines.

The engine testing is coordinated by the Pullfish maintainers. If you want to
help improve Pullfish 1.0 171025, please read this
[guideline](https://github.com/jorgeluisruiz/pullfish/wiki/Getting-Started)
first, where the basics of development are explained.

Discussions about Pullfish take place mainly in the community
[Discord server](https://discord.gg/GWDRS3kU6R). This is the best place to ask
questions about the codebase and how to improve it.

## Compiling Pullfish

Pullfish 1.0 171025 has support for 32 or 64-bit CPUs, certain hardware instructions,
big-endian machines such as Power PC, and other platforms.

On Unix-like systems, it should be easy to compile Pullfish 1.0 171025 directly from the
source code with the included Makefile in the folder `src`. In general, it is
recommended to run `make help` to see a list of make targets with corresponding
descriptions. An example suitable for most Intel and AMD chips:

```
cd src
make -j profile-build
```

Detailed compilation instructions for all platforms can be found in the
[documentation](https://github.com/jorgeluisruiz/pullfish/wiki/Compilation). The
wiki also has information about the
[UCI commands](https://github.com/jorgeluisruiz/pullfish/wiki/UCI-Commands)
supported by Pullfish.

## Terms of use

Pullfish 1.0 171025 is free and distributed under the
[**GNU General Public License version 3**](Copying.txt) (GPL v3). Essentially,
this means you are free to do almost exactly what you want with the program,
including distributing it among your friends, making it available for download
from your website, selling it (either by itself or as part of some bigger
software package), or using it as the starting point for a software project of
your own.

The only real limitation is that whenever you distribute Pullfish 1.0 171025 in some way,
you MUST always include the license and the full source code (or a pointer to
where the source code can be found) to generate the exact binary you are
distributing. If you make any changes to the source code, these changes must
also be made available under GPL v3.

## Credits

Pullfish 1.0 171025 is maintained by Jorge Ruiz in collaboration with the ChatGPT AI.
The project gives full credit to the Stockfish authors and to every contributor
listed in [AUTHORS](AUTHORS), and it continues to benefit from the innovations
shared by the wider open-source chess community.

## Acknowledgements

Pullfish uses neural networks trained on
[data provided by the Leela Chess Zero project](https://training.lczero.org/),
which is made available under the
[Open Database License](https://opendatacommons.org/licenses/odbl/) (ODbL).

