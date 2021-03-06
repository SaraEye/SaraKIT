// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: google/devtools/cloudtrace/v2/tracing.proto
// Original file comments:
// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_google_2fdevtools_2fcloudtrace_2fv2_2ftracing_2eproto__INCLUDED
#define GRPC_google_2fdevtools_2fcloudtrace_2fv2_2ftracing_2eproto__INCLUDED

#include "google/devtools/cloudtrace/v2/tracing.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace google {
namespace devtools {
namespace cloudtrace {
namespace v2 {

// This file describes an API for collecting and viewing traces and spans
// within a trace.  A Trace is a collection of spans corresponding to a single
// operation or set of operations for an application. A span is an individual
// timed event which forms a node of the trace tree. A single trace may
// contain span(s) from multiple services.
class TraceService final {
 public:
  static constexpr char const* service_full_name() {
    return "google.devtools.cloudtrace.v2.TraceService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends new spans to new or existing traces. You cannot update
    // existing spans.
    virtual ::grpc::Status BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncBatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncBatchWriteSpansRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> PrepareAsyncBatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(PrepareAsyncBatchWriteSpansRaw(context, request, cq));
    }
    // Creates a new span.
    virtual ::grpc::Status CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::google::devtools::cloudtrace::v2::Span* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>> AsyncCreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>>(AsyncCreateSpanRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>> PrepareAsyncCreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>>(PrepareAsyncCreateSpanRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Sends new spans to new or existing traces. You cannot update
      // existing spans.
      virtual void BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) = 0;
      virtual void BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      // Creates a new span.
      virtual void CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncBatchWriteSpansRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* PrepareAsyncBatchWriteSpansRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>* AsyncCreateSpanRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::devtools::cloudtrace::v2::Span>* PrepareAsyncCreateSpanRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::google::protobuf::Empty* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncBatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncBatchWriteSpansRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> PrepareAsyncBatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(PrepareAsyncBatchWriteSpansRaw(context, request, cq));
    }
    ::grpc::Status CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::google::devtools::cloudtrace::v2::Span* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>> AsyncCreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>>(AsyncCreateSpanRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>> PrepareAsyncCreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>>(PrepareAsyncCreateSpanRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)>) override;
      void BatchWriteSpans(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response, ::grpc::ClientUnaryReactor* reactor) override;
      void CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response, std::function<void(::grpc::Status)>) override;
      void CreateSpan(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncBatchWriteSpansRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* PrepareAsyncBatchWriteSpansRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>* AsyncCreateSpanRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::devtools::cloudtrace::v2::Span>* PrepareAsyncCreateSpanRaw(::grpc::ClientContext* context, const ::google::devtools::cloudtrace::v2::Span& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_BatchWriteSpans_;
    const ::grpc::internal::RpcMethod rpcmethod_CreateSpan_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends new spans to new or existing traces. You cannot update
    // existing spans.
    virtual ::grpc::Status BatchWriteSpans(::grpc::ServerContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response);
    // Creates a new span.
    virtual ::grpc::Status CreateSpan(::grpc::ServerContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBatchWriteSpans(::grpc::ServerContext* context, ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CreateSpan() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreateSpan(::grpc::ServerContext* context, ::google::devtools::cloudtrace::v2::Span* request, ::grpc::ServerAsyncResponseWriter< ::google::devtools::cloudtrace::v2::Span>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_BatchWriteSpans<WithAsyncMethod_CreateSpan<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest, ::google::protobuf::Empty>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* request, ::google::protobuf::Empty* response) { return this->BatchWriteSpans(context, request, response); }));}
    void SetMessageAllocatorFor_BatchWriteSpans(
        ::grpc::MessageAllocator< ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest, ::google::protobuf::Empty>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest, ::google::protobuf::Empty>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* BatchWriteSpans(
      ::grpc::CallbackServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_CreateSpan() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::google::devtools::cloudtrace::v2::Span, ::google::devtools::cloudtrace::v2::Span>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::google::devtools::cloudtrace::v2::Span* request, ::google::devtools::cloudtrace::v2::Span* response) { return this->CreateSpan(context, request, response); }));}
    void SetMessageAllocatorFor_CreateSpan(
        ::grpc::MessageAllocator< ::google::devtools::cloudtrace::v2::Span, ::google::devtools::cloudtrace::v2::Span>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::google::devtools::cloudtrace::v2::Span, ::google::devtools::cloudtrace::v2::Span>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CreateSpan(
      ::grpc::CallbackServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_BatchWriteSpans<WithCallbackMethod_CreateSpan<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CreateSpan() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBatchWriteSpans(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CreateSpan() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreateSpan(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->BatchWriteSpans(context, request, response); }));
    }
    ~WithRawCallbackMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* BatchWriteSpans(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_CreateSpan() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CreateSpan(context, request, response); }));
    }
    ~WithRawCallbackMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CreateSpan(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_BatchWriteSpans : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_BatchWriteSpans() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest, ::google::protobuf::Empty>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest, ::google::protobuf::Empty>* streamer) {
                       return this->StreamedBatchWriteSpans(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_BatchWriteSpans() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status BatchWriteSpans(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest* /*request*/, ::google::protobuf::Empty* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedBatchWriteSpans(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::devtools::cloudtrace::v2::BatchWriteSpansRequest,::google::protobuf::Empty>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CreateSpan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CreateSpan() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::google::devtools::cloudtrace::v2::Span, ::google::devtools::cloudtrace::v2::Span>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::google::devtools::cloudtrace::v2::Span, ::google::devtools::cloudtrace::v2::Span>* streamer) {
                       return this->StreamedCreateSpan(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CreateSpan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CreateSpan(::grpc::ServerContext* /*context*/, const ::google::devtools::cloudtrace::v2::Span* /*request*/, ::google::devtools::cloudtrace::v2::Span* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCreateSpan(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::devtools::cloudtrace::v2::Span,::google::devtools::cloudtrace::v2::Span>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_BatchWriteSpans<WithStreamedUnaryMethod_CreateSpan<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_BatchWriteSpans<WithStreamedUnaryMethod_CreateSpan<Service > > StreamedService;
};

}  // namespace v2
}  // namespace cloudtrace
}  // namespace devtools
}  // namespace google


#endif  // GRPC_google_2fdevtools_2fcloudtrace_2fv2_2ftracing_2eproto__INCLUDED
