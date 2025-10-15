#ifndef POLYGLOT_BOOK_H_INCLUDED
#define POLYGLOT_BOOK_H_INCLUDED

#include <cstddef>
#include <string>
#include <vector>

#include "book/book.h"

namespace Stockfish::Book::Polyglot {

struct PolyglotEntry;
struct PolyglotBookMove;

class PolyglotBook: public Book {
   public:
    PolyglotBook();
    ~PolyglotBook() override;

    PolyglotBook(const PolyglotBook&)            = delete;
    PolyglotBook& operator=(const PolyglotBook&) = delete;

    std::string type() const override;

    void close() override;
    bool open(const std::string& f) override;

    Move probe(const Position& pos, size_t width, bool onlyGreen) const override;

    void show_moves(const Position& pos) const override;

   private:
    unsigned char* data() const;
    size_t         data_size() const;
    bool           has_data() const;
    size_t         total_entries() const;

    size_t find_first_pos(Key key) const;
    void   get_moves(const Position& pos, std::vector<PolyglotBookMove>& bookMoves) const;

    std::string    filename;
    unsigned char* bookData;
    size_t         bookDataLength;
};

}  // namespace Stockfish::Book::Polyglot

#endif
