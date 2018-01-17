#include "publisher.h"
#include <service/event/ctkEventAdmin.h>

Publisher::Publisher(ctkPluginContext *context)
    : pc(context)
{

}

void Publisher::Publish()
{
    ctkServiceReference ref = pc->getServiceReference<ctkEventAdmin>();
    if (ref) {
        //引用事件管理对象
        ctkEventAdmin *eventAdmin = pc->getService<ctkEventAdmin>(ref);

        ctkDictionary props;
        props.insert("name", "zjh");
        props.insert("age", 18);

        //事件
        ctkEvent event("org/commontk/login", props);
        //事件管理对象发送事件
        eventAdmin->sendEvent(event);
    }
}
