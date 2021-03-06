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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_INSTANCE_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_INSTANCE_HPP

#include <otf2xx/common.hpp>
#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/ref_counted.hpp>

#include <otf2xx/definition/group.hpp>
#include <otf2xx/definition/location.hpp>
#include <otf2xx/definition/location_group.hpp>
#include <otf2xx/definition/metric_class.hpp>
#include <otf2xx/definition/system_tree_node.hpp>

#include <memory>
#include <vector>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class metric_instance_impl : public ref_counted
        {
        public:
            typedef otf2::common::metric_scope metric_scope;
            typedef otf2::common::metric_occurence metric_occurence;

            metric_instance_impl(reference<detail::metric_base> ref,
                                 const otf2::definition::metric_class& metric_class,
                                 const otf2::definition::location& recorder,
                                 const otf2::definition::location& scope,
                                 std::int64_t retain_count = 0)
            : ref_counted(retain_count), ref_(ref), metric_class_(metric_class),
              recorder_(recorder), location_scope_(scope), location_group_scope_(),
              system_tree_node_scope_(), group_scope_()
            {
            }

            metric_instance_impl(reference<detail::metric_base> ref,
                                 const otf2::definition::metric_class& metric_class,
                                 const otf2::definition::location& recorder,
                                 const otf2::definition::location_group& scope,
                                 std::int64_t retain_count = 0)
            : ref_counted(retain_count), ref_(ref), metric_class_(metric_class),
              recorder_(recorder), location_scope_(), location_group_scope_(scope),
              system_tree_node_scope_(), group_scope_()
            {
            }

            metric_instance_impl(reference<detail::metric_base> ref,
                                 const otf2::definition::metric_class& metric_class,
                                 const otf2::definition::location& recorder,
                                 const otf2::definition::system_tree_node& scope,
                                 std::int64_t retain_count = 0)
            : ref_counted(retain_count), ref_(ref), metric_class_(metric_class),
              recorder_(recorder), location_scope_(), location_group_scope_(),
              system_tree_node_scope_(scope), group_scope_()
            {
            }

            metric_instance_impl(reference<detail::metric_base> ref,
                                 const otf2::definition::metric_class& metric_class,
                                 const otf2::definition::location& recorder,
                                 const otf2::definition::locations_group& scope,
                                 std::int64_t retain_count = 0)
            : ref_counted(retain_count), ref_(ref), metric_class_(metric_class),
              recorder_(recorder), location_scope_(), location_group_scope_(),
              system_tree_node_scope_(), group_scope_(scope)
            {
            }

            // no implicit copy, see duplicate()
            metric_instance_impl(const metric_instance_impl&) = delete;
            metric_instance_impl& operator=(const metric_instance_impl&) = delete;

            metric_instance_impl(metric_instance_impl&&) = default;
            metric_instance_impl& operator=(metric_instance_impl&&) = default;

            static metric_instance_impl* undefined()
            {
                static metric_instance_impl undef(otf2::reference<metric_instance>::undefined(),
                                                  otf2::definition::metric_class::undefined(),
                                                  otf2::definition::location::undefined(),
                                                  otf2::definition::location::undefined(), 1);
                return &undef;
            }

            otf2::reference<metric_base> ref() const
            {
                return ref_;
            }

            metric_occurence occurence() const
            {
                return metric_occurence::async;
            }

            const otf2::definition::metric_class& metric_class() const
            {
                return metric_class_;
            }

            const otf2::definition::location& recorder() const
            {
                return recorder_;
            }

            metric_scope scope() const
            {
                if (location_scope_.is_valid())
                    return metric_scope::location;

                if (location_group_scope_.is_valid())
                    return metric_scope::location_group;

                if (system_tree_node_scope_.is_valid())
                    return metric_scope::system_tree_node;

                if (group_scope_.is_valid())
                    return metric_scope::group;

                make_exception("There is no valid scope definition for this metric instance.");

                return metric_scope::group;
            }

            const otf2::definition::location& location_scope() const
            {
                return location_scope_;
            }

            const otf2::definition::location_group& location_group_scope() const
            {
                return location_group_scope_;
            }

            const otf2::definition::system_tree_node& system_tree_node_scope() const
            {
                return system_tree_node_scope_;
            }

            const otf2::definition::locations_group& group_scope() const
            {
                return group_scope_;
            }

        private:
            reference<metric_base> ref_;

            otf2::definition::metric_class metric_class_;
            otf2::definition::location recorder_;

            otf2::definition::location location_scope_;
            otf2::definition::location_group location_group_scope_;
            otf2::definition::system_tree_node system_tree_node_scope_;
            otf2::definition::locations_group group_scope_;
        };
    } // namespace detail
} // namespace definition
} // namespace otf2

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_INSTANCE_HPP
