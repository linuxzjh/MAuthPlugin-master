#include "authpluginactivator.h"
#include "auth_plugin.h"

void AuthPluginActivator::start(ctkPluginContext* context)
{
    s.reset(new AuthPlugin(context));
}

void AuthPluginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
}
