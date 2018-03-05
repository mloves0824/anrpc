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

#include <string>
#include <getopt.h>


//static bool test_set(acl::redis& cmd, int n)
//{
//	acl::string key, val;
//
//	for (int i = 0; i < n; i++)
//	{
//		key.format("%s_%d", __keypre.c_str(), i);
//		val.format("val_%s", key.c_str());
//		cmd.clear();
//		if (cmd.set(key, val) == false)
//		{
//			printf("set key: %s error: %s\r\n", key.c_str(),
//				cmd.result_error());
//			return false;
//		}
//		else if (i < 10)
//			printf("set key: %s ok\r\n", key.c_str());
//	}
//
//	return true;
//}

static void usage(const char* procname)
{
	printf("usage: %s -h[help]\r\n"
		"-s redis_addr[127.0.0.1:6379]\r\n"
		"-p password[default: \"\"]\r\n"
		"-n count\r\n"
		"-C connect_timeout[default: 10]\r\n"
		"-T rw_timeout[default: 10]\r\n"
		"-a cmd[set|del|expire|ttl|exists|type|all]\r\n",
		procname);
}

int main(int argc, char* argv[])
{
	int  ch, n = 1, conn_timeout = 10, rw_timeout = 10;
	std::string addr("127.0.0.1:6379"), command, passwd;

	while ((ch = getopt(argc, argv, "hs:n:C:T:a:p:")) > 0)
	{
		switch (ch)
		{
		case 'h':
			usage(argv[0]);
			return 0;
		case 's':
			addr = optarg;
			break;
		case 'n':
			n = atoi(optarg);
			break;
		case 'C':
			conn_timeout = atoi(optarg);
			break;
		case 'T':
			rw_timeout = atoi(optarg);
			break;
		case 'a':
			command = optarg;
			break;
		case 'p':
			passwd = optarg;
			break;
		default:
			break;
		}
	}

//	acl::acl_cpp_init();
//	acl::log::stdout_open(true);
//	acl::redis_client client(addr.c_str(), conn_timeout, rw_timeout);
//	client.set_password(passwd);
//	acl::redis cmd(&client);

	bool ret;

	if (command == "set")
		ret = test_set(cmd, n);
//	else if (command == "get")
//		ret = test_get(cmd, n);
//	else if (command == "del")
//		ret = test_del(cmd, n);
//	else if (command == "expire")
//		ret = test_expire(cmd, n);
//	else if (command == "ttl")
//		ret = test_ttl(cmd, n);
//	else if (command == "exists")
//		ret = test_exists(cmd, n);
//	else if (command == "type")
//		ret = test_type(cmd, n);
//	else if (command == "all")
//	{
//		ret = test_set(cmd, n)
//			&& test_get(cmd, n)
//			&& test_expire(cmd, n)
//			&& test_ttl(cmd, n)
//			&& test_exists(cmd, n)
//			&& test_type(cmd, n)
//			&& test_del(cmd, n);
//	}
	else
	{
		ret = false;
		printf("unknown cmd: %s\r\n", command.c_str());
	}

	if (ret == true)
		printf("test OK!\r\n");
	else
		printf("test failed!\r\n");


	return 0;
}
