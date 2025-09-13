#pragma once

#ifndef JNOVA_HPP
#define JNOVA_HPP

#include <cstring>
#include <exception>
#include <format>
#include <iostream>
#include <source_location>
#include <string>

namespace JNOVA {

class Ex : public std::exception {
  std::string make_message() const;
  std::source_location srcLoc_;
  std::string reason_;
  std::string message_;

public:
  Ex(std::string reason,
     const std::source_location &srcLoc = std::source_location::current());

  const char *what() const noexcept override;
};

} // namespace JNOVA

#endif