/*
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Product name: program_options
  Copyright (C) Wallix 2015
  Author(s): Jonathan Poelen
*/
#include "program_options.h"

#include <limits>
#include <ostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#include <cerrno>
#include <cassert>

namespace rviz {
namespace program_options {

bool option_value::parse_int(char const * s, int * x) {
    char * p;
    long const n = std::strtol(s, &p, 10);
    if (n > std::numeric_limits<int>::max()) {
        return false;
    }
    *x = static_cast<int>(n);
    return p != s && !*p;
}

bool option_value::parse_unsigned_int(char const * s, unsigned int * x) {
    char * p;
    unsigned long const n = std::strtoul(s, &p, 10);
    if (n > std::numeric_limits<unsigned>::max()) {
        return false;
    }
    *x = static_cast<unsigned>(n);
    return p != s && !*p;
}

bool option_value::parse_long(char const * s, long * x) {
    char * p;
    *x = std::strtol(s, &p, 10);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_long_long(char const * s, long long * x) {
    char * p;
    *x = std::strtoll(s, &p, 10);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_unsigned_long(char const * s, unsigned long * x) {
    char * p;
    *x = std::strtoul(s, &p, 10);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_unsigned_long_long(char const * s, unsigned long long * x) {
    char * p;
    *x = std::strtoull(s, &p, 10);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_float(char const * s, float * x) {
    char * p;
    *x = std::strtof(s, &p);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_double(char const * s, double * x) {
    char * p;
    *x = std::strtod(s, &p);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_long_double(char const * s, long double * x) {
    char * p;
    *x = std::strtold(s, &p);
    return p != s && !*p && errno != ERANGE;
}

bool option_value::parse_string(char const * s, std::string * x) {
    *x = s;
    return true;
}

namespace {
    template<bool Print, class Fn>
    void output_desc(std::ostream & os, options_description const & desc, Fn f) {
        for (option_description const & opt : desc) {
            size_t len = opt.long_name().size() + 1;
            if (opt.has_short_name()) {
                if (Print) os << "  -" << opt.short_name();
                if (opt.has_long_name()) {
                    if (Print) os << " [ --" << opt.long_name() << " ]";
                    len += 7;
                }
            }
            else if (opt.has_long_name()) {
                if (Print) os << "  --" << opt.long_name();
            }

            if (opt.has_value()) {
                if (Print) os << " arg";
                len += 4;
            }

            f(len);

            if (Print) os << opt.description() << '\n';
        }
    }
}

std::ostream & operator<<(std::ostream & os, options_description const & desc) {
    size_t max_len = 0;
    output_desc<false>(os, desc, [&](size_t len) { max_len = std::max(max_len, len); });
    output_desc<true >(os, desc, [&](size_t len) { os << std::setw(int(max_len - len + 2)) << ""; });
    return os;
}


size_t variables_map::count(const std::string& name) const
{
    for (option_description const & desc : ref_descriptions) {
        if (desc.long_name() == name) {
            return 1;
        }
    }
    return 0;
}

size_t variables_map::count(const char* name) const
{
    for (option_description const & desc : ref_descriptions) {
        if (desc.long_name() == name) {
            return 1;
        }
    }
    return 0;
}

size_t variables_map::count(char name) const
{
    for (option_description const & desc : ref_descriptions) {
        if (desc.short_name() == name) {
            return 1;
        }
    }
    return 0;
}


unknown_option::unknown_option()
: std::runtime_error("unrecognized empty option")
{}

unknown_option::unknown_option(char opt)
: std::runtime_error(std::move(std::string("unrecognized option '-") + opt + '\''))
{}

unknown_option::unknown_option(std::string opt)
: std::runtime_error(std::move(std::string("unrecognized option '--") + opt + '\''))
{}


invalid_option_value::invalid_option_value(option_description const & option, char const * arg)
: std::runtime_error([&]{
    std::string s = "the argument ('";
    s += arg;
    s += "') for option '-";
    if (option.has_long_name()) {
        s += '-';
        s += option.long_name();
    }
    else {
        s += option.short_name();
    }
    s += "' is invalid";
    return s;
}())
{}


invalid_command_line_syntax::invalid_command_line_syntax(option_description const & option)
: std::runtime_error([&]{
    std::string s = "the required argument for option '-";
    if (option.has_long_name()) {
        s += '-';
        s += option.long_name();
    }
    else {
        s += option.short_name();
    }
    s += "' is missing";
    return s;
}())
{}

invalid_command_line_syntax::invalid_command_line_syntax()
: runtime_error("invalid syntax")
{}


void options_description::check_option_names() const
{
#ifndef NDEBUG
    std::string short_names;
    std::vector<std::reference_wrapper<const std::string>> long_names;

    for (option_description const & opt : this->options_) {
        if (opt.has_short_name()) {
            short_names.push_back(opt.short_name());
        }
    }
    for (option_description const & opt : this->options_) {
        if (opt.has_long_name()) {
            long_names.push_back(opt.long_name());
        }
    }

    std::sort(short_names.begin(), short_names.end());
    std::sort(long_names.begin(), long_names.end(), std::less<std::string>{});

    bool const has_unique_short_name = std::unique(short_names.begin(), short_names.end()) == short_names.end();
    bool const has_unique_long_name = std::unique(long_names.begin(), long_names.end(), std::equal_to<std::string>{}) == long_names.end();

    assert(has_unique_short_name && "two short option defined with the same name");
    assert(has_unique_long_name && "two long option defined with the same name");
#endif
}

namespace {

option_description const & get_option_description(options_description const & desc, char opt) {
    if (!opt) {
        throw unknown_option();
    }
    auto pred = [&](option_description const & option) {
        return option.short_name() == opt;
    };
    auto it = std::find_if(desc.begin(), desc.end(), pred);
    if (it == desc.end()) {
        throw unknown_option(opt);
    }
    return *it;
}

option_description const & get_option_description(options_description const & desc, char const *opt) {
    if (!*opt) {
        throw unknown_option();
    }
    auto pred = [&](option_description const & option) {
        return option.long_name() == opt;
    };
    auto it = std::find_if(desc.begin(), desc.end(), pred);
    if (it == desc.end()) {
        throw unknown_option(opt);
    }
    return *it;
}

}

variables_map parse_command_line(int ac, char const * const * av, const options_description & desc)
{
    variables_map variables;

    option_description const * option = nullptr;

    for (int i = 1; i < ac; ++i) {
        char const * arg = av[i];
        if (option) {
            if (!option->value().parse(arg)) {
                throw invalid_option_value(*option, arg);
            }
            variables.ref_descriptions.push_back(*option);
            option = nullptr;
        }
        else if (arg[0] == '-') {
            if (arg[1] == '-') {
                option = &get_option_description(desc, arg + 2);
                if (!option->has_value()) {
                    variables.ref_descriptions.push_back(*option);
                    option = nullptr;
                }
            }
            else {
                ++arg;
                do {
                    option = &get_option_description(desc, arg[0]);
                    if (option->has_value()) {
                        if (arg[1]) {
                            if (!option->value().parse(arg+1)) {
                                throw invalid_option_value(*option, arg);
                            }
                            variables.ref_descriptions.push_back(*option);
                            option = nullptr;
                        }
                        break;
                    }

                    variables.ref_descriptions.push_back(*option);
                    ++arg;
                    option = nullptr;
                } while (*arg);
            }
        }
        else {
            throw invalid_command_line_syntax();
        }
    }

    if (option) {
        throw invalid_command_line_syntax(*option);
    }

    return variables;
}

}
}
