#pragma once

#include "Transaction.h"
#include "proto/Tezos.pb.h"
#include <string>

namespace TW {
namespace Tezos {

class OperationList {
  public:
    std::string branch;
    std::vector<Transaction> operation_list;
    OperationList(const std::string& string);
    void addOperation(const Transaction& transaction);
    /// Returns a string representation of the operations.
    Data forge() const;
    Data forgeBranch() const;
};

} // namespace Tezos
} // namespace TW

/// Wrapper for C interface.
struct TWTezosOperationList {
    TW::Tezos::OperationList impl;
};
