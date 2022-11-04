#include "config.h"
#include "mysql/mysql.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //需要修改的数据库信息,登录名,密码,库名
    string user = "root";
    string passwd = "123456";
    string databasename = "yourdb";
    string host = "127.0.0.1";
    //MYSQL连接测试
    MYSQL *mysql;
    mysql = mysql_init(nullptr);
    if (mysql == nullptr) {
	   cout << "ERROR: " << mysql_error(mysql) << endl;
	   return 0;
    }
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), databasename.c_str(), 0, nullptr, 0);
    if (mysql == nullptr) {
	   cout << "ERROR: " << mysql_error(mysql) << endl;
	   return 0;
    }
    cout << "mysql connect success!" << endl;
    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    //日志
    server.log_write();

    //数据库
    server.sql_pool();

    //线程池
    server.thread_pool();

    //触发模式
    server.trig_mode();

    //监听
    server.eventListen();

    //运行
    server.eventLoop();

    return 0;
}
