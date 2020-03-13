//
// Uber, Inc. (c) 2020
//

#pragma once

#include "neuropod/multiprocess/serialization/ipc_serialization.hh"

namespace neuropod
{

// Contains everything needed to load a model in the worker process
struct ope_load_config
{
    // The path of the model to load
    std::string neuropod_path;
};

// Specializations for ope_load_config
// Because of a bug in boost serialization, we can't just `ope_load_config`
// as serializable
template <>
void ipc_serialize(std::ostream &out, const ope_load_config &data);

template <>
void ipc_deserialize(std::istream &in, ope_load_config &data);

} // namespace neuropod