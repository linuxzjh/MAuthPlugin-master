#include <QCoreApplication>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginContext.h>

#include "publisher.h"
#include "subscriber.h"

//liborg_commontk_eventadmin.dll所在路径
const QString c_strSearchPath = "C:/tmp/auth_plugin/makePlugin/Libs";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    //在插件的搜索路径中添加一条路径
    ctkPluginFrameworkLauncher::addSearchPath(c_strSearchPath);

    //设置并启动CTK插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    //获取插件上下文
    ctkPluginContext *pluginContext = ctkPluginFrameworkLauncher::getPluginContext();
    //注册服务,用于接收事件通知
    Subscriber sub(pluginContext);
    sub.registerService();

    //发布事件
    Publisher pub(pluginContext);
    pub.Publish();

    //停止插件
    ctkPluginFrameworkLauncher::stop();

    return app.exec();
}
