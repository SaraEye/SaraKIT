// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/bigquery/storage/v1/storage.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MOCKS_MOCK_BIGQUERY_READ_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MOCKS_MOCK_BIGQUERY_READ_CONNECTION_H

#include "google/cloud/bigquery/bigquery_read_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace bigquery_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockBigQueryReadConnection : public bigquery::BigQueryReadConnection {
 public:
  MOCK_METHOD(
      StatusOr<google::cloud::bigquery::storage::v1::ReadSession>,
      CreateReadSession,
      (google::cloud::bigquery::storage::v1::CreateReadSessionRequest const&
           request),
      (override));

  MOCK_METHOD(
      StreamRange<google::cloud::bigquery::storage::v1::ReadRowsResponse>,
      ReadRows,
      (google::cloud::bigquery::storage::v1::ReadRowsRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::bigquery::storage::v1::SplitReadStreamResponse>,
      SplitReadStream,
      (google::cloud::bigquery::storage::v1::SplitReadStreamRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MOCKS_MOCK_BIGQUERY_READ_CONNECTION_H
