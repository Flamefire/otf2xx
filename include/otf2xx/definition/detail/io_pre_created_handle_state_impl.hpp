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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_PRE_CREATED_HANDLE_STATE_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_PRE_CREATED_HANDLE_STATE_HPP

#include <otf2xx/common.hpp>
#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/ref_counted.hpp>

#include <otf2xx/definition/io_handle.hpp>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class io_pre_created_handle_state_impl : public ref_counted
        {
        public:
            using io_access_mode_type = otf2::common::io_access_mode_type;
            using io_status_flag_type = otf2::common::io_status_flag_type;

            io_pre_created_handle_state_impl(const otf2::definition::io_handle& handle,
                                             io_access_mode_type mode, io_status_flag_type flags,
                                             int retain_count = 0)
            : ref_counted(retain_count), handle_(handle), access_mode_(mode), status_flags_(flags)
            {
            }

            // no implicit copy, see duplicate()
            io_pre_created_handle_state_impl(const io_pre_created_handle_state_impl&) = delete;
            io_pre_created_handle_state_impl&
            operator=(const io_pre_created_handle_state_impl&) = delete;

            io_pre_created_handle_state_impl(io_pre_created_handle_state_impl&&) = default;
            io_pre_created_handle_state_impl&
            operator=(io_pre_created_handle_state_impl&&) = default;

            static io_pre_created_handle_state_impl* undefined()
            {
                static io_pre_created_handle_state_impl undef(
                    otf2::definition::io_handle::undefined(), io_access_mode_type::read_only,
                    io_status_flag_type::none);

                return &undef;
            }

            const otf2::definition::io_handle& handle() const
            {
                return handle_;
            }

            io_access_mode_type access_mode() const
            {
                return access_mode_;
            }

            io_status_flag_type status_flags() const
            {
                return status_flags_;
            }

        private:
            otf2::definition::io_handle handle_;
            io_access_mode_type access_mode_;
            io_status_flag_type status_flags_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_IO_PRE_CREATED_HANDLE_STATE_HPP
