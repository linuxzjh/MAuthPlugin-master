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
        //��ʼ��������������
        frameWork->init();
        frameWork->start();
        qDebug() << "CTK Plugin FrameWork start...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework" << e.what();
        return -1;
    }

    //��ȡ���������
    ctkPluginContext *pluginContext = frameWork->getPluginContext();
    try {
        //��װ���
       QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(c_strPluginPath));
       //�������
       plugin->start(ctkPlugin::START_TRANSIENT);
       qDebug() << "Plugin start...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to install plugin" << e.what();
        return -1;
    }

    //��ȡ��������
    ctkServiceReference reference = pluginContext->getServiceReference<AuthPluginService>();
    //��ȡָ��ctkServiceReference ���õķ������
    AuthPluginService *authService = qobject_cast<AuthPluginService *>(pluginContext->getService(reference));
    if (authService != Q_NULLPTR) {
        //���÷���,������֤
        bool isLogin = authService->login("root", "123456");
        if (isLogin) {
            qDebug() << "Login successfully";
        } else {
            qDebug() << "Login failed";
        }
    }
    return app.exec();
}
