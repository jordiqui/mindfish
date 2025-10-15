#ifndef CTG_BOOK_H_INCLUDED
#define CTG_BOOK_H_INCLUDED

#include <cstdint>
#include <string>

#include "book/book.h"
#include "book/file_mapping.h"

namespace Stockfish::Book::CTG {

struct CtgPositionData;
struct CtgMoveList;
struct CtgMove;
struct CtgMoveStats;

class CtgBook: public Book {
   public:
    CtgBook();
    ~CtgBook() override;

    CtgBook(const CtgBook&)            = delete;
    CtgBook& operator=(const CtgBook&) = delete;

    std::string type() const override;

    bool open(const std::string& f) override;
    void close() override;

    bool is_open() const;

    Move probe(const Position& pos, size_t width, bool onlyGreen) const override;

    void show_moves(const Position& pos) const override;

   private:
    bool decode(const Position& pos, CtgPositionData& positionData) const;
    void decode_board(const Position& pos, CtgPositionData& positionData) const;
    void invert_board(CtgPositionData& positionData) const;
    bool needs_flipping(const Position& pos) const;
    void flip_board(const Position& pos, CtgPositionData& positionData) const;

    void     encode_position(const Position& pos, CtgPositionData& positionData) const;
    bool     read_position_data(CtgPositionData& positionData, uint32_t pageNum) const;
    uint32_t gen_position_hash(CtgPositionData& positionData) const;
    bool     lookup_position(CtgPositionData& positionData) const;

    void get_stats(const CtgPositionData& positionData, CtgMoveStats& stats, bool isMove) const;
    Move get_pseudo_move(const CtgPositionData& positionData, int moveNum) const;
    bool get_move(const Position& pos, const CtgPositionData& positionData, int moveNum, CtgMove& ctgMove) const;
    void get_moves(const Position& pos, const CtgPositionData& positionData, CtgMoveList& ctgMoveList) const;

    Book::FileMapping cto;
    Book::FileMapping ctg;
    uint32_t          pageLowerBound;
    uint32_t          pageUpperBound;
    bool              isOpen;
};

}  // namespace Stockfish::Book::CTG

#endif
