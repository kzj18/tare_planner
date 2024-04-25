// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.
//
// Generates Java code for a given .proto file.

#ifndef GOOGLE_PROTOBUF_COMPILER_JAVA_GENERATOR_H__
#define GOOGLE_PROTOBUF_COMPILER_JAVA_GENERATOR_H__

#include <string>

#include "google/protobuf/compiler/code_generator.h"

// Must be included last.
#include "google/protobuf/port_def.inc"

namespace google {
namespace protobuf {
namespace compiler {
namespace java {

// CodeGenerator implementation which generates Java code.  If you create your
// own protocol compiler binary and you want it to support Java output, you
// can do so by registering an instance of this CodeGenerator with the
// CommandLineInterface in your main() function.
class PROTOC_EXPORT JavaGenerator : public CodeGenerator {
 public:
  JavaGenerator();
  JavaGenerator(const JavaGenerator&) = delete;
  JavaGenerator& operator=(const JavaGenerator&) = delete;
  ~JavaGenerator() override;

  // implements CodeGenerator ----------------------------------------
  bool Generate(const FileDescriptor* file, const std::string& parameter,
                GeneratorContext* context, std::string* error) const override;

  uint64_t GetSupportedFeatures() const override;

  void set_opensource_runtime(bool opensource) {
    opensource_runtime_ = opensource;
  }

 private:
  bool opensource_runtime_ = PROTO2_IS_OSS;
};

}  // namespace java
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_COMPILER_JAVA_GENERATOR_H__
