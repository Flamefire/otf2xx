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

#ifndef INCLUDE_OTF2XX_EVENT_THREAD_JOIN_HPP
#define INCLUDE_OTF2XX_EVENT_THREAD_JOIN_HPP

#include <otf2xx/definition/fwd.hpp>

#include <otf2xx/chrono/chrono.hpp>

#include <otf2xx/event/base.hpp>

namespace otf2
{
namespace event
{

    class thread_join : public base<thread_join>
    {
    public:
        thread_join(otf2::chrono::time_point timestamp, otf2::common::paradigm_type paradigm)
        : base<thread_join>(timestamp), paradigm_(paradigm)
        {
        }

        thread_join(OTF2_AttributeList* al, otf2::chrono::time_point timestamp,
                    otf2::common::paradigm_type paradigm)
        : base<thread_join>(al, timestamp), paradigm_(paradigm)
        {
        }

        thread_join(const otf2::event::thread_join& other, otf2::chrono::time_point timestamp)
        : base<thread_join>(other, timestamp), paradigm_(other.paradigm())
        {
        }

        otf2::common::paradigm_type paradigm() const
        {
            return paradigm_;
        }

    private:
        otf2::common::paradigm_type paradigm_;
    };
}
} // namespace otf2::event

#endif // INCLUDE_OTF2XX_EVENT_THREAD_JOIN_HPP
