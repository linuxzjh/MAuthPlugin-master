#include <QCoreApplication>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginContext.h>

#include "publisher.h"
#include "subscriber.h"

//liborg_commontk_eventadmin.dll����·��
const QString c_strSearchPath = "C:/tmp/auth_plugin/makePlugin/Libs";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    //�ڲ��������·�������һ��·��
    ctkPluginFrameworkLauncher::addSearchPath(c_strSearchPath);

    //���ò�����CTK������
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    //��ȡ���������
    ctkPluginContext *pluginContext = ctkPluginFrameworkLauncher::getPluginContext();
    //ע�����,���ڽ����¼�֪ͨ
    Subscriber sub(pluginContext);
    sub.registerService();

    //�����¼�
    Publisher pub(pluginContext);
    pub.Publish();

    //ֹͣ���
    ctkPluginFrameworkLauncher::stop();

    return app.exec();
}
