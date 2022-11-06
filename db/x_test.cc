#include <cassert>
#include <iostream>

#include "leveldb/db.h"
#include "leveldb/write_batch.h"

int main() {
  // Open a database.
  leveldb::DB* db;
  leveldb::Options opts;
  opts.create_if_missing = true;
  // tmp目录需要先创建,否则失败,权限不足
  leveldb::Status status = leveldb::DB::Open(opts, "../tmp/testdb", &db);
  assert(status.ok());

  // Write data
  status = db->Put(leveldb::WriteOptions(), "name", "Xiong");
  assert(status.ok());

  // Read data
  std::string val;
  status = db->Get(leveldb::ReadOptions(), "name", &val);
  assert(status.ok());
  std::cout << val << std::endl;
  return 0;
}