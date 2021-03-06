#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_TRAITS_STATUS_HPP_20100903
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_TRAITS_STATUS_HPP_20100903

// Copyright Dean Michael Berris 2010.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cstdint>
#include <boost/network/support/is_async.hpp>
#include <boost/network/tags.hpp>

namespace boost {
namespace network {
namespace http {

namespace traits {

template <class Tag>
struct unsupported_tag;

template <class Message>
struct status
    : mpl::if_<
          is_async<typename Message::tag>,
          std::shared_future<std::uint16_t>,
          typename mpl::if_<is_sync<typename Message::tag>, std::uint16_t,
                            unsupported_tag<typename Message::tag> >::type> {};

}  // namespace traits
 /* traits */

}  // namespace http
 /* http */
} // namespace network
 /* network */
} // namespace boost
 /* boost */

#endif
