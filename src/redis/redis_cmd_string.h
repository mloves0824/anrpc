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
#ifndef SRC_REDIS_REDIS_CMD_STRING_H_
#define SRC_REDIS_REDIS_CMD_STRING_H_

#include "redis_cmd.h"

namespace anrpc {
namespace redis {

class RedisCmdString : public RedisCmd {
public:
	RedisCmdString();
	~RedisCmdString();

	const std::string Set(const std::string& key, const std::string& value);
	bool Get(const std::string& key, std::string& value);

};

}
}



#endif /* SRC_REDIS_REDIS_CMD_STRING_H_ */
