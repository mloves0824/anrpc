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

#ifndef _REDIS_CMD_H_
#define _REDIS_CMD_H_

#include "redis_client.h"
#include "redis_result.h"

namespace anrpc {
namespace redis {

//redis 客户端命令操作类的纯虚父类
class RedisCmd {
public:
    //缺省的构造函数，如果使用此构造函数初始化类对象，则必须调用 set_client 或
    //set_cluster 设置 redis 客户端命令类对象的通讯方式。
    RedisCmd();
    
    //当使用非集群模式时的构造函数，可以使用此构造函数设置 redis 通信类对象
    RedisCmd(RedisClientPtr client);

    ~RedisCmd();

    //将连接对象与命令操作对象绑定
    SetClient(RedisClientPtr client);

protected:
    const RedisResultPtr Run();
        
private:
    RedisClientPtr client_;
};


}}

#endif
