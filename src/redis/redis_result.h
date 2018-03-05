// Copyright (c) 2015 Antalk, Inc.
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
 
// Author: chenbang@antalk.com

#ifndef _REDIS_RESULT_H_
#define _REDIS_RESULT_H_

#include <memory>
#include <vector>

namespace anrpc {
namespace redis {

#define REDIS_REPLY_STRING 1
#define REDIS_REPLY_ARRAY 2
#define REDIS_REPLY_INTEGER 3
#define REDIS_REPLY_NIL 4
#define REDIS_REPLY_STATUS 5
#define REDIS_REPLY_ERROR 6

class RedisResult;
typedef std::shared_ptr<RedisResult> RedisResultPtr;

class RedisResult {//TODO:支持hiredis/acl/brpc/pebble
public:
    RedisResult();
    virtual ~RedisResult();

private:
    //TODO：内存优化
	unsigned char type_;
	std::string str_;
	long long integer_;
	std::vector<RedisResultPtr> elements_;
};


}
}


#endif
