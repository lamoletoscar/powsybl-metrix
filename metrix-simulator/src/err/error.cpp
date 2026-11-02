//
// Copyright (c) 2021, RTE (http://www.rte-france.com)
// See AUTHORS.txt
// All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, you can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//


#include "err/error.h"

#include <boost/filesystem.hpp>

namespace err
{
Error::Error(const std::string& msg, const std::string& file, int line) :
    msg_(msg),
    location_(boost::filesystem::path(file).filename().generic_string() + ":" + std::to_string(line))
{
}

} // namespace err