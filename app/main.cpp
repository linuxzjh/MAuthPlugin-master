#include <QCoreApplication>
#include <QDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "../../auth_plugin/makePlugin/authpluginservice.h"

const QString c_strPluginPath = "../../auth_plugin/makePlugin/debug/auth_plugin.dll";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ctkPluginFrameworkFactory frameworkFactory;
    QSharedPointer<ctkPluginFramework> frameWork = frameworkFactory.getFramework();
    try {
        //初始化及启动插件框架
        frameWork->init();
        frameWork->start();
        qDebug() << "CTK Plugin FrameWork start...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework" << e.what();
        return -1;
    }

    //获取插件上下文
    ctkPluginContext *pluginContext = frameWork->getPluginContext();
    try {
        //安装插件
       QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(c_strPluginPath));
       //启动插件
       plugin->start(ctkPlugin::START_TRANSIENT);
       qDebug() << "Plugin start...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to install plugin" << e.what();
        return -1;
    }

    //获取服务引用
    ctkServiceReference reference = pluginContext->getServiceReference<AuthPluginService>();
    //获取指定ctkServiceReference 引用的服务对象
    AuthPluginService *authService = qobject_cast<AuthPluginService *>(pluginContext->getService(reference));
    if (authService != Q_NULLPTR) {
        //调用服务,进行认证
        bool isLogin = authService->login("root", "123456");
        if (isLogin) {
            qDebug() << "Login successfully";
        } else {
            qDebug() << "Login failed";
        }
    }
    return app.exec();
}
