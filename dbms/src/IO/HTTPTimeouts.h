#pragma once

#include <Poco/Timespan.h>
#include <Interpreters/Settings.h>

namespace DB
{

struct HTTPTimeouts
{
    Poco::Timespan connection_timeout = Poco::Timespan(DEFAULT_HTTP_READ_BUFFER_CONNECTION_TIMEOUT, 0);
    Poco::Timespan send_timeout = Poco::Timespan(DEFAULT_HTTP_READ_BUFFER_TIMEOUT, 0);
    Poco::Timespan receive_timeout = Poco::Timespan(DEFAULT_HTTP_READ_BUFFER_TIMEOUT, 0);

    HTTPTimeouts() = default;

    HTTPTimeouts(Poco::Timespan connection_timeout_, Poco::Timespan send_timeout_, Poco::Timespan receive_timeout_)
            : connection_timeout(connection_timeout_),
              send_timeout(send_timeout_),
              receive_timeout(receive_timeout_)
    {
    }

    explicit HTTPTimeouts(const Settings & settings)
            : connection_timeout(settings.connect_timeout),
              send_timeout(settings.send_timeout),
              receive_timeout(settings.receive_timeout)
    {
    }
};

}
