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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_STRING_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_STRING_HPP

#include <otf2xx/reference.hpp>

#include <memory>
#include <string>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class string_impl
        {
        public:
            string_impl(otf2::reference<string> ref, const std::string& str) : ref_(ref), str_(str)
            {
                //             std::cout << "Created String_impl @" << this << " text: '" << str <<
                //             "' id: " << ref << std::endl;
            }

            // no implicit copy allowed, see duplicate()
            string_impl(const string_impl&) = delete;
            string_impl& operator=(const string_impl&) = delete;

            string_impl(string_impl&&) = default;
            string_impl& operator=(string_impl&&) = default;

            static const std::shared_ptr<string_impl>& undefined()
            {
                static std::shared_ptr<string_impl> undef(std::make_shared<string_impl>(
                    otf2::reference<string>::undefined(), std::string("")));
                return undef;
            }

            otf2::reference<string> ref() const
            {
                return ref_;
            }

            const std::string& str() const
            {
                return str_;
            }

            ~string_impl()
            {
                //             std::cout << "Deleted String_impl @" << this << " text: '" << str_ <<
                //             "' id: " << ref_ << std::endl;
            }

        private:
            otf2::reference<string> ref_;
            std::string str_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_STRING_HPP
