/// The pack machinery packs a tensor's non-zero components according to the
/// tensor's storage format.  The machinery is available both as an interpreter
/// that can pack into any format, and as a code generator that generates
/// specialized packing code for one format.

#ifndef TACO_STORAGE_PACK_H
#define TACO_STORAGE_PACK_H

#include <vector>

namespace taco {
class Format;
namespace ir {
class Stmt;
}
namespace storage {
class TensorStorage;

/// Pack tensor coordinates into a format. The coordinates must be stored as a
/// structure of arrays, that is one vector per axis coordinate and one vector
/// for the values.
TensorStorage pack(const std::vector<int>&              dimensionSizes,
                   const Format&                        format,
                   const std::vector<std::vector<int>>& coordinates,
                   const std::vector<double>            values);

}}
#endif
