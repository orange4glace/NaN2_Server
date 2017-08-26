// logger.h
#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <boost/locale/generator.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>

#define L_DEBUG BOOST_LOG_TRIVIAL(debug)
#define L_DEBUG_W BOOST_LOG(nan2::lg)

namespace nan2 {

  extern boost::log::sources::wlogger lg;

  class Logger {

    static Logger* instance_;
    
    boost::shared_ptr< boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > > stdout_sink_;
    boost::log::sources::wlogger* wlogger_;

  public:
    static Logger* const instance() {
      if (instance_ == nullptr) {
        instance_ = new Logger();
      }
      return instance_;
    }

    Logger() {
      stdout_sink_ = boost::log::add_console_log();
      std::locale loc = boost::locale::generator()("en_US.UTF-8");
      stdout_sink_->imbue(loc);

      // Let's add some commonly used attributes, like timestamp and record counter.
      boost::log::add_common_attributes();

      wlogger_ = new boost::log::sources::wlogger();
    }

    const boost::log::sources::wlogger* const wlogger() {
      return wlogger_;
    }



  };

}

#define endl "\n"

#endif