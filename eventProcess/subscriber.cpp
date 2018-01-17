#include "subscriber.h"
#include <QDebug>
#include <service/event/ctkEventConstants.h>

Subscriber::Subscriber(ctkPluginContext *context)
    : pc(context)
{

}

//将事件处理程序注册为服务
void Subscriber::registerService()
{
    ctkDictionary props;
    props.insert(ctkEventConstants::EVENT_TOPIC, "org/commontk/login");
    pc->registerService<ctkEventHandler>(this, props);
}

void Subscriber::handleEvent(const ctkEvent &event)
{
    QString name = event.getProperty("name").toString();
    int age = event.getProperty("age").toInt();

    qDebug() << QString("name: %1 age:%2").arg(name).arg(age);
}
