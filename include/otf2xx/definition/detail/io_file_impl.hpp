/*
 * This file is part of otf2xx (https://github.com/tud-zih-energy/otf2xx)
 * otf2xx - A wrapper for the Open Trace Format 2 library
 *
 * Copyright (c) 2013-2016, Technische Universität Dresden, Germany
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_FILE_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_FILE_HPP

#include <otf2xx/common.hpp>
#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/ref_counted.hpp>

#include <otf2xx/definition/string.hpp>
#include <otf2xx/definition/system_tree_node.hpp>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class io_file_impl : public ref_counted
        {
        public:
            io_file_impl(otf2::reference<io_file> ref, const otf2::definition::string& name,
                         const otf2::definition::system_tree_node& scope,
                         std::int64_t retain_count = 0)
            : ref_counted(retain_count), ref_(ref), name_(name), scope_(scope)
            {
            }

            // no implicit copy, see duplicate()
            io_file_impl(const io_file_impl&) = delete;
            io_file_impl& operator=(const io_file_impl&) = delete;

            io_file_impl(io_file_impl&&) = default;
            io_file_impl& operator=(io_file_impl&&) = default;

            static io_file_impl* undefined()
            {
                static io_file_impl undef(otf2::reference<io_file>::undefined(),
                                          string::undefined(),
                                          otf2::definition::system_tree_node::undefined(), 1);
                return &undef;
            }

            otf2::reference<io_file> ref() const
            {
                return ref_;
            }

            const otf2::definition::string& name() const
            {
                return name_;
            }

            const otf2::definition::system_tree_node& scope() const
            {
                return scope_;
            }

        private:
            otf2::reference<io_file> ref_;
            otf2::definition::string name_;
            otf2::definition::system_tree_node scope_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_FILE_HPP
